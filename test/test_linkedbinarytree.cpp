#include "test_linkedbinarytree.h"


namespace test_binarytree
{
	void debugLinkedBinaryTree()
	{
		auto tree1 = binarytree::LinkedBinaryTree<std::string>();

		tree1.insert("lijalen");
		tree1.insert("hello");
		tree1.insert("hhahhaha");
		tree1.preOrderOutput();

		auto tree2 = binarytree::LinkedBinaryTree<std::string>();
		tree2.insert("asdfasf");
		tree2.insert("anklj");
		tree2.insert("werqwr");

		tree1.merge(tree2);
		tree1.preOrderOutput();

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