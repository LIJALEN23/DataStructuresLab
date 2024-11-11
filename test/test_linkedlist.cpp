#include "test_linkedlist.h"
#include <iostream>	

namespace test_linkedlist
{
	void testBasic()
	{
		using namespace linkedlist;

		LinkedList<u32> list1;

		for (u32 i = 100; i >= 1; i--)
		{
			list1.addFirst(i);
		}
		std::cout << "list1(1 - 100) : " << list1 << std::endl;

		for (u32 i = 101; i <= 200; i++)
		{
			list1.addLast(i);
		}
		std::cout << std::endl << "list(1 - 200) : " << list1 << std::endl;



		std::cout << "The index of 150 : " << list1[150] << std::endl;

		LinkedList<u32> list2 = list1;
		std::cout << std::endl << list2 << std::endl;

	}
}

