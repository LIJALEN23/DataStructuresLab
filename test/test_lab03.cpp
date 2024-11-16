/**
* @file test_lab03.cpp
* @brief 对应头文件test_lab03的函数实现
*
* @author [lijalen](https://github.com/LIJALEN23)
* @date 2024-11-14
* @version 1.0
*/
#include "test_lab03.h"

/**
* @namespace test_lab03
* @brief lab03的测试相关函数
*/
namespace test_lab03
{
	using std::string;
	using std::cout;
	using std::cin;
	using std::endl;
	using file_system::FileSystem;
	using file_system::FileTree;
	using std::getline;


	/**
	* @brief 文件系统Main函数
	* @details 测试文件系统，输入指令，执行指令
	*/
	void fileSystemMain()
	{
		string input;
		FileSystem system("/\nlib/\n\tpython3/\n\thello.txt\n\telse/\nhome/\n\tlijalen/\n\t\tCode/\n\t\t\tCpp/\n\t\t\t\thelloworld.cpp\n\t\t\tJava/\n\t\t\t\thahaha.java\n\t\t\tPython/\n\t\tDesktop/\n\t\tsundries/\nbin/\n\tapt/\n\thahaha.txt");

		while (true)
		{
			cout << "Please enter a instrucntion : ";
			getline(cin, input);

			if (input == "exit")
			{
				cout << "Bye~" << endl;
				return;
			}

			system.operateSystem(input);
			input.clear();
		}
	}

	/**
	* @brief 文件树Mainhd
	* @details 测试文件树，添加、删除、查找
	*/
	void debugFileTree()
	{
		string str1 = "/bin/python3/";
		string str2 = "/bin/hello.txt";
		string str3 = "/bin/else/";
		string str4 = "/home/lijalen/Desktop/hello.txt";
		string str5 = "/home/lijalen/Code/Cpp/";
		string str6 = "/home/lijalen/Code/Java/";
		string str7 = "/home/lijalen/Code/Cpp/hello.cpp";


		FileTree tree1;
		tree1.add(str1);
		tree1.add(str2);
		tree1.add(str3);
		tree1.add(str4);
		tree1.add(str5);
		tree1.add(str6);
		tree1.add(str7);

		tree1.printFileTree();
		cout << endl;

		//tree1.remove(str1);
		//tree1.remove(str2);
		//tree1.remove(str3);
		//tree1.remove(str4);
		//tree1.remove(str5);
		//tree1.remove(str6);
		//tree1.printFileTree();
		//cout << endl;

		//tree1.remove(str7);
		//tree1.printFileTree();
		//cout << endl;

		arraylist::ArrayList<string> result = tree1.find("hello.txt");
		for (size_t i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}

		FileTree tree("/\nlib/\n\tpython3/\n\thello.txt\n\telse/\nhome/\n\tlijalen/\n\t\tCode/\n\t\t\tCpp/\n\t\t\t\thelloworld.cpp\n\t\t\tJava/\n\t\t\t\thahaha.java\n\t\t\tPython/\n\t\tDesktop/\n\t\tsundries/\nbin/\n\tapt/\n\thahaha.txt");
		tree.printFileTree();
	}

	/**
	* @brief 测试文件树构造函数
	*/
	void testFileTreeConstructors()
	{
		FileTree tree1;
		tree1.printFileTree();
		cout << endl;

		FileTree tree2("/\nlib/\n\tpython3/\n\thello.txt\n\telse/\nhome/\n\tlijalen/\n\t\tCode/\n\t\t\tCpp/\n\t\t\t\thelloworld.cpp\n\t\t\tJava/\n\t\t\t\thahaha.java\n\t\t\tPython/\n\t\tDesktop/\n\t\tsundries/\nbin/\n\tapt/\n\thahaha.txt");
		tree2.printFileTree();
		cout << endl;

	}

	/**
	* @brief 测试文件树CRUD
	*/
	void testFileTreeCRUD()
	{
		FileTree tree1;
		string str1 = "/bin/python3/";
		string str2 = "/bin/hello.txt";
		string str3 = "/bin/else/";
		string str4 = "/home/lijalen/Desktop/hello.txt";
		string str5 = "/home/lijalen/Code/Cpp/";
		string str6 = "/home/lijalen/Code/Java/";
		string str7 = "/home/lijalen/Code/Cpp/hello.cpp";

		//测试add()
		tree1.add(str1);
		tree1.add(str2);
		tree1.add(str3);
		tree1.add(str4);
		tree1.add(str5);
		tree1.add(str6);
		tree1.add(str7);
		tree1.printFileTree();
		cout << endl;

		//测试find()
		arraylist::ArrayList<string> result = tree1.find("hello.txt");
		for (size_t i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}
		cout << endl;


		//测试remove()
		tree1.remove(str1);
		tree1.remove(str2);
		tree1.remove(str3);
		tree1.remove(str4);
		tree1.remove(str5);
		tree1.remove(str6);
		tree1.printFileTree();
		cout << endl;

		tree1.remove(str7);
		tree1.printFileTree();
		cout << endl;
	}

	/**
	* @brief 测试文件系统
	*/
	void debugFileSystem()
	{
		FileSystem system("/\nlib/\n\tpython3/\n\thello.txt\n\telse/\nhome/\n\tlijalen/\n\t\tCode/\n\t\t\tCpp/\n\t\t\t\thelloworld.cpp\n\t\t\tJava/\n\t\t\t\thahaha.java\n\t\t\tPython/\n\t\tDesktop/\n\t\tsundries/\nbin/\n\tapt/\n\thahaha.txt");

		system.show();
		string operation = "rm /bin";
		system.operateSystem(operation);
		system.show();

	}

	/**
	* @brief 哈夫曼树Main函数
	* @details 测试哈夫曼树，编码、解码
	*/
	void huffmanTreeMain()
	{
		//编码数组的长度
		const static size_t LENGTH = 27;
		//码表偏移量
		const static size_t OFFSET = 64;

		//权重数组
		i32 weight[LENGTH] = { 186, 64, 13, 22, 32, 103, 21, 15, 47, 57, 1, 5, 32, 20, 57, 63, 15, 1, 48, 51, 80, 23, 8, 18, 1, 16, 1 };
		//生成哈夫曼树
		binarytree::LinkedBinaryTree<i32> huffmantree = huffmantree::huffmanTree(weight, LENGTH);
		
		//生成编码表
		std::string* map = new string[LENGTH];
		std::string prefix = "";
		huffmantree::mapArr(map, huffmantree.getRoot(), prefix);
		
		//输出编码表
		std::cout << "空格 : " << map[0] << std::endl;
		for (size_t i = 1; i < LENGTH; i++)
		{
			std::cout << (char)(i + OFFSET) << " : " << map[i] << std::endl;
		}

		//编码
		std::string originalCode = "THIS PROGRAM IS MY FAVORITE";
		std::string afterEncode = huffmantree::encode(map, originalCode);
		std::cout << std::endl << "AfterEncode : " << afterEncode << std::endl;

		//解码	
		std::string afterDecode = huffmantree::decode(huffmantree, afterEncode);
		std::cout << "AfterDecode : " << afterDecode << std::endl;

	}

	/**
	* @brief 测试哈夫曼树
	*/
	void debugHuffmanTree()
	{
		i32 weight[] = { 186, 64, 13, 22, 32, 103, 21, 15, 47, 57, 1, 5, 32, 20, 57, 63, 15, 1, 48, 51, 80, 23, 8, 18, 1, 16, 1 };
		size_t length = sizeof(weight) / sizeof(weight[0]);

		//index mapping character
		std::string str = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

		binarytree::LinkedBinaryTree<i32> tree = huffmantree::huffmanTree(weight, length);
		tree.preOrderOutput();
	}
}