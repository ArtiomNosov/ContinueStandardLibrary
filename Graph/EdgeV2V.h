#pragma once
/*
*	Edge.h
*	Version 0.2
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/
#include "Edge.h"
#include "VertexV2V.h"
namespace csl
{
    template<class T>
    class EdgeV2V : public Edge<T>
    {
        // std::pair<VertexV2V<T>*> V;
    public:
        EdgeV2V() {}
        EdgeV2V(T idFirst, T idSecond)
        {
            this->E.first = idFirst; this->E.second = idSecond;
        }
        EdgeV2V(EdgeV2V& e)
        {
            this->E.first = e.E.first; this->E.second = e.E.second;
        }
        EdgeV2V(EdgeV2V&& e) noexcept
        {
            *this = std::move(e);
        }
        ~EdgeV2V()
        {
        }
        EdgeV2V& operator=(const EdgeV2V& other) {
            this->E.first = other.E.first; this->E.second = other.E.second;
            return *this;
        };
        EdgeV2V& operator=(const EdgeV2V&& e) noexcept {
            this->E.first = std::move(e.E.first);
            this->E.second = std::move(e.E.second);
            e.E.~pair();
            return *this;
        }
        void Set(T& b, T& e) {
            this->E.first = b;
            this->E.second = e;
        }
    };
}