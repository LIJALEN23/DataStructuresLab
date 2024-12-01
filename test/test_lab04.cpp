/**
* @file test_lab04.cpp
* @brief 测试函数的实现
*
* @author [lijalen](https://github.com/LIJALEN23)
* @date 2024-12-01
* @version 1.0
*/
#include "test_lab04.h"
#include <sstream>

namespace test_lab04
{
	/**实验的邻接矩阵图
	*	 A		B		C		D		E		F		G
	* A  0		INFI	10		INFI	INFI	INFI	9
	* B	 20		0		10		30		INFI	INFI	INFI
	* C  INFI	INFI	0		INFI	5		6		INFI
	* D	 INFI	INFI	INFI	0		INFI	INFI	INFI
	* E	 INFI	INFI	INFI	12		0		INFI	INFI
	* F  INFI	INFI	INFI	INFI	8		0		INFI
	* G	 INFI	INFI	3		INFI	5		10		0
	* 
	*/

	void debugRoutePlan()
	{
		std::string verticeName[] = { "A", "B", "C" , "D", "E", "F", "G" };
		size_t verticeNum = sizeof(verticeName) / sizeof(verticeName[0]);

		route_plan::MatrixGraph graph{verticeName, verticeNum};
		
		graph.addEdge("A", "C", 10);
		graph.addEdge("A", "G", 9);
		graph.addEdge("B", "A", 20);
		graph.addEdge("B", "C", 10);
		graph.addEdge("B", "D", 30);
		graph.addEdge("C", "E", 5);
		graph.addEdge("C", "F", 6);
		graph.addEdge("E", "D", 12);
		graph.addEdge("F", "E", 8);
		graph.addEdge("G", "C", 3);
		graph.addEdge("G", "E", 5);
		graph.addEdge("G", "F", 10);

		std::cout << graph << std::endl;

		//Find A to each vertice
		std::unique_ptr<std::string[]> paths = nullptr;
		paths = graph.findAllShortestPath("A");
		for (size_t i = 0; i < verticeNum; i++)
		{
			std::cout << paths[i] << std::endl;
		}
		std::cout << std::endl;

		//Find B to D
		std::string pathB2D;
		pathB2D = graph.findShortesPath("B", "D");
		std::cout << pathB2D << std::endl;
	}

	void RoutePlanMain(int argc, char* argv[])
	{
		size_t verticeLength = static_cast<size_t>(argc - 1);
		std::string* verticeName = new std::string[verticeLength];

		for (size_t i = 1; i < verticeLength; i++)
		{
			verticeName[i] = argv[i];
		}

		//init the graph
		route_plan::MatrixGraph graph{ verticeName, verticeLength };

		//input from keyboard
		std::string input;
		while (true)
		{
			std::cout << "Please enter a instruction: ";
			std::getline(std::cin, input);

			if (input == "exit")
			{
				std::cout << "Bye~" << std::endl;
				return;
			}
			else if (input == "show")
			{
				std::cout << graph << std::endl;
			}
		}
	}
}