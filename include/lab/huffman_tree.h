#pragma once
#include "./../datastructures/binarytree.h"
#include "./../datastructures/linkedlist.h"
#include "./../myint.h"

namespace huffmantree
{
	using linkedlist::LinkedList;
	using binarytree::BinaryTree;
	using binarytree::BinaryTreeNode;
	using binarytree::LinkedBinaryTree;
	using std::string;

	template<typename T>
	struct HuffmanNode
	{
		T weight;
		LinkedBinaryTree<T> tree;

		HuffmanNode(T weight_ = T()) : weight(weight_), tree() { tree.insert(weight); }

		~HuffmanNode() = default;
	};

	template<typename T>
	LinkedBinaryTree<T>* huffmanTree(T weight[], size_t size)
	{
		HuffmanNode<T>* nodes = new HuffmanNode<T>[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			nodes[i].weight = weight[i];
		}

		//minHeap<HuffmanNode<T>> heap;


		return nullptr;
	}

	string decode(string text);

	string encode(string text);

	string encode(LinkedBinaryTree<i32> tree, string text);

}