#pragma once

namespace list
{
	template<typename T>
	class List
	{
	public:

		virtual ~List() = default;

		virtual void addFirst(const T& data) = 0;

		virtual T removeFirst() = 0;

		virtual void addLast(const T& data) = 0;

		virtual T removeLast() = 0;

		virtual T getValue(size_t index) const = 0;

		virtual T& getReference(size_t index) = 0;

		virtual const T& get(size_t index) const = 0;

		virtual const T& operator[](size_t index) const = 0;

		virtual T remove(size_t index) = 0;

		virtual void set(size_t index, const T& data) = 0;

		virtual bool isEmpty() const = 0;

		virtual size_t size() const = 0;

	protected:

		virtual void clear() = 0;
	};

}