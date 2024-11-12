#include <iostream>
#include "./../test/test_arraylist.h"
#include "./../test/test_linkedlist.h"
#include "./../test/test_linkedbinarytree.h"
#include "./../test/test_lab03.h"

int main() {

	std::cout << "Hello, lijalen!" << std::endl;
	std::cout << "Enjoy your time!\n\n\n\n\n";

	//test_arraylist::testBasic();
	//test_arraylist::testCopyConstructor1();
	//test_arraylist::testCopyConstructor2();
	//test_arraylist::testConstructor();
	//test_linkedlist::testBasic();
	test_binarytree::testBasic();
	//test_binarytree::debugLinkedBinaryTree();
	//test_lab03::testFileTreeConstructors();
	//test_lab03::testFileTreeCRUD();
	//test_lab03::debugFileSystem();
	//test_lab03::fileSystemMain();
	//test_lab03::debugHuffmanTree();

	return 0;
}