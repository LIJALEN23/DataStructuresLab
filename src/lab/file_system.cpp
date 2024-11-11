/**
* @file file_system.cpp
* @brief FileTree类、FileSystem类的实现
*
* @author [lijalen](https://github.com/LIJALEN23)
* @date 2024-11-03
* @version 1.0
*/
#include "./../../include/lab/file_system.h"

/**
* @namespace file_system
* @brief lab03实现一个模拟linux操作文件交互相关的类、方法、函数...
*/
namespace file_system
{
	/**
	* @brief FileTree的默认构造函数
	*/
	FileTree::FileTree()
	{
		root = new FileTreeNode();

		//初始化根目录
		root->files.addLast("/");

		root->children.addLast(new FileTreeNode());
	}

	/**
	* @brief FileTree构造函数，通过给定的文本构造
	*
	* @param text 给定的文本
	*/
	FileTree::FileTree(const string& text)
	{
		root = new FileTreeNode();
		root->files.addLast("/");
		root->children.addLast(new FileTreeNode());

		ArrayList<string> filesOrFolders;
		filesOrFolders = splitText(text, filesOrFolders);
		for (size_t i = 0; i < filesOrFolders.size(); i++)
		{
			add(filesOrFolders.get(i));
		}
	}

	/**
	* @brief FileTree的复制构造函数
	*
	* @param other 需要复制的FileTree实例
	*/
	FileTree::FileTree(const FileTree& other)
	{
		root = new FileTreeNode();
		root->files = other.root->files;
		root->children = other.root->children;
	}

	/**
	* @brief
	*
	* @details
	*
	* @param
	*/
	void FileTree::add(const string& absolutePath)
	{
		//先将绝对路径字符串拆分成字符串数组
		ArrayList<string> components = splitPath(absolutePath);

		//通过拆分的字符串对节点建立新文件或文件夹
		addChild(components, root->children.get(0));
	}

	/**
	* @brief
	*
	* @details
	*
	* @param
	*/
	void FileTree::remove(const string& absolutePath)
	{
		//先将绝对路径字符串拆分成字符串数组
		ArrayList<string> components = splitPath(absolutePath);

		//通过拆分的字符串对节点建立新文件或文件夹
		remove(components, root->children.get(0));

	}

	/**
	* @brief
	*
	* @details
	*
	* @param
	*
	* @return
	*/
	ArrayList<string> FileTree::find(const string& fileOrFolder)
	{
		string prefix = "/";
		ArrayList<string> result;
		result = find(result, root->children.get(0), fileOrFolder, prefix);
		return result;
	}

	void (*FileTree::visit) (FileTreeNode*) = nullptr;

	/**
	* @brief
	*
	* @details
	*
	* @param
	*/
	void FileTree::preOrder(FileTreeNode* node)
	{
		if (node == nullptr)
		{
			return;
		}

		visit(node);

		for (size_t i = 0; i < node->children.size(); i++)
		{
			preOrder(node->children.get(i));
		}
	}

	/**
	* @brief
	*
	* @details
	*
	* @param
	*/
	void FileTree::postOrder(FileTreeNode* node)
	{
		if (node == nullptr)
		{
			return;
		}

		for (size_t i = 0; i < node->children.size(); i++)
		{
			postOrder(node->children.get(i));
		}


		visit(node);
	}

	/**
	* @brief
	*
	* @details
	*
	* @param
	*/
	void FileTree::output(FileTreeNode* node)
	{
		for (size_t i = 0; i < node->files.size(); i++)
		{
			cout << node->files.get(i) << "  ";
		}
	}

	void FileTree::printFileTree(FileTreeNode* node, string& prefix)
	{
		//节点为空停止递归
		if (node == nullptr)
		{
			return;
		}

		//依次打印该节点的每个目录
		for (size_t i = 0; i < node->files.size(); i++)
		{
			cout << prefix << (i == node->files.size() - 1 ? "|_____" : "|-----") << node->files.get(i) << endl;
			string tempPrefix = prefix + "|     ";
			printFileTree(node->children.get(i), tempPrefix);
		}
	}

	ArrayList<string>& FileTree::find(ArrayList<string>& filesOrFolders, FileTreeNode* node, const string& fileOrFolder, string& prefix)
	{
		if (node == nullptr)
		{
			return filesOrFolders;
		}

		for (size_t i = 0; i < node->files.size(); i++)
		{
			if (fileOrFolder == node->files.get(i))
			{
				string path = prefix + fileOrFolder;
				filesOrFolders.addLast(path);
			}
			else
			{
				string tempPrefix = (prefix + node->files.get(i) + "/");
				find(filesOrFolders, node->children.get(i), fileOrFolder, tempPrefix);
			}
		}


		return filesOrFolders;
	}

	void FileTree::remove(ArrayList<string>& components, FileTreeNode* node)
	{
		if (components.size() == 0)
		{
			return;
		}

		string fileOrFolder = components.removeFirst();

		for (size_t i = 0; i < node->files.size(); i++)
		{
			if (fileOrFolder == node->files.get(i))
			{
				if (components.size() == 0)
				{
					node->files.remove(i);
					FileTreeNode* removeNode = node->children.remove(i);
					dispose(removeNode);
					return;
				}
				else
				{
					remove(components, node->children.get(i));
				}
			}
		}

		size_t childrenSize = node->files.size();
		if (childrenSize == 0)
		{
			return;
		}
		remove(components, node->children.get(childrenSize - 1));
	}

	void FileTree::addChild(ArrayList<string>& components, FileTreeNode* node)
	{
		if (components.size() == 0)
		{
			return;
		}

		string fileOrFolder = components.removeFirst();

		for (size_t i = 0; i < node->files.size(); i++)
		{
			if (fileOrFolder == node->files.get(i))
			{
				addChild(components, node->children.get(i));
				return;
			}
		}

		node->files.addLast(fileOrFolder);
		node->children.addLast(new FileTreeNode());
		addChild(components, node->children.get(node->files.size() - 1));
	}

	ArrayList<string> FileTree::splitPath(const string& path)
	{
		ArrayList<string> components;

		size_t start = 1;
		size_t end = 1;
		for (size_t i = 1; i < path.length(); i++)
		{
			if (path.at(i) == '/')
			{
				end = i - 1;
				components.addLast(path.substr(start, end - start + 1));
				start = end + 2;
			}
		}

		//上面的for循环不能识别最后一个/后是否还有文件，所以需要再检查是否含有文件
		if (start < path.length())
		{
			components.addLast(path.substr(start, path.length() - start));
		}

		return components;
	}

	ArrayList<string>& FileTree::splitText(const string& text, ArrayList<string>& filesOrFolders)
	{
		istringstream iss(text);
		string line;
		ArrayList<string> path;

		while (getline(iss, line))
		{
			u32 indent = 0;
			while (line[indent] == '\t')
			{
				++indent;
			}

			string content = line.substr(indent);

			while (path.size() > indent)
			{
				path.removeLast();
			}
			path.addLast(content);

			string absolutePath = "/";
			for (size_t i = 0; i < path.size(); i++)
			{
				absolutePath += path.get(i);
			}

			filesOrFolders.addLast(absolutePath);
		}

		filesOrFolders.removeFirst();
		return filesOrFolders;
	}



	void FileSystem::operateSystem(const string& operating)
	{
		ArrayList<string> components = parseInput(operating);

		string instrucntion = components.removeFirst();
		if (instrucntion == "show")
		{
			show();
		}
		else if (instrucntion == "touch")
		{
			if (components.isEmpty())
			{
				cout << "touch: missing operand" << endl;
			}
			else
			{
				string fileOrFolder = components.removeFirst();
				add(fileOrFolder);
			}
		}
		else if (instrucntion == "rm")
		{
			if (components.isEmpty())
			{
				cout << "rm: missing operand" << endl;
			}
			else
			{
				string fileOrFolder = components.removeFirst();
				remove(fileOrFolder);
			}
		}
		else if (instrucntion == "find")
		{
			if (components.isEmpty())
			{
				cout << "find: missing operand" << endl;
			}
			else
			{
				string fileOrFolder = components.removeFirst();
				find(fileOrFolder);
			}
		}
		else
		{
			cout << "Command not found!" << endl;
		}
	}

	ArrayList<string> FileSystem::parseInput(const string& input)
	{
		ArrayList<string> components;

		string component;
		for (size_t i = 0; i < input.size(); i++)
		{
			if (input.at(i) != ' ')
			{
				component += input.at(i);
			}
			else
			{
				components.addLast(component);
				component.clear();
			}

			if (i == input.size() - 1)
			{
				components.addLast(component);
			}
		}
		return components;
	}

	void FileSystem::add(const string& fileOrFolder, FileTree& tree)
	{
		tree.add(fileOrFolder);
	}

	void FileSystem::remove(const string& fileOrFolder, FileTree& tree)
	{
		tree.remove(fileOrFolder);
	}

	void FileSystem::find(const string& fileOrFolder, FileTree& tree)
	{
		ArrayList<string> filesOrFolders;
		filesOrFolders = tree.find(fileOrFolder);

		if (filesOrFolders.size() == 0)
		{
			cout << "No such files or folders!" << endl;
		}

		for (size_t i = 0; i < filesOrFolders.size(); i++)
		{
			cout << filesOrFolders.get(i) << endl;
		}
		cout << endl;
	}

	void FileSystem::show(FileTree& tree)
	{
		tree.printFileTree();
		cout << endl;
	}
}