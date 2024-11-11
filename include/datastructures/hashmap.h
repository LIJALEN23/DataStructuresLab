//#pragma once
//#include "arraylist.hpp"
//#include "linkedlist.hpp"
//#include <iostream>
//
//
//
//namespace hashmap
//{
//	using linkedlist::LinkedList;
//	using arraylist::ArrayList;
//
//	constexpr size_t DEFAULT_CAPACITY = 8;
//	constexpr float LOAD_FACTOR = 0.75f;
//
//	template<typename K, typename V>
//	class HashMap
//	{
//	public:
//		HashMap()
//		{
//			capacity_ = DEFAULT_CAPACITY;
//			size_ = 0;
//		}
//
//
//		HashMap(size_t capacity)
//		{
//			capacity_ = capacity;
//			size_ = 0;
//		}
//
//
//		~HashMap()
//		{
//			bucket_.~ArrayList();
//
//			size_ = 0;
//			capacity_ = 0;
//		}
//
//
//		HashMap(const HashMap& other)
//		{
//			for (size_t i = 0; i < other.bucket_.size(); i++)
//			{
//				const auto& otherList = other.bucket_[i];
//				LinkedList<Pair> newList = std::move(otherList);
//
//				bucket_[i] = std::move(other.bucket_[i]);
//			}
//		}
//
//
//		HashMap(HashMap&& other) noexcept
//		{
//			capacity_ = other.capacity_;
//			size_ = other.size_;
//			bucket_ = std::move(other.bucket_);
//
//			other.bucket_.~ArrayList();
//		}
//
//
//		HashMap<K, V>& operator=(const HashMap& other)
//		{
//			if (this != &other)
//			{
//				bucket_.~ArrayList();
//
//				size_ = other.size_;
//				capacity_ = other.capacity_;
//
//				for (size_t i = 0; i < other.bucket_.size(); i++)
//				{
//					const auto& otherList = other.bucket_[i];
//					LinkedList<Pair> newList = std::move(otherList);
//
//					bucket_[i] = std::move(other.bucket_[i]);
//				}
//			}
//
//			return *this;
//		}
//
//
//		HashMap<K, V>& operator=(HashMap&& other) noexcept
//		{
//			if (this != &other)
//			{
//				size_ = other.size_;
//				capacity_ = other.capacity_;
//
//				bucket_ = std::move(other.bucket_);
//				other.bucket_.~ArrayList;
//			}
//
//			return *this;
//		}
//
//
//		void put(const K& key, const V& val)
//		{
//			size_t index = hash(key);
//			LinkedList<Pair>& list = bucket_.getReference(index);
//
//			//判断是否有这个键值对，如果有则需要更新值
//			for (size_t i = 0; i < list.size(); i++)
//			{
//				Pair& pair = list.getReference(i);
//				if (pair.key_ == key)
//				{
//					pair.val_ = val;
//					return;
//				}
//			}
//
//			list.addLast(Pair(key, val));
//			++size_;
//
//			ensureCapacity();
//		}
//
//
//		const V& get(const K& key) const
//		{
//			size_t index = hash(key);
//			auto& list = bucket_.get(index);
//
//			for (auto* current = list.head_; current != nullptr; current = current->next_)
//			{
//				if (current->data_.key_ == key)
//				{
//					return current->data_.val_;
//				}
//			}
//			throw std::runtime_error("Key not found.");
//		}
//
//		V& get(const K& key)
//		{
//			size_t index = hash(key);
//			const auto& list = bucket_.get(index);
//
//			for (auto* current = list.head_; current != nullptr; current = current->next_)
//			{
//				if (current->data_.key_ == key)
//				{
//					return current->data_.val_;
//				}
//			}
//			throw std::runtime_error("Key not found.");
//		}
//
//		V remove(const K& key)
//		{
//			size_t index = hash(key);
//			auto& list = bucket_.get(index);
//			auto* current = list.head_;
//			while (current != nullptr)
//			{
//				if (current->data_.key_ == key)
//				{
//					V val = current->data_.val_;
//
//					if (current == list.head_)
//					{
//						list.head_ = current->next;
//					}
//
//					if (current == list.tail_)
//					{
//						list.tail_ = current->pre;
//					}
//
//					if (current->pre_ != nullptr)
//					{
//						current->pre_->next_ = current->next_;
//					}
//					if (current->next_ != nullptr)
//					{
//						current->next_->pre_ = current->pre_;
//					}
//
//					delete current;
//					--size_;
//					return val;
//				}
//				current = current->next_;
//			}
//			throw std::runtime_error("Key not found.");
//		}
//
//		bool containsVal(const V& val) const
//		{
//			for (size_t i = 0; i < capacity_; i++)
//			{
//				auto& list = bucket_.get(i);
//				for (auto* current = list.head_; current != nullptr; current = current->next_)
//				{
//					if (current->data_.val_ == val)
//					{
//						return true;
//					}
//				}
//			}
//			return false;
//		}
//
//
//		bool containsKey(const K& key) const
//		{
//			size_t index = hash(key);
//			const auto& list = bucket_.get(index);
//			for (auto* current = list.head_; current != nullptr; current = current->next_)
//			{
//				if (current->data_.key_ == key)
//				{
//					return true;
//				}
//			}
//			return false;
//		}
//
//		size_t size() const { return size_; };
//
//		bool isEmpty() const { return size_ == 0; }
//
//
//	private:
//
//		void resize(size_t new_capacity)
//		{
//			ArrayList<LinkedList<Pair>> new_bucket(new_capacity);
//
//			for (size_t i = 0; i < capacity_; i++)
//			{
//				auto& list = bucket_.get(i);
//
//				for (auto* current = list.head_; current != nullptr; current = current->next_)
//				{
//					Pair pair = current->data_;
//					size_t new_index = hash(pair.key_);
//					auto& new_list = new_bucket.get(new_index);
//					new_list.addLast(pair);
//				}
//			}
//
//			bucket_ = new_bucket;
//			capacity_ = new_capacity;
//
//		}
//
//		//默认为整型
//		size_t hash(const K& key) const { return key % capacity_; }
//
//		void ensureCapacity()
//		{
//			if ((float)(size_ / capacity_) >= LOAD_FACTOR)
//			{
//				resize(capacity_ * 2);
//			}
//		}
//
//		struct Pair
//		{
//			K key_;
//			V val_;
//
//			Pair(const K& key, const V& val) : key_(key), val_(val) {}
//		};
//
//
//		ArrayList<LinkedList<Pair>> bucket_;
//		size_t capacity_;
//		size_t size_;
//	};
//
//	
//
//}