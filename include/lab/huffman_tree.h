#pragma once
#include "./../datastructures/binarytree.h"
#include "./../datastructures/heap.h"
#include "./../myint.h"

namespace huffmantree
{
	using binarytree::BinaryTree;
	using binarytree::BinaryTreeNode;
	using binarytree::LinkedBinaryTree;
	using heap::Heap;
	using std::string;

	template<typename T>
	struct HuffmanNode
	{
		T weight;
		LinkedBinaryTree<T> tree;

		HuffmanNode(T weight_ = T()) : weight(weight_), tree() { tree.insert(weight); }

		~HuffmanNode() = default;

		bool operator<(const HuffmanNode& other) const
		{
			return weight < other.weight;
		}

		bool operator>(const HuffmanNode& other) const
		{
			return weight > other.weight;
		}
	};

	template<typename T>
	LinkedBinaryTree<T> huffmanTree(T weight[], size_t size)
	{
		HuffmanNode<T>* nodes = new HuffmanNode<T>[size];
		for (size_t i = 0; i < size; i++)
		{
			nodes[i].weight = weight[i];
		}
		Heap<HuffmanNode<T>> heap(nodes, size, heap::MIN_HEAP);
		delete[] nodes;

		while (heap.length() > 1)
		{
			HuffmanNode<T> node1 = heap.top();
			heap.pop();
			HuffmanNode<T> node2 = heap.top();
			heap.pop();
			
			node1.weight = node1.weight + node2.weight;
			/node1.tree.merge(node2.tree);

			heap.push();
		}
		return heap.top().tree;
	}

	string decode(string text);

	string encode(string text);

	string encode(LinkedBinaryTree<i32> tree, string text);

}