/**
* @file huffman_tree.h 
* @brief 哈夫曼编码相关代码
*
* @author [lijalen](https://github.com/LIJALEN23)
* @date 2024-11-14
* @version 1.0
*/
#pragma once
#include "./../datastructures/binarytree.h"
#include "./../datastructures/heap.h"
#include "./../myint.h"

/**
* @namespace huffmantree
* @brief 哈夫曼编码相关代码名称空间
*/
namespace huffmantree
{
	using binarytree::BinaryTree;
	using binarytree::BinaryTreeNode;
	using binarytree::LinkedBinaryTree;
	using heap::Heap;
	using std::string;

	/**
	* @brief 哈夫曼节点
	*/
	template<typename T>
	struct HuffmanNode
	{
		T weight;						// 节点权值
		LinkedBinaryTree<i32> tree;		// 节点对应的哈夫曼树

		/**
		* @brief 构造函数
		* @param weight_ 节点权值
		*/
		HuffmanNode(T weight_ = T()) : weight(weight_), tree() {}

		/**
		* @brief 析构函数
		*/
		~HuffmanNode() = default;

		/**
		* @brief 重载小于运算符
		* @param other 另一个哈夫曼节点
		* @return bool
		*/
		bool operator<(const HuffmanNode& other) const
		{
			return weight < other.weight;
		}

		/**
		* @brief 重载大于运算符
		* @param other 另一个哈夫曼节点
		* @return bool
		*/
		bool operator>(const HuffmanNode& other) const
		{
			return weight > other.weight;
		}
	};

	/**
	* @brief 哈夫曼编码
	* @param weight 权值数组
	* @param size 权值数组大小
	* @return LinkedBinaryTree<i32> 哈夫曼树
	*/
	template<typename T>
	LinkedBinaryTree<i32> huffmanTree(T weight[], size_t size)
	{
		//创建哈夫曼节点
		HuffmanNode<T>* nodes = new HuffmanNode<T>[size];
		//初始化每个哈夫曼节点
		for (size_t i = 0; i < size; i++)
		{
			nodes[i].weight = weight[i];
			nodes[i].tree.insert(i);	//树的节点为对应编码的映射下标
		}
		//创建堆
		Heap<HuffmanNode<T>> heap(nodes, size, heap::MIN_HEAP);
		delete[] nodes;
		
		//循环构建哈夫曼树
		while (heap.length() > 1)
		{
			HuffmanNode<T> node1 = heap.top();
			heap.pop();
			HuffmanNode<T> node2 = heap.top();
			heap.pop();
			
			node1.weight = node1.weight + node2.weight;
			node1.tree.merge(node2.tree);

			heap.push(node1);
		}
		
		LinkedBinaryTree<i32> tree = heap.top().tree;
		heap.pop();

		return tree;
	}

	/**
	* @brief 构建哈夫曼编码表
	* @param arr 哈夫曼编码表
	* @param length 哈夫曼编码表大小
	* @param node 哈夫曼树节点
	* @param prefix 前缀
	* @return string*& 哈夫曼编码表
	*/
	string*& mapArr(string*& arr, size_t length, BinaryTreeNode<i32>*& node, string& prefix);

	/**
	* @brief 哈夫曼编码
	* @param map 哈夫曼编码表
	* @param length 哈夫曼编码表大小
	* @param text 待编码文本
	* @return string 编码结果
	*/
	string encode(string*& map, size_t length,const string& text);

	/**
	* @brief 哈夫曼解码
	* @param tree 哈夫曼树
	* @param text 待解码文本
	* @return string 解码结果
	*/
	string decode(LinkedBinaryTree<i32>& tree,  const string& text);

}