﻿#include "test_linkedbinarytree.h"


namespace test_binarytree
{
	void debugLinkedBinaryTree()
	{


	}

	void testBasic()
	{
		auto tree1 = binarytree::LinkedBinaryTree<std::string>();

		tree1.insert("lijalen");
		tree1.insert("hello");
		tree1.insert("hhahhaha");
		tree1.preOrderOutput();

		tree1.remove("lijalen");
		tree1.remove("hello");
		tree1.remove("hhahhaha");
		tree1.preOrderOutput();
	}
	void testCopyConstructor()
	{
		auto tree1 = binarytree::LinkedBinaryTree<std::string>();
		tree1.insert("lijalen");
		tree1.insert("hello");
		tree1.insert("hhahhaha");
		tree1.preOrderOutput();

		auto tree2 = tree1;
		tree2.preOrderOutput();
	}
}