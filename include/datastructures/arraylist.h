/**
* @file arraylist.h
* @brief ArrayList类的头文件
*
* @author [lijalen](https://github.com/LIJALEN23)
* @date 2024-10-16
* @version 2.0
*/
#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include "./../myint.h"
#include "list.h"
#include <iostream>

/**
* @namespace arraylist
* @brief 与ArrayList有关的都放在该名称空间中中
*/
namespace arraylist
{
	constexpr size_t DEFAULT_CAPACIY = 10;	//默认数组大小

	/**
	* @brief ArrayList类
	*
	* @details 一个泛型的ArrayList类，包括基本的增删查改
	*/
	template<typename T>
	class ArrayList : public virtual list::List<T>
	{
	public:
		ArrayList()	 				 //默认构造函数
		{
			data_ = new T[DEFAULT_CAPACIY];
			capacity_ = DEFAULT_CAPACIY;

			size_ = 0;
		}

		ArrayList(size_t capacity)		 //给定初始空间的构造函数
		{
			if (capacity <= 0)
			{
				throw std::invalid_argument("Capacity must be positive.");
			}

			data_ = new T[capacity];
			capacity_ = capacity;

			size_ = 0;
		}

		/**
		* @brief ArrayList的析构函数，当data_不为空时，需要释放其开辟的内存
		*/
		virtual ~ArrayList() { clear(); }

		ArrayList(const ArrayList& other)						//复制构造函数
		{
			capacity_ = other.capacity_;
			size_ = other.size_;

			data_ = new T[capacity_];

			//将other.data_的每个数据复制到data_中
			for (size_t i = 0; i < capacity_; i++)
			{
				data_[i] = std::move(other.data_[i]);
			}
		}

		ArrayList(ArrayList&& other) noexcept					//移动构造函数
		{
			capacity_ = other.capacity_;
			size_ = other.size_;
			data_ = other.data_;

			//将原来的data设置成nullptr
			other.data_ = nullptr;
		}

		ArrayList& operator=(const ArrayList& other)			//赋值运算符
		{
			if (this != &other)
			{
				//先释放原来的内存
				delete[] data_;

				capacity_ = other.capacity_;
				size_ = other.size_;

				data_ = new T[capacity_];

				//将other.data_的每个数据复制到data_中
				for (size_t i = 0; i < capacity_; i++)
				{
					data_[i] = std::move(other.data_[i]);
				}
			}

			return *this;
		}

		ArrayList& operator=(ArrayList&& other) noexcept		//移动赋值运算符
		{
			if (this != &other)
			{
				capacity_ = other.capacity_;
				size_ = other.size_;
				data_ = other.data_;

				//将原来的data设置成nullptr
				other.data_ = nullptr;
			}

			return *this;
		}



		void addFirst(const T& data) override				//在列表第一个位置插入新数据
		{
			//判断是否需要扩容
			if (capacity_ == size_)
			{
				resize(capacity_ * 2);
			}

			for (size_t i = size_; i >= 1; i--)
			{
				data_[i] = std::move(data_[i - 1]);
			}

			data_[0] = std::move(data);
			size_++;
		}

		T removeFirst() override							//将列表第一个位置的数据删除
		{
			if (isEmpty())
			{
				throw std::out_of_range("Cannot remove from an empty list!");
			}

			T data = std::move(data_[0]);

			for (size_t i = 0; i < size_ - 1; i++)
			{
				data_[i] = std::move(data_[i + 1]);
			}

			data_[size_ - 1].~T();

			size_--;

			if (size_ < capacity_ / 4)
			{
				resize(capacity_ / 2);
			}

			return data;
		}

		void addLast(const T& data) override				//在列表最后一个位置插入新数据
		{
			if (capacity_ == size_)
			{
				resize(capacity_ * 2);
			}

			data_[size_++] = std::move(data);
		}

		T removeLast() override								//将列表最后一个位置的数据删除
		{
			if (isEmpty())
			{
				throw std::out_of_range("Cannot remove from an empty list!");
			}

			T data = std::move(data_[size_ - 1]);
			//将最后一个元素手动析构
			data_[size_ - 1].~T();

			size_--;

			if (size_ < capacity_ / 4)
			{
				resize(capacity_ / 2);
			}

			return data;
		}

		T getValue(size_t index) const override					//获得下标index处的数据
		{
			if (index >= size_)
			{
				throw std::out_of_range("Index out of range");
			}

			return data_[index];
		}

		T& getReference(size_t index) override				//获得下标index处的数据的引用
		{
			if (index >= size_)
			{
				throw std::out_of_range("Index out of range");
			}

			return data_[index];
		}

		const T& get(size_t index) const override			//获得下标index处的数据的常量引用
		{
			if (index >= size_)
			{
				throw std::out_of_range("Index out of range");
			}

			return data_[index];
		}

		const T& operator[](size_t index) const override	//重载[]以实现用数组方式获得下标index处的常量引用
		{
			if (index >= size_)
			{
				throw std::out_of_range("Index out of range");
			}

			return data_[index];
		}

		T remove(size_t index) override						//删除下标index处的数据
		{
			if (index >= size_)
			{
				throw std::out_of_range("Index out of range");
			}

			T data = data_[index];

			for (size_t i = index; i < size_ - 1; i++)
			{
				data_[i] = std::move(data_[i + 1]);
			}

			data_[size_ - 1].~T();

			size_--;

			return data;
		}

		void set(size_t index, const T& data) override		//在下标index出的元素重新设置成data
		{
			if (index >= size_)
			{
				throw std::out_of_range("Index out of range");
			}

			for (size_t i = index; i < size_ - 1; i++)
			{
				data_[i + 1] = std::move(data_[i]);
			}

			data_[index] = std::move(data);
		}

		bool isEmpty() const override { return size_ == 0; }		//判断列表是否为空	

		size_t size() const override { return size_; };			//获得列表中元素的数量

		friend std::ostream& operator<<(std::ostream& os, const ArrayList& list)	//重载<<以实现输出列表中元素，需要显式具体化
		{
			os << "[";

			for (size_t i = 0; i < list.size() - 1; i++)
			{
				os << list.get(i) << " ";
			}

			return os << list.get(list.size() - 1) << "]";
		}

	private:
		T* data_;			//存放数据的数组

		size_t capacity_;	//该列表的容量大小

		size_t size_;		//该列表现在使用的数量


		void resize(size_t new_capacity)	//当列表中元素数量到达一定值时，需要进行扩容等
		{
			T* temp = new T[new_capacity];

			for (size_t i = 0; i < size(); i++)
			{
				temp[i] = std::move(data_[i]);
			}

			delete[] data_;

			data_ = temp;
			capacity_ = new_capacity;
		}

		void clear() override
		{
			if (isEmpty())
			{
				return;
			}

			delete[] data_;
		}
	};
}

#endif // !ARRAYLIST_HPP