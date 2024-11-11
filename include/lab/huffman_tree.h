#pragma once
#include "./../datastructures/binarytree.h"
#include "./../myint.h"

namespace huffmantree
{
	using binarytree::BinaryTree;
	using binarytree::BinaryTreeNode;
	using binarytree::LinkedBinaryTree;
	using std::string;

	template<typename T>
	struct HuffmanNode
	{
		T weight;
		LinkedBinaryTree<i32>* tree;

		HuffmanNode() : weight(0), tree(nullptr) {}

		HuffmanNode(T weight_, LinkedBinaryTree<i32>* tree_ = nullptr) : weight(weight_), tree(tree_) {}

		~HuffmanNode() { delete tree; }
	};

	template<typename T>
	LinkedBinaryTree<i32>* huffmanTree(T weight[], size_t n)
	{
		//n个元素，对应初始化n个HuffmanNode
		HuffmanNode<T>* hNode = new HuffmanNode<T>[n + 1];
		LinkedBinaryTree<i32> emptyTree;

		for (size_t i = 1; i <= n; i++)
		{
			hNode[i].weight = weight[i];
			hNode[i].tree = new LinkedBinaryTree<i32>;
			hNode[i].tree->makeTree(i, emptyTree, emptyTree);
		}

		return nullptr;
	}

	string decode(string text);

	string encode(string text);

	string encode(LinkedBinaryTree<i32> tree, string text);

}