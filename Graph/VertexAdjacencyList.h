#pragma once
#include "pch.h"
/*
*	EdgeAdjacencyList.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/
#include "Vertex.h"
namespace csl {

template<class IdTy, class EdgeTy>
class VertexAdjacencyList: public Vertex<IdTy>
{
	typedef std::shared_ptr<EdgeTy> Ptr;

public:
	VertexAdjacencyList() = delete;
	VertexAdjacencyList(IdTy&);
	VertexAdjacencyList(VertexAdjacencyList&);
	VertexAdjacencyList(VertexAdjacencyList&&);
	~VertexAdjacencyList();
public:
	VertexAdjacencyList& operator=(const VertexAdjacencyList&);
	VertexAdjacencyList& operator=(const VertexAdjacencyList&&);
public:
	decltype(E.begin()) BeginE() { return E.begin(); };
	decltype(E.end()) EndE() { return E.end(); };
private:
	std::vector<Ptr> E;
};

template<class IdTy, class EdgeTy>
VertexAdjacencyList<IdTy, EdgeTy>::VertexAdjacencyList(IdTy& id):
	Vertex<IdTy>(id)
{
}

template<class IdTy, class EdgeTy>
VertexAdjacencyList<IdTy, EdgeTy>::~VertexAdjacencyList()
{
}
template<class IdTy, class EdgeTy>
VertexAdjacencyList<IdTy, EdgeTy>::VertexAdjacencyList(VertexAdjacencyList<IdTy, EdgeTy>& v):
	Vertex<IdTy>(v)
{
	*this = v;
}
template<class IdTy, class EdgeTy>
VertexAdjacencyList<IdTy, EdgeTy>::VertexAdjacencyList(VertexAdjacencyList<IdTy, EdgeTy>&& v):
	Vertex<IdTy>(v)
{
	*this = std::move(v);
}
template<class IdTy, class EdgeTy>
VertexAdjacencyList<IdTy, EdgeTy>& VertexAdjacencyList<IdTy, EdgeTy>::operator=(const VertexAdjacencyList<IdTy, EdgeTy>& v)
{
	this->E = v.E;
	for (auto it = E.begin(); it != E.end; it++)
	{
		std::shared_ptr<EdgeTy> buf(new EdgeTy(**it));
		*it = buf;
	}
	return *this;
}
template<class IdTy, class EdgeTy>
VertexAdjacencyList<IdTy, EdgeTy>& VertexAdjacencyList<IdTy, EdgeTy>::operator=(const VertexAdjacencyList<IdTy, EdgeTy>&& v)
{
	if (&v != this)
	{
		this->E = std::move(v.E);
	}
	return *this;
}

}