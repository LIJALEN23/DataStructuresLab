#pragma once
#include "test_arraylist.h"
#include "./../include/datastructures/linkedlist.h"

namespace test_arraylist
{
	void testConstructor()
	{
		std::cout << "\n\nTEST[testConstructor()]:\n\n";

		arraylist::ArrayList<u32> list1;
		for (u32 i = 5; i >= 1; i--)
		{
			list1.addFirst(i);
		}
		std::cout << list1 << std::endl;
	}

	void testCopyConstructor1()
	{
		arraylist::ArrayList<u32> list1;
		for (u32 i = 5; i >= 1; i--)
		{
			list1.addFirst(i);
		}
		std::cout << "list1 : " << list1 << std::endl;

		arraylist::ArrayList<u32> list2 = std::move(list1);
		std::cout << "list2 : " << list2 << std::endl;
	}

	void testCopyConstructor2()
	{
		arraylist::ArrayList<linkedlist::LinkedList<u32>> list1;

		linkedlist::LinkedList<u32> arrElem;
		for (u32 i = 1; i < 100; i++)
		{
			arrElem.addLast(i);
		}
		for (size_t i = 0; i < 10; i++)
		{
			list1.addLast(arrElem);
		}

		for (size_t i = 0; i < list1.size(); i++)
		{
			auto& list = list1.getReference(i);

			for (u32 j = 0; j < 100; j++)
			{
				list.addLast(j);
			}
		}

		for (size_t i = 0; i < list1.size(); i++)
		{
			std::cout << std::endl << list1[i] << std::endl;
		}
	}

	void testBasic()
	{
		using namespace arraylist;
		std::cout << "\n\nTEST[testBasic()]:\n\n";

		ArrayList<u32> list1(100);
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
	}

}
