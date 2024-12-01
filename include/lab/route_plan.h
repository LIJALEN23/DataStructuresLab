/**
* @file route_plan.h
* @brief Matrix_Graph类的头文件
*
* @author [lijalen](https://github.com/LIJALEN23)
* @date 2024-12-01
* @version 1.0
*/
#pragma once
#include <iostream>
#include <sstream>
#include <cstddef>
#include <string>
#include <memory>
#include <cstdint>

#define INFI UINT32_MAX		//将无路径设置为32位无符号数的最大值

/**
* @namespace route_plan
* @brief lab04实现一个邻接矩阵存储有向加权图的类
*/
namespace route_plan
{
	/**
	* @brief 邻接矩阵存储有向加权图的类
	*/
	class MatrixGraph
	{
	public:
		/**
		* @brief 构造函数
		* @param verticeArr 顶点数组
		* @param length 顶点数组的长度
		*/
		MatrixGraph(std::string* verticeArr, size_t length);

		/**
		* @brief 析构函数
		*/
		~MatrixGraph() = default;

		/**
		* @brief 添加一条边
		* @param vertice1 顶点1
		* @param vertice2 顶点2
		* @param weight 权重
		*/
		void addEdge(const std::string& vertice1, const std::string& vertice2, uint32_t weight);

		/**
		* @brief 修改一条边
		* @param vertice1 顶点1
		* @param vertice2 顶点2
		* @param weight 权重
		*/
		void alterEdge(const std::string& vertice1, const std::string& vertice2, uint32_t weight) { addEdge(vertice1, vertice2, weight); }
		
		/**
		* @brief 删除一条边
		* @param vertice1 顶点1
		* @param vertice2 顶点2
		*/
		void removeEdge(const std::string& vertice1, const std::string& vertice2);

		/**
		* @brief 判断是否存在一条边
		* @param vertice1 顶点1
		* @param vertice2 顶点2
		* @return true 存在一条边
		* @return false 不存在一条边
		*/
		bool hasEdge(const std::string& vertice1, const std::string& vertice2) const;

		/**
		* @brief 获取顶点的索引
		* @param verticeName 顶点名称
		* @return size_t 顶点的索引
		*/
		size_t getVerticeIndex(const std::string& verticeName) const;
		
		/**
		* @brief 获取最短路径(弗洛伊德算法)
		* @param start 起点
		* @param end 终点
		* @return std::string 最短路径
		*/
		std::string findShortesPath(const std::string& start, const std::string& end) const;

		/**
		* @brief 获取所有最短路径(迪杰斯特拉算法)
		* @param start 起点
		* @return std::unique_ptr<std::string[]> 所有最短路径
		*/
		std::unique_ptr<std::string[]> findAllShortestPath(const std::string start) const;

		void execInput(const std::string& input);

		/**
		* @brief 重载输出运算符
		* @param os 输出流
		* @param graph 邻接矩阵存储有向加权图
		* @return std::ostream& 输出流
		*/
		friend std::ostream& operator<<(std::ostream& os, const MatrixGraph& graph);

	private:
		std::unique_ptr<std::unique_ptr<uint32_t[]>[]> matrix;	//邻接矩阵
		size_t verticeNum;		//顶点数量
		std::unique_ptr<std::string[]> vertice; //顶点数组
	};

}