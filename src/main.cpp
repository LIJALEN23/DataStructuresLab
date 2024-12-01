/**
* @file main.cpp
* @brief Main file for testing all the functions in the project
* 
* @author [lijalen](https://github.com/LIJALEN23) 
*/
#include <iostream>
#include "./../test/test_arraylist.h"
#include "./../test/test_linkedlist.h"
#include "./../test/test_linkedbinarytree.h"
#include "./../test/test_lab03.h"
#include "./../test/test_heap.h"
#include "./../test/test_graph.h"
#include "./../test/test_lab04.h"

int main(int argc, char* argv[]) {

	std::cout << "Hello, lijalen!" << std::endl;
	std::cout << "Enjoy your time!\n\n\n\n\n";


	//test_lab04::debugRoutePlan();
	test_lab04::RoutePlanMain(argc, argv);

	return 0;
}