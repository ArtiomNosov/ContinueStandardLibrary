#pragma once
#include "pch.h"
/*
*	Edge.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/
namespace csl {

template<class T>
class Edge
{
    typedef std::shared_ptr<T> Ptr;
public:
    Edge() = delete;
    Edge(std::shared_ptr<T>&, std::shared_ptr<T>&);
    Edge(Edge& e);
    Edge(Edge&& e);
    ~Edge();
public:
    void SetFirst(std::shared_ptr<T>&);
    void SetSecond(std::shared_ptr<T>&);
    std::shared_ptr<T>& GetFirst();
    std::shared_ptr<T>& GetSecond();
protected:
    std::pair<Ptr, Ptr> E;
    Edge& operator=(const Edge&);
    Edge& operator=(const Edge&&);
};
template<class T>
Edge<T>::Edge(std::shared_ptr<T>& first, std::shared_ptr<T>& second)
{
    E.first = first;
    E.second = second;
}
template<class T>
Edge<T>::Edge(Edge<T>& e)
{
    *this = e;
}
template<class T>
Edge<T>::Edge(Edge<T>&& e)
{
    *this = std::move(e);
}
template<class T>
Edge<T>::~Edge()
{
}
template<class T>
void Edge<T>::SetFirst(std::shared_ptr<T>& ptr)
{
    E.first = ptr;
}
template<class T>
void Edge<T>::SetSecond(std::shared_ptr<T>& ptr)
{
    E.second = ptr;
}
template<class T>
std::shared_ptr<T>& Edge<T>::GetFirst()
{
    return E.first;
}
template<class T>
std::shared_ptr<T>& Edge<T>::GetSecond()
{
    return E.second;
}

template<class T>
Edge<T>& Edge<T>::operator=(const Edge<T>& e)
{
    this->E = e.E;
    return *this;
}
template<class T>
Edge<T>& Edge<T>::operator=(const Edge<T>&& e)
{
    if (&e != this)
    {
        this->E = std::move(e.E);
    }
    return *this;
}
}