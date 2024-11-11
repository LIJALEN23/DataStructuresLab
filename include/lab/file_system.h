/**
* @file file_system.hpp
* @brief FileTree类、FileTreeNode结构、FileSystem类的头文件
*
* @author [lijalen](https://github.com/LIJALEN23)
* @date 2024-11-03
* @version 1.0
*/
#pragma once
#include <iostream>
#include <sstream>
#include "./../datastructures/arraylist.h"

/**
* @namespace file_system
* @brief lab03实现一个模拟linux操作文件交互相关的类、方法、函数...
*/
namespace file_system
{
	using arraylist::ArrayList;
	using std::string;
	using std::cout;
	using std::endl;
	using std::istringstream;
	using std::getline;

	/**
	* @brief 文件树的节点
	*
	*/
	struct FileTreeNode
	{
		ArrayList<string> files;			//此节点的文件和文件夹
		ArrayList<FileTreeNode*> children;	//此节点的孩子节点

		FileTreeNode() : files(), children() {}		//默认构造函数
	};

	/**
	* @brief FileTree类的头文件声明
	*
	* @details 实现FileTree的增删查改等操作
	*/
	class FileTree
	{
	public:
		FileTree();			//默认构造函数

		FileTree(const string& text);			//通过一段文本直接构造一个文件树

		FileTree(const FileTree& other);		//复制构造函数

		~FileTree()								//析构函数
		{
			clear();
		}

		void add(const string& absolutePath);			//通过绝对路径加一个文件或者文件夹

		void remove(const string& absolutePath);		//通过绝对路径删除一个文件或者文件夹

		ArrayList<string> find(const string& fileOrFolder);				//通过一个文件名查找其绝对路径

		void preOrder(void (*theVisit) (FileTreeNode*)) { visit = theVisit; preOrder(root); }		//先序遍历

		void postOrder(void (*theVisit) (FileTreeNode*)) { visit = theVisit; postOrder(root); }		//后序遍历

		void preOrderOutput() { preOrder(output); }			//先序遍历输出文本

		void postOrderOutput() { postOrder(output); }		//后续遍历输出文本

		void printFileTree() { string prefix = ""; cout << "/" << endl; printFileTree(root->children.get(0), prefix); }	//打印一个字符树

		void clear() { postOrder(dispose); root = nullptr; }	//删除文件树

	private:
		FileTreeNode* root;		//文件树根节点

		static void (*visit) (FileTreeNode*);		//访问器	

		static void preOrder(FileTreeNode* node);		//先序遍历辅助方法

		static void postOrder(FileTreeNode* node);		//后序遍历辅助方法

		static void output(FileTreeNode* node);			//输出文本

		static void printFileTree(FileTreeNode* node, string& prefix);	//printFileTree的辅助方法

		static void dispose(FileTreeNode* node) { delete node; }		//删除该节点

		static ArrayList<string>& find(ArrayList<string>& filesOrFolders, FileTreeNode* node, const string& fileOrFolder, string& prefix);	//find辅助方法

		static void remove(ArrayList<string>& components, FileTreeNode* node);		//remove辅助方法

		static void addChild(ArrayList<string>& componefnts, FileTreeNode* node);	//给这个节点添加新文件或者文件夹

		static ArrayList<string> splitPath(const string& path);				//将一个绝对路径字符串分解

		static ArrayList<string>& splitText(const string& text, ArrayList<string>& filesOrFolders);	//将一个文本拆成一个一个绝对路径的文件或文件夹
	};

	/**
	* @brief FileSystem的头文件声明
	*
	* @details 该类通过使用FileTree类模拟linux的文件交互逻辑
	*/
	class FileSystem
	{
	public:
		FileSystem() : fileTree() {}			//默认构造函数

		FileSystem(const string& text) : fileTree(text) {}	//通过一段文本构造一个文件系统

		~FileSystem() = default;			//析构函数

		void operateSystem(const string& operating);		//传操作指令进来，对文件系统进行操作

		void add(const string& fileOrFolder) { add(fileOrFolder, fileTree); }		//通过绝对路径加一个文件或文件夹

		void remove(const string& fileOrFolder) { remove(fileOrFolder, fileTree); }		//通过绝对路径删除一个文件或者文件夹

		void find(const string& fileOrFolder) { find(fileOrFolder, fileTree); }

		void show() { show(fileTree); }			//答应文件树
	private:
		FileTree fileTree;		//文件系统对应的文件树

		static ArrayList<string> parseInput(const string& input);	//处理输入文本的函数

		static void add(const string& fileOrFolder, FileTree& tree);	//add辅助函数

		static void remove(const string& fileOrFolder, FileTree& tree);	//remove辅助函数

		static void find(const string& fileOrFolder, FileTree& tree); //find辅助函数

		static void show(FileTree& tree);								//show辅助函数
	};
}