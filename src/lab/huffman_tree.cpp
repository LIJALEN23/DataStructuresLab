/**
* @file huffman_tree.cpp
* @details 实现huffman树编码解码
* 
* @author [lijalen](https://github.com/LIJALEN23)
* @date 2024-11-14
* @version 1.0
*/
#include "./../../include/lab/huffman_tree.h"

/**
* @namespace huffmantree
* @brief Huffman树编码解码实现
* 
*/
namespace huffmantree
{
	string*& mapArr(string*& arr, size_t length, BinaryTreeNode<i32>*& node, string& prefix)
	{
		//叶节点才记录
		if (node->left == nullptr && node->right == nullptr)
		{
			arr[node->elem] = prefix;
			return arr;
		}
		//左子树为空，右子树不为空
		else if (node->left == nullptr && node->right != nullptr)
		{
			string rightPrefix = prefix + '1';
			mapArr(arr, length, node->right, rightPrefix);
		}
		//左子树不为空，右子树为空
		else if(node->left != nullptr && node->right == nullptr)
		{
			string leftPrefix = prefix + '0';
			mapArr(arr, length, node->left, leftPrefix);
		}

		string leftPrefix = prefix + '0';
		string rightPrefix = prefix + '1';
		//左右子树都存在
		mapArr(arr, length, node->left, leftPrefix);
		mapArr(arr, length, node->right, rightPrefix);
	}

	string decode(LinkedBinaryTree<i32>& tree, const string& text)
	{
		//计算字符的偏移量
		const static i32 OFFSET = 64;

		string result;

		size_t index = 0;

		//遍历所有字符
		while (index < text.size())
		{
			BinaryTreeNode<i32>* node = tree.getRoot();
			while (node != nullptr)
			{
				//叶节点
				if (node->left == nullptr && node->right == nullptr)
				{
					char ch = node->elem == 0 ? ' ' : (char)(node->elem + OFFSET);
					result += ch;
					break;
				}

				//0左，1右
				if (text.at(index) == '0')
				{
					node = node->left;
					index++;
				}
				else if (text.at(index) == '1')
				{
					node = node->right;
					index++;
				}
			}
			
		}
		
		return result;
	}

	string encode(string*& map, size_t length,const string& text)
	{
		//计算字符的偏移量
		const static i32 OFFSET = 64;

		string result;

		for (char ch : text)
		{
			//空格
			if (ch == ' ')
			{
				result += map[0];
			}
			//字符
			else
			{
				size_t index = (i32)ch - OFFSET;
				result += map[index];
			}
		}

		return result;
	}

}
