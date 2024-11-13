#include "test_heap.h"

namespace test_heap
{
	using heap::Heap;


	void test_heap::testBasic()
	{
		i32 arr[] = { 1, 3, 4, 534, 31, 1423, 123, 23 };
		size_t size = sizeof(arr) / sizeof(arr[0]);

		Heap<i32> heap(arr, size, heap::MIN_HEAP);
		
		for (size_t i = 0; i < size; i++)
		{
			std::cout << heap.top() << " ";
			heap.pop();
		}

		std::cout << std::endl;
	}
}


