#pragma once
#include <iostream>
#include "./../myint.h"

namespace binarytree
{
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

	template<typename T>
	struct BinaryTreeNode
	{
		T elem;
		BinaryTreeNode<T>* left;
		BinaryTreeNode<T>* right;

		BinaryTreeNode() { left = right = nullptr; }

		BinaryTreeNode(const T& theElem, BinaryTreeNode* theLeft = nullptr, BinaryTreeNode* theRight = nullptr) : elem(theElem), left(theLeft), right(theRight) {}

	};

	template<typename T>
	class LinkedBinaryTree : public virtual BinaryTree<BinaryTreeNode<T>>
	{
	public:
		LinkedBinaryTree() : root(nullptr), treeSize(0) {}

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

			}

			return *this;
		};

		bool isEmpty() const override { return treeSize == 0; }

		size_t size() const override { return treeSize; }

		size_t height() const override { return height(root); }

		void insert(const T& val) { root = insert(root, val); treeSize++; }

		T remove(const T& val) { return remove(root, val); treeSize--; }

		BinaryTreeNode<T>* find(const T& val) { return find(root, val); }

		BinaryTreeNode<T>* findMin(const T& val) { return findMin(root); }

		BinaryTreeNode<T>* findMax(const T& val) { return findMax(root); }

		void makeTree(T elem, LinkedBinaryTree tree1, LinkedBinaryTree tree2)
		{
			LinkedBinaryTree<T>* left = nullptr;
			LinkedBinaryTree<T>* right = nullptr;

			if (tree1.root->elem > tree2.root->elem)
			{
				left = new LinkedBinaryTree<T>(tree2);
				right = new LinkedBinaryTree<T>(tree1);
			}
			else
			{
				left = new LinkedBinaryTree<T>(tree1);
				right = new LinkedBinaryTree<T>(tree2);
			}

			BinaryTreeNode<T>* newRoot = new BinaryTreeNode<T>(elem, left->root, right->root);
			erase();
			root = newRoot;
			treeSize = left->treeSize > right->treeSize ? left->treeSize : right->treeSize;
		}

		void preOrder(void (*theVisit) (BinaryTreeNode<T>*)) override { visit = theVisit; preOrder(root); }

		void inOrder(void (*theVisit) (BinaryTreeNode<T>*)) override { visit = theVisit; inOrder(root); }

		void postOrder(void (*theVisit) (BinaryTreeNode<T>*)) override { visit = theVisit; postOrder(root); }

		void levelOrder(void(*)(BinaryTreeNode<T>*)) override
		{

		}

		void preOrderOutput() { preOrder(output); std::cout << std::endl; }

		void inOrderOutput() { inOrder(output); std::cout << std::endl; }

		void erase()
		{
			postOrder(dispose);
			root = nullptr;
			treeSize = 0;
		}

	private:
		BinaryTreeNode<T>* root;
		size_t treeSize;
		static void (*visit) (BinaryTreeNode<T>*);

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

		T remove(BinaryTreeNode<T>* node, const T& val)
		{
			return T();
		}

		BinaryTreeNode<T>* find(BinaryTreeNode<T>* node, const T& val)
		{
			// TODO: insert return statement here
			return nullptr;
		}

		BinaryTreeNode<T>* findMax(BinaryTreeNode<T>* node)
		{
			// TODO: insert return statement here
			return nullptr;
		}

		BinaryTreeNode<T>* findMin(BinaryTreeNode<T>* node)
		{
			// TODO: insert return statement here
			return nullptr;
		}

		inline BinaryTreeNode<T>* copyTree(BinaryTreeNode<T>* node)
		{
			return nullptr;
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

		static void output(BinaryTreeNode<T>* node) { std::cout << node->elem << " "; }

		static void dispose(BinaryTreeNode<T>* node) { delete node; }
	};

	template<typename T>
	void (*LinkedBinaryTree<T>::visit)(BinaryTreeNode<T>*) = nullptr;
}