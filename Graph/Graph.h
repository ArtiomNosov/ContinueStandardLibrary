#pragma once
/*  Sourses:
* - https://prog-cpp.ru/data-graph/#height Основная ифнормация про графы,
*	обходы в глубину в ширину, поиск кратчайшего пути,
* - https://cpp.mazurok.com/tag/%D0%BD%D0%B5%D0%BE%D1%80%D0%B8%D0%B5%D0%BD%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%BD%D1%8B%D0%B9-%D0%B3%D1%80%D0%B0%D1%84/
*	Задача на неориентированном графе
* - https://www.cyberforum.ru/cpp-beginners/thread153326.html
*	Пара простых задачь на неориентированном графе
* - https://coderoad.ru/5493474/%D0%A0%D0%B5%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D1%8F-%D0%B3%D1%80%D0%B0%D1%84%D0%B0-C
*	Coderoad - Реализация графа C++
*/
#include "Vertex.h"
#include "Edge.h"
/*
*	Graph.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/
namespace csl {
    enum class GraphTypeConnect {
        ConnectedGraph,
        UnConnectedGraph,
    };
    enum class ConnectivityComponent {
        One,
        MoreThenOne,
    };
    template<class VertexTy, class EdgeTy>
    class Graph
    {
    public:
        Graph();
        Graph(Graph&) = delete;
        Graph(Graph&& g) = delete;
        ~Graph();
        Graph& operator=(const Graph&) = delete;
        Graph& operator=(const Graph&& g) = delete;

    public: // Shortest path problem methods 
        // Source Ru: https://ru.wikipedia.org/wiki/%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0_%D0%BE_%D0%BA%D1%80%D0%B0%D1%82%D1%87%D0%B0%D0%B9%D1%88%D0%B5%D0%BC_%D0%BF%D1%83%D1%82%D0%B8#:~:text=%D0%97%D0%B0%D0%B4%D0%B0%CC%81%D1%87%D0%B0%20%D0%BE%20%D0%BA%D1%80%D0%B0%D1%82%D1%87%D0%B0%CC%81%D0%B9%D1%88%D0%B5%D0%BC%20%D0%BF%D1%83%D1%82%D0%B8%CC%81%20%E2%80%94%20%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B0,%D0%BC%D0%BD%D0%BE%D0%B6%D0%B5%D1%81%D1%82%D0%B2%D0%BE%20%D0%B0%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%D0%BE%D0%B2%20%D0%B4%D0%BB%D1%8F%20%D0%B5%D1%91%20%D1%80%D0%B5%D1%88%D0%B5%D0%BD%D0%B8%D1%8F.
        // Source Eng: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
        // virtual Graph& DijkstrasAlgorithm(VertexTy& vertex) = 0;

    private:
        std::vector<EdgeTy> V; // Edges
    };

    template<class VertexTy, class EdgeTy>
    Graph<VertexTy, EdgeTy>::Graph()
    {
    }

    template<class VertexTy, class EdgeTy>
    Graph<VertexTy, EdgeTy>::~Graph()
    {

    }
}

