/**
* @file test_lab03.cpp
* @brief 对应头文件test_lab03的函数实现
*
* @author [lijalen](https://github.com/LIJALEN23)
* @date 2024-11-03
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

	void testFileTreeConstructors()
	{
		FileTree tree1;
		tree1.printFileTree();
		cout << endl;

		FileTree tree2("/\nlib/\n\tpython3/\n\thello.txt\n\telse/\nhome/\n\tlijalen/\n\t\tCode/\n\t\t\tCpp/\n\t\t\t\thelloworld.cpp\n\t\t\tJava/\n\t\t\t\thahaha.java\n\t\t\tPython/\n\t\tDesktop/\n\t\tsundries/\nbin/\n\tapt/\n\thahaha.txt");
		tree2.printFileTree();
		cout << endl;

	}

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

	void debugFileSystem()
	{
		FileSystem system("/\nlib/\n\tpython3/\n\thello.txt\n\telse/\nhome/\n\tlijalen/\n\t\tCode/\n\t\t\tCpp/\n\t\t\t\thelloworld.cpp\n\t\t\tJava/\n\t\t\t\thahaha.java\n\t\t\tPython/\n\t\tDesktop/\n\t\tsundries/\nbin/\n\tapt/\n\thahaha.txt");

		system.show();
		string operation = "rm /bin";
		system.operateSystem(operation);
		system.show();

	}
	void huffmanTreeMain()
	{
	}
	void debugHuffmanTree()
	{
		i32 arr[] = { 1, 2, 3, 4 };

		huffmantree::LinkedBinaryTree<i32>* tree = huffmantree::huffmanTree(arr, 5);
	}
}