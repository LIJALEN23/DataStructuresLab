/**
* @file linkedlist.hpp
* @brief LinkedList类的头文件
*
* @author [lijalen](https://github.com/LIJALEN23)
* @date 2024-10-19
* @version 2.0
*/
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "./../myint.h"
#include "list.h"
#include <iostream>
#include <stdexcept>

/**
* @namespace linkedlist
* @brief 与LinkedList有关的都放在该名称空间中中
*/
namespace linkedlist
{
	/**
	* @brief LinkedList类的头文件声明
	*
	* @details 一个泛型的LinkedList类，包括基本的增删查改
	*/
	template <typename T>
	class LinkedList : public virtual list::List<T>
	{
	public:
		LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}		//默认无参构造函数

		/**
		* @brief LinkedList的析构函数，当链表不为空时，需要释放其开辟的内存
		*/
		virtual ~LinkedList() override { clear(); }

		LinkedList(const LinkedList& other)					//复制构造函数
		{
			head_ = nullptr;
			tail_ = nullptr;
			size_ = 0;

			Node* current = other.head_;
			while (current != nullptr)
			{
				addLast(current->data_);
				current = current->next_;
			}
		}

		LinkedList(LinkedList&& other) noexcept				//移动复制构造函数
		{
			head_ = other.head_;
			tail_ = other.tail_;
			size_ = other.size_;

			other.head_ = nullptr;
			other.tail_ = nullptr;
		}

		LinkedList& operator=(const LinkedList& other)			//赋值运算符
		{
			if (this != &other) { // 避免自我赋值
				clear(); // 清空当前链表

				Node* current = other.head_;
				while (current != nullptr) {
					addLast(current->data_); // 使用 addLast 或 addFirst 方法添加节点
					current = current->next_;
				}
			}
			return *this; // 返回当前对象的引用
		}

		LinkedList& operator=(LinkedList&& other) noexcept		//移动赋值运算符
		{
			if (this != &other) {
				head_ = other.head_;
				tail_ = other.tail_;
				size_ = other.size_;

				other.head_ = nullptr;
				other.tail_ = nullptr;
			}

			return *this;
		}



		void addFirst(const T& data) override				//在列表第一个位置插入新数据
		{
			Node* newNode = new Node(data);

			if (isEmpty())
			{
				tail_ = head_ = newNode;
			}
			else
			{
				newNode->next_ = head_;
				head_->pre_ = newNode;
				head_ = newNode;
			}

			size_++;
		}



		/**
		 * @brief 将链表的头节点删除
		 *
		 * 删除操作之前需要检查链表是否为空
		 * 删除节点后需要注意链表中是否还有节点
		 *
		 * @return T 被删除节点的值
		 */
		T removeFirst() override
		{
			if (isEmpty())
			{
				//链表为空抛出异常
				throw std::runtime_error("[removeFirst()] : The linkedlist is empty!");
			}

			Node* temp = head_;
			T data = temp->data_;

			head_ = head_->next_;
			head_->pre_ = nullptr;
			if (head_ == nullptr)
			{
				tail_ = nullptr;
			}

			delete temp;
			size_--;

			return data;
		}

		void addLast(const T& data) override
		{
			Node* newNode = new Node(data);

			if (isEmpty())
			{
				head_ = tail_ = newNode;
			}
			else
			{
				newNode->pre_ = tail_;
				tail_->next_ = newNode;
				tail_ = newNode;
			}

			size_++;
		}

		T removeLast() override
		{
			if (isEmpty())
			{
				throw std::runtime_error("[removeLast()] : The linkedlist is empty!");
			}

			Node* temp = tail_;	
			T data = temp->data_;

			tail_ = tail_->pre_;
			tail_->next_ = nullptr;
			if (tail_ == nullptr)
			{
				head_ = nullptr;
			}

			delete temp;
			size_--;

			return data;
		}

		T remove(size_t index) override
		{
			Node* current = head_;
			while (index != 0)
			{
				current = current->next_;
				index--;
			}

			(*current->pre_).next_ = current->next_;
			(*current->next_).pre_ = current->pre_;

			T data = current->data_;
			return data;
		}

		T getValue(size_t index) const override
		{
			if (index + 1 > size_)
			{
				;
			}

			Node* current = head_;
			for (size_t i = 0; i < index; i++)
			{
				current = current->next_;
			}

			return current->data_;
		}

		T& getReference(size_t index) override
		{
			if (index + 1 > size_)
			{
				;
			}

			Node* current = head_;
			for (size_t i = 0; i < index; i++)
			{
				current = current->next_;
			}

			return current->data_;
		}

		const T& get(size_t index) const override
		{
			if (index + 1 > size_)
			{
				;
			}

			Node* current = head_;
			for (size_t i = 0; i < index; i++)
			{
				current = current->next_;
			}

			return current->data_;

		}

		const T& operator[](size_t index) const override
		{
			if (index + 1 > size_)
			{
				;
			}

			Node* current = head_;
			for (size_t i = 0; i < index; i++)
			{
				current = current->next_;
			}

			return current->data_;

		}

		void set(size_t index, const T& data) override
		{

		}

		bool isEmpty() const override { return size_ == 0; };	//判断列表是否为空	

		size_t size() const override { return size_; }	//获得列表中元素的数量

		friend std::ostream& operator<<(std::ostream& os, const LinkedList& list)	//重载<<以实现输出列表中元素，需要显式具体化
		{
			LinkedList<u32>::Node* current = list.head_;

			while (current != nullptr)
			{
				os << current->data_ << " <-> ";
				current = current->next_;
			}

			os << "nullptr";

			return os;
		}

	private:
		/**
		* @brief Node，链表的节点
		*/
		struct Node
		{
			T data_;		//节点存储的数据
			Node* pre_;		//指向前一个节点的指针
			Node* next_;	//指向下一个节点的指针

			Node(const T& data, Node* pre = nullptr, Node* next = nullptr) : data_(data), pre_(pre), next_(next) {} //构造函数
		};

		Node* head_;		//链表的头节点
		Node* tail_;		//链表的根节点
		size_t size_;		//链表的数量

		void clear() override
		{
			if (isEmpty())
			{
				return;
			}

			while (head_ != nullptr)
			{
				Node* temp = head_;
				head_ = head_->next_;
				delete temp;
			}

			tail_ = nullptr;
			size_ = 0;
		}

	};

}

#endif // !LINKEDLIST_HPP