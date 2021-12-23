#pragma once
#include "pch.h"
/*
*	EdgeAdjacencyList.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/
#include "Edge.h"
namespace csl {

template<class T>
class EdgeAdjacencyList: public Edge<T>
{
public:
	EdgeAdjacencyList() = delete;
	EdgeAdjacencyList(std::shared_ptr<T>, std::shared_ptr<T>);
	~EdgeAdjacencyList();

private:

};

template<class T>
EdgeAdjacencyList<T>::EdgeAdjacencyList(std::shared_ptr<T> first, std::shared_ptr<T> second):
	Edge<T>(first, second)
{
}

template<class T>
EdgeAdjacencyList<T>::~EdgeAdjacencyList()
{
}

}