/**
* @file route_plan.cpp
* @brief Matrix_Graph类的实现
*
* @author [lijalen](https://github.com/LIJALEN23)
* @date 2024-12-01
* @version 1.0
*/
#include "./../../include/lab/route_plan.h"

/**
* @namespace route_plan
* @brief Matrix_Graph类的实现
*/
namespace route_plan
{
	MatrixGraph::MatrixGraph(std::string* verticeArr, size_t length)
	{
		(*this).verticeNum = length;
		(*this).vertice = std::make_unique<std::string[]>(length);
		(*this).matrix = std::make_unique<std::unique_ptr<uint32_t[]>[]>(length);

		for (size_t i = 0; i < length; i++)
		{
			//Init matrix
			(*this).matrix[i] = std::make_unique<uint32_t[]>(length);
			for (size_t j = 0; j < length; j++)
			{
				if (i == j)
				{
					(*this).matrix[i][j] = 0;
				}
				else
				{
					(*this).matrix[i][j] = INFI;
				}
			}

			//Init vertice array//Inti 
			(*this).vertice[i] = verticeArr[i];
		}

	}

	void MatrixGraph::addEdge(const std::string& vertice1, const std::string& vertice2, uint32_t weight)
	{
		size_t index1 = getVerticeIndex(vertice1);
		size_t index2 = getVerticeIndex(vertice2);

		if (hasEdge(vertice1, vertice2))
		{
			matrix[index1][index2] = matrix[index1][index2] == weight ? matrix[index1][index2] : weight;
			return;
		}
	
		matrix[index1][index2] = weight;
	}

	void MatrixGraph::removeEdge(const std::string& vertice1, const std::string& vertice2)
	{
		if (!hasEdge(vertice1, vertice2))
		{
			return;
		}

		matrix[getVerticeIndex(vertice1)][getVerticeIndex(vertice2)] = INFI;
	}

	bool MatrixGraph::hasEdge(const std::string& vertice1, const std::string& vertice2) const
	{
		return matrix[getVerticeIndex(vertice1)][getVerticeIndex(vertice2)] != INFI;
	}

	size_t MatrixGraph::getVerticeIndex(const std::string& verticeName) const
	{
		for (size_t i = 0; i < verticeNum; i++)
		{
			if (vertice[i] == verticeName)
			{
				return i;
			}
		}
		
		std::abort();
	}

	std::string MatrixGraph::findShortesPath(const std::string& start, const std::string& end) const
	{
		//Init the distance and next array
		std::unique_ptr<std::unique_ptr<uint32_t[]>[]> distance = std::make_unique<std::unique_ptr<uint32_t[]>[]>(verticeNum);
		std::unique_ptr<std::unique_ptr<size_t[]>[]> preIndex = std::make_unique<std::unique_ptr<size_t[]>[]>(verticeNum);
		for (size_t i = 0; i < verticeNum; i++)
		{
			distance[i] = std::make_unique<uint32_t[]>(verticeNum);
			preIndex[i] = std::make_unique<size_t[]>(verticeNum);

			for (size_t j = 0; j < verticeNum; j++)
			{
				distance[i][j] = matrix[i][j];

				if (matrix[i][j] != INFI && matrix[i][j] != 0)
				{
					preIndex[i][j] = i;
				}
				else
				{
					preIndex[i][j] = SIZE_MAX;
				}
			}
		}
			
		//i 是不是能通过 k 缩短到 j 的距离
		for (size_t k = 0; k < verticeNum; k++)
		{
			for (size_t i = 0; i < verticeNum; i++)
			{
				for (size_t j = 0; j < verticeNum; j++)
				{
					if (distance[i][k] != INFI && distance[k][j] != INFI && distance[i][k] + distance[k][j] < distance[i][j])
					{
						distance[i][j] = distance[i][k] + distance[k][j];
						preIndex[i][j] = preIndex[k][j];
					}
				}
			}	
		}

		std::string path;
		size_t startIndex = getVerticeIndex(start);
		size_t endIndex = getVerticeIndex(end);

		path = start + " -> " + end + " : " + end;
		size_t pre = preIndex[startIndex][endIndex];
		while (pre != SIZE_MAX)
		{
			path = path + " <- " + vertice[pre];
			pre = preIndex[startIndex][pre];
		}
		path = path + "(" + std::to_string(distance[startIndex][endIndex]) + ")";

		return path;
	}

	std::unique_ptr<std::string[]> MatrixGraph::findAllShortestPath(const std::string start) const
	{
		std::unique_ptr<uint32_t[]> distance = std::make_unique<uint32_t[]>(verticeNum);		//The shortest distance
		std::unique_ptr<bool[]> visited = std::make_unique<bool[]>(verticeNum);					//The visited vertice		
		std::unique_ptr<size_t[]> preIndex = std::make_unique<size_t[]>(verticeNum);			//Each vertice's pre vertice'index

		//init the three array above
		for (size_t i = 0; i < verticeNum; i++)
		{
			distance[i] = INFI;
			visited[i] = false;
			preIndex[i] = SIZE_MAX;
		}

		size_t startIndex = getVerticeIndex(start);
		distance[startIndex] = 0;

		for (size_t i = 0; i < verticeNum; i++)
		{
			//Find the nearest vertice(not visited) to start vertice
			size_t nearestIndex = SIZE_MAX;

			for (size_t j = 0; j < verticeNum; j++)
			{
				if (!visited[j] && (distance[j] < distance[nearestIndex] || nearestIndex == SIZE_MAX ))
				{
					nearestIndex = j;
				}
			}

			visited[nearestIndex] = true;

			//Update the adjacency vertice distance
			for (size_t j = 0; j < verticeNum; j++)
			{
				if (!visited[j] && matrix[nearestIndex][j] != INFI && distance[nearestIndex] != INFI)
				{
					uint32_t newDistance = matrix[nearestIndex][j] + distance[nearestIndex];
					if (newDistance < distance[j])
					{
						distance[j] = newDistance;
						preIndex[j] = nearestIndex;	//Update the pre vertice's index
					}
				}
			}
		}

		std::unique_ptr<std::string[]> paths = std::make_unique<std::string[]>(verticeNum);
		for (size_t i = 0; i < verticeNum; i++)
		{
			std::string path = start + " -> " + vertice[i] +  " : ";

			if (preIndex[i] == SIZE_MAX)
			{
				path += "没有路径";
				paths[i] = path;
			}
			else
			{
				path += vertice[i];
				size_t pre = preIndex[i];
				while (preIndex[pre] != SIZE_MAX)
				{
					path = path + " <- " + vertice[pre];
					pre = preIndex[pre];
				}
				path = path + " <- " + start + "(" + std::to_string(distance[i]) + ")" ;

				paths[i] = path;
			}
		}

		return paths;
	}

	void MatrixGraph::execInput(const std::string& input)
	{
		std::istringstream iss(input);
		std::string command;
		iss >> command;

		if (command == "show")
		{	//show
			std::cout << (*this);
		}
		else if (command == "add")
		{	//add vertice1 vertice2 weight)
			std::string vertice1;
			std::string vertice2;
			uint32_t weight;

			iss >> vertice1 >> vertice2 >> weight;

			addEdge(vertice1, vertice2, weight);
		}
		else if (command == "remove")
		{	//remove vertice1 vertice2
			std::string vertice1;
			std::string vertice2;

			iss >> vertice1 >> vertice2;

			removeEdge(vertice1, vertice2);

		}
		else if (command == "findAll")
		{	//findAll vertice
			std::string vertice;
			iss >> vertice;

			std::unique_ptr<std::string[]> paths = std::make_unique<std::string[]>(verticeNum);
			paths = findAllShortestPath(vertice);
			for (size_t i = 0; i < verticeNum; i++)
			{
				std::cout << paths[i] << std::endl;
			}
			std::cout << std::endl;
		}
		else if (command == "find")
		{	//find vertice1 to vertice2
			std::string vertice1;
			std::string vertice2;

			iss >> vertice1 >> vertice2;

			std::cout << findShortesPath(vertice1, vertice2) << std::endl;
		}
		else
		{
			std::cout << "Command not find" << std::endl;
		}
	}

	std::ostream& operator<<(std::ostream& os, const MatrixGraph& graph)
	{
		//os << "\t";
		for (size_t i = 0; i < graph.verticeNum; i++)
		{
			os << "\t" << graph.vertice[i];
		}
		os << std::endl;

		for (size_t i = 0; i < graph.verticeNum; i++)
		{
			os << graph.vertice[i];

			for (size_t j = 0; j < graph.verticeNum; j++)
			{
				if (graph.matrix[i][j] == INFI)
				{
					os << "\tINFI";
				}
				else
				{
					os << "\t" << graph.matrix[i][j];
				}
			}
			os << std::endl;
		}
		os << std::endl;

		return os;
	}


}
