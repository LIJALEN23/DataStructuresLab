/**
* @file binarytree.h 
* @brief 二叉树相关实现的头文件
* 
* @author [lijalen](https://github.com/LIJALEN23)
* @date
* @version 1.0
*/
#pragma once
#include <iostream>
#include "./../myint.h"

/**
* @namespace binarytree
* @brief 与二叉树相关的代码都放在该名称中间中
*/
namespace binarytree
{
	/**
	* @brief BinaryTree类
	* 
	* @details 一个泛型的二叉树抽象类
	*/
	template<typename T>
	class BinaryTree
	{
	public:
		virtual ~BinaryTree() = default;

		virtual bool isEmpty() const = 0;

		virtual size_t size() const = 0;

		virtual size_t height() const = 0;

		virtual void preOrder(void (*) (T*)) = 0;

		virtual void inOrder(void (*) (T*)) = 0;

		virtual void postOrder(void (*) (T*)) = 0;

		virtual void levelOrder(void (*) (T*)) = 0;

	};

	/**
	* @brief BinaryTreeNode类
	* 
	* @details 一个泛型二叉树节点的类
	*/
	template<typename T>
	struct BinaryTreeNode
	{
		T elem;						//节点元素
		BinaryTreeNode<T>* left;	//左子树
		BinaryTreeNode<T>* right;	//右子树

		/**
		* @brief 无参构造函数
		*/
		BinaryTreeNode() { left = right = nullptr; }

		/**
		* @brief 有参构造函数
		* @param theElem 节点元素
		* @param theLeft 左子树指针
		* @param theRight 右子树指针
		*/
		BinaryTreeNode(const T& theElem, BinaryTreeNode* theLeft = nullptr, BinaryTreeNode* theRight = nullptr) : elem(theElem), left(theLeft), right(theRight) {}

	};

	/**
	* @brief LinkedBinaryTree类
	* 
	* @details 一个泛型的LinkedBinaryTree类，实现了基本的CRUD
	*/
	template<typename T>
	class LinkedBinaryTree : public virtual BinaryTree<BinaryTreeNode<T>>
	{
	public:
		/**
		* @brief 无参构造函数
		*/
		LinkedBinaryTree() : root(nullptr), treeSize(0) {}

		/**
		* @brief LinkedBinaryTree析构函数
		*/
		virtual ~LinkedBinaryTree() { erase(); }

		/**
		* @brief LinedBinaryTree复制构造函数
		*/

		LinkedBinaryTree(const LinkedBinaryTree& other)
		{
			treeSize = other.size();
			root = copyTree(other.root);
		}

		/**
		* @brief LinkedBinaryTree赋值运算符
		*/

		LinkedBinaryTree<T>& operator=(const LinkedBinaryTree& other)
		{
			if (this != &other)
			{
				treeSize = other.treeSize;
				root = copyTree(other.root);
			}

			return *this;
		}

		/**
		* @brief 获取根节点指针
		*/
		BinaryTreeNode<T>*& getRoot() { return root; }

		/**
		* @brief 判断二叉树是否为空
		* @return true or false
		*/
		bool isEmpty() const override { return treeSize == 0; }

		/**
		* @brief 获取二叉树元素个数
		* @return 元素个数
		*/
		size_t size() const override { return treeSize; }

		/**
		* @brief 获取二叉树的高度
		* @return 二叉树的高度
		*/
		size_t height() const override { return height(root); }

		/**
		* @brief 插入元素
		* @param val 要插入的元素
		*/
		void insert(const T& val) { root = insert(root, val); treeSize++; }

		/**
		* @brief 删除元素
		* @param val 要删除的元素
		*/
		void remove(const T& val) { root = remove(root, val); treeSize--; }

		/**
		* @brief 查找元素
		* @param val 要查找的元素
		* @return 查找到的元素
		*/
		BinaryTreeNode<T>* find(const T& val) { return find(root, val); }

		/**
		* @brief 查找最小元素
		* @return 最小元素
		*/
		BinaryTreeNode<T>* findMin(const T& val) { return findMin(root); }

		/**
		* @brief 查找最大元素
		* @return 最大元素
		*/
		BinaryTreeNode<T>* findMax(const T& val) { return findMax(root); }

		/**
		* @brief 合并二叉树
		* @param other 要合并的二叉树
		*/
		void merge(const LinkedBinaryTree<T>& other)
		{
			LinkedBinaryTree<T>* newTree = new LinkedBinaryTree(other);
			BinaryTreeNode<T>* newRoot = new BinaryTreeNode<T>(root->elem);
			if (root->elem > newTree->root->elem)
			{
				newRoot->left = newTree->root;
				newRoot->right = root;
			}
			else
			{
				newRoot->left = newTree->root;
				newRoot->right = root;
			}

			root = newRoot;
			treeSize = other.treeSize + treeSize + 1;
		}

		/**
		* @brief 前序遍历
		* @param theVisit 访问函数
		*/
		void preOrder(void (*theVisit) (BinaryTreeNode<T>*)) override { visit = theVisit; preOrder(root); }

		/**
		* @brief 中序遍历
		* @param theVisit 访问函数
		*/
		void inOrder(void (*theVisit) (BinaryTreeNode<T>*)) override { visit = theVisit; inOrder(root); }

		/**
		* @brief 后序遍历
		* @param theVisit 访问函数
		*/
		void postOrder(void (*theVisit) (BinaryTreeNode<T>*)) override { visit = theVisit; postOrder(root); }

		/**
		* @brief 层序遍历
		* @param theVisit 访问函数
		*/
		void levelOrder(void(*theVisit)(BinaryTreeNode<T>*)) override { visit = theVisit; levelOrder(root); }

		/**
		* @brief 前序遍历输出
		*/
		void preOrderOutput() { preOrder(output); std::cout << std::endl; }

		/**
		* @brief 中序遍历输出
		*/
		void inOrderOutput() { inOrder(output); std::cout << std::endl; }

		/*
		* @brief 释放二叉树
		*/
		void erase()
		{
			postOrder(dispose);
			root = nullptr;
			treeSize = 0;
		}

	private:
		BinaryTreeNode<T>* root;						//根节点指针
		size_t treeSize;								//二叉树元素个数
		static void (*visit) (BinaryTreeNode<T>*);		//访问函数指针

		/**
		* @brief 拷贝二叉树
		* @param node 二叉树节点指针
		* @return 二叉树节点指针
		*/
		static size_t height(BinaryTreeNode<T>* node)
		{
			if (node == nullptr)
			{
				return 0;
			}

			size_t leftHeight = height(node->left);
			size_t rightHeight = height(node->right);

			return leftHeight > rightHeight ? ++leftHeight : ++rightHeight;
		}

		BinaryTreeNode<T>* insert(BinaryTreeNode<T>* node, const T& val)
		{
			if (node == nullptr)
			{
				return new BinaryTreeNode<T>(val);
			}

			if (val > node->elem)
			{
				(*node).right = insert(node->right, val);
			}
			else if (val < node->elem)
			{
				(*node).left = insert(node->left, val);
			}

			return node;
		}

		BinaryTreeNode<T>* remove(BinaryTreeNode<T>* node, const T& val)
		{
			//删除这个外部节点，需要注意是否为root
			if (node->elem == val && node != root)
			{
				delete(node);
				return nullptr;
			}
			
			if (val > node->elem)
			{
				node->right = remove(node->right, val);
			}
			else if (val < node->elem)
			{
				node->left = remove(node->left, val);
			}
			else
			{
				if (node->left != nullptr)
				{
					BinaryTreeNode<T>* precursor = findMax(node->left);
					node->elem = precursor->elem;
					node->left = remove(node->left, node->elem);
				}
				else
				{
					if (node->right == nullptr)
					{
						delete(node);
						return nullptr;
					}

					BinaryTreeNode<T>* successor = findMin(node->right);
					node->elem = successor->elem;
					node->right = remove(node->right, node->elem);
				}
			}

			return node;
		}

		BinaryTreeNode<T>* find(BinaryTreeNode<T>* node, const T& val) const
		{
			if (node == nullptr)
			{
				return nullptr;
			}

			if (val > node->elem)
			{
				return find(node->right, val);
			}
			else if (val < node->elem)
			{
				return find(node->left, val);
			}

			return node;
		}

		BinaryTreeNode<T>* findMax(BinaryTreeNode<T>* node) const
		{
			if (node->right != nullptr)
			{
				node = node->right;
			}

			return node;
		}

		BinaryTreeNode<T>* findMin(BinaryTreeNode<T>* node) const
		{
			if (node->left != nullptr)
			{
				node = node->left;
			}

			return node;
		}

		BinaryTreeNode<T>* copyTree(BinaryTreeNode<T>* node) const
		{
			if (node == nullptr)
			{
				return nullptr;
			}

			BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(node->elem);
			newNode->left = copyTree(node->left);
			newNode->right = copyTree(node->right);

			return newNode;
		}

		static void preOrder(BinaryTreeNode<T>* node)
		{
			if (node != nullptr)
			{
				visit(node);
				preOrder(node->left);
				preOrder(node->right);
			}
		}

		static void inOrder(BinaryTreeNode<T>* node)
		{
			if (node != nullptr)
			{
				inOrder(node->left);
				visit(node);
				inOrder(node->right);
			}
		}

		static void postOrder(BinaryTreeNode<T>* node)
		{
			if (node != nullptr)
			{
				postOrder(node->left);
				postOrder(node->right);
				visit(node);
			}
		}

		static void levelOrder(BinaryTreeNode<T>* node)
		{

		}

		static void output(BinaryTreeNode<T>* node) { std::cout << node->elem << " "; }

		static void dispose(BinaryTreeNode<T>* node) { delete node; }
	};

	/**
	* @brief 函数指针visit初始化为空
	*/
	template<typename T>
	void (*LinkedBinaryTree<T>::visit)(BinaryTreeNode<T>*) = nullptr;
}