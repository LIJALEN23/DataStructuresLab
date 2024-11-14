/**
* @file test_lab03.h
* @brief 测试FileSystem类和FileTree类，和lab03操作文件系统的main函数声明
*
* @author [lijalen](https://github.com/LIJALEN23)
* @date 2024-11-03
* @version 1.0
*/
#pragma once
#include "./../include/lab/file_system.h"
#include "./../include/lab/huffman_tree.h"

/**
* @namespace test_lab03
* @brief lab03的测试相关函数
*/
namespace test_lab03
{
	void fileSystemMain();		//lab03操作文件系统的main函数

	void debugFileTree();		//用的调试FileTree类的

	void testFileTreeConstructors();		//测试FileTree::Constructor

	void testFileTreeCRUD();				//测试FileTree::CRUD

	void debugFileSystem();					//调试FileSystem类的

	void huffmanTreeMain();		//lab03哈夫曼编码的main函数
	
	void debugHuffmanTree();	//调试HuffmanTree相关函数的
}