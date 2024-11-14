/**
* @file heap.h
* @brief 实现了一个堆
* 
* @author [lijalen](https://github.com/LIJALEN23)
* @date 2024-11-13
* @version 1.0
*/
#pragma once
#include "./../myint.h"
#include <iostream>

/**
* @namespace heap
* @brief 与堆相关的操作和数据结构定义
*/
namespace heap
{
	//定义MIN_HEAP和MAX_HEAP
	const static bool MIN_HEAP = false;
	const static bool MAX_HEAP = true;

	/**
	* @brief Heap类
	*
	* @details 一个泛型的Heap类
	*/
	template<typename T>
	class Heap
	{
	public:

		/**
		* @brief 构造函数
		*
		* @param arr 堆化的数组
		* @param length 数组的长度
		* @param type 堆的类型，默认为MAX_HEAP
		*/
		Heap(T* arr, size_t length, bool type = MAX_HEAP)
		{	
			capacity = length + 1;
			comparator = type == MAX_HEAP ? &maxComparator : &minComparator;
			initHeap(arr, length);
		}

		/**
		* @brief 析构函数
		*
		*/
		~Heap() { delete[] heap; }

		/**
		* @brief 判断堆是否为空
		*
		* @return true 堆为空
		* @return false 堆不为空
		*/
		bool empty() const { return size == 0; }

		/**
		* @brief 获取堆的长度
		*
		* @return size_t 堆的长度
		*
		*/
		size_t length() const { return size; }

		/**
		* @brief 返回堆顶元素
		*
		* @return const T& 堆顶元素
		*/
		const T& top()
		{
			if (size == 0)
			{
				throw std::out_of_range("Out of range");
			}

			return heap[1];
		}

		/**
		* @brief 弹出堆顶元素
		*
		*/
		void pop()
		{
			if (size == 0)
			{
				throw std::out_of_range("Out of range");
			}

			heap[1].~T();

			T lastElem = heap[size--];

			size_t currentNode = 1;
			size_t child = 2;
			while (child <= size)
			{
				//寻找左右孩子中优先级较大的那个
				if (child < size && comparator(heap[child], heap[child + 1]) < 0)
				{
					child++;
				}

				//判断是否要交换
				if (comparator(lastElem, heap[child]) > 0)
				{
					break;
				}

				heap[currentNode] = heap[child];
				currentNode = child;
				child *= 2;
			}

			heap[currentNode] = lastElem;
		}

		/**
		* @brief 向堆中插入元素
		*
		* @param data 要插入的元素
		*/
		void push(const T& data)
		{
			if (size == capacity)
			{
				resize(capacity * 2 + 1);
			}
			
			//为新元素寻找位置
			size_t currentNode = size + 1;
			while (currentNode != 1 && comparator(heap[currentNode / 2], data) < 0)
			{
				heap[currentNode] = heap[currentNode / 2];
				currentNode /= 2;
			}

			heap[currentNode] = data;
			size++;
		}

	private:
		T* heap;		//堆数组
		size_t size;		//堆中元素的个数
		size_t capacity;	//堆数组的容量

		//比较函数
		i32 (*comparator) (const T& elem1, const T& elem2);

		/**
		* @brief 比较函数
		*
		* @param elem1 元素1
		* @param elem2 元素2
		* @return i32 返回值
		*
		* @details 如果elem1小于elem2，返回-1；elem1大于elem2，返回1；elem1等于elem2，返回0。
		*/
		static i32 minComparator(const T& elem1, const T& elem2)
		{
			if (elem1 > elem2)
			{
				return -1;
			}
			else if (elem1 < elem2)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}

		/**
		* @brief 比较函数
		*
		* @param elem1 元素1
		* @param elem2 元素2
		* @return i32 返回值
		*
		* @details 如果elem1小于elem2，返回1；elem1大于elem2，返回-1；elem1等于elem2，返回0。
		*/
		static i32 maxComparator(const T& elem1, const T& elem2)
		{
			return -minComparator(elem1, elem2);
		}

		/**
		* @brief 初始化堆
		*
		* @param arr 堆化的数组
		* @param length 数组的长度
		*/
		void initHeap(T* arr, size_t length)
		{
			heap = new T[capacity];
			for (size_t i = 0; i < length; i++)
			{
				heap[i + 1] = arr[i];
			}
			size = length;

			//堆化，从数组的最后一个非叶子节点开始，向前遍历到根节点。对完全二叉树来说，最后一个非叶子节点是size / 2
			for (size_t root = size / 2; root >= 1; root--)
			{
				T rootElem = heap[root];

				//左孩子
				size_t child = 2 * root;
				while (child <= size)
				{
					//heap[child]是否是兄弟中优先级较大者
					if (child < size && comparator(heap[child], heap[child + 1]) < 0)
					{
						child++;
					}

					//判断rootElem和heap[child]的优先级
					if (comparator(rootElem, heap[child]) >= 0)
					{
						break;
					}

					//把孩子向上移
					heap[child / 2] = heap[child];
					//移动到下一层
					child *= 2;
				}

				heap[child / 2] = rootElem;
			}
		}

		/**
		* @brief 扩容
		*
		* @param newCapacity 新的容量
		*/
		void resize(size_t newCapacity)
		{
			T* newHeap = new T[newCapacity];
			for (size_t i = 0; i < size; i++)
			{
				newHeap[i] = heap[i];
			}

			delete[] heap;

			heap = newHeap;
			capacity = newCapacity - 1;
		}
	};

	/**
	* @brief 默认的比较函数
	*
	*/
	template<typename T>
	i32 (Heap<T>::* comparator) (const T& elem1, const T& elem2) = nullptr;
}
