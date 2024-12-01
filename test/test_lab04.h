/**
* @file test_lab04.h
* @brief 实验四测试文件
*
* @author [lijalen](https://github.com/LIJALEN23)
* @date 2024-12-01
* @version 1.0
*/
#pragma once
#include "./../include/lab/route_plan.h"

/**
* @namespace test_lab04
* @brief 实验四测试相关函数
*/
namespace test_lab04
{
	/**
	* @brief 调试路径规划算法
	*/
	void debugRoutePlan();

	/**
	* @brief 路径规划主函数
	* @param argc 参数个数
	* @param argv 参数列表
	*/
	void RoutePlanMain(int argc, char* argv[]);
}
