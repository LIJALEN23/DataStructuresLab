/**
 * @file graph.h
 * @brief 图数据结构头文件
 *
 * @author [lijalen](https://github.com/LIJALEN23)
 * @date 2024-11-20
 * @version
 */
#pragma once
#include <iostream>
#include <memory>
#include "./../myint.h"
#include "./../datastructures/arraylist.h"

 /**
  * @namespace graph
  * @brief 与图数据结构相关的代码放在该名称空间
 */
namespace graph
{
    using arraylist::ArrayList;
    using std::unique_ptr;
    using std::shared_ptr;


    /**
     * @brief graph类
     *
     * @details 一个泛型的图抽象类
     */
    template<typename V>
    class Graph
    {
    public:
        virtual ~Graph() = default;

        virtual void addEdge(const V& src, const V& dest) = 0;

        virtual void removeEdge(const V& src, const V& dest) = 0;

        virtual void hasEdage(const V& src, const V& dest) const = 0;

        virtual void printGraph(const V& src, const V& dest) const = 0;

        virtual void dfs(const V& start) const = 0;

        virtual void bfs(const V& start) const = 0;
    };

    /**
     * @brief GraphMatrix
     *
     * @details 一个泛型邻接矩阵实现的图数据结构
     */
    template<typename V>
    class GraphMatrix : public virtual Graph<V>
    {
    public:
        GraphMatrix()
        {

        }

        GraphMatrix(size_t num)
        {

        }

        virtual ~GraphMatrix()
        {

        }

        void addEdge(const V& src, const V& dest) override
        {

        }

        void removeEede(const V& src, const V& dest) override
        {

        }

        void hasEdge(const V& src, const V& dest) const override
        {

        }

        void printGraph(const V& src, const V& dest) const override
        {

        }

        void dfs(const V& start) const override
        {

        }

        void bfs(const V& start) const override
        {

        }

    private:
        size_t numVertices;
        unique_ptr<ArrayList<unique_ptr<ArrayList<size_t>>>> matrix;    

    };
    /**
     * @brief GraphAdjList
     *
     * @details 一个泛型邻接表实现的图结构
    */
    template<typename V>
    class GraphAdjList : public virutal Graph<V>
    {
    public:
        GraphAdjList()
        {

        }

        GraphAdjList(size_t numVertices)
        {

        }

        virtual ~GraphAdjList()
        {

        }

        void addEdge(const V& src, const V& dest) override
        {

        }

        void removeEede(const V& src, const V& dest) override
        {

        }

        void hasEdge(const V& src, const V& dest) const override
        {

        }

        void printGraph(const V& src, const V& dest) const override
        {

        }

        void dfs(const V& start) const override
        {

        }

        void bfs(const V& start) const override
        {

        }

    private:
    };
}