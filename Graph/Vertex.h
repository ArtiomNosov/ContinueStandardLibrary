#pragma once
/*
*	Vertex.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/
namespace csl {
    template<class T>
    class Vertex
    {
    protected:
        T Id;
    public:
        Vertex() :
            Id()
        {

        }
        Vertex(T id) :
            Id(id)
        {

        }
        Vertex(Vertex& v)
        {
            *this = v;
        }
        Vertex(Vertex&& v)
        {
            *this = std::move(v);
        }
        ~Vertex()
        {
        }
        Vertex& operator=(const Vertex& v)
        {
            Id = v.Id;
            return *this;
        }
        Vertex& operator=(const Vertex&& v)
        {
            if (&v != this)
            {
                Id = std::move(v.Id);
            }
            return *this;
        }
        T& GetId()
        {
            return Id;
        }
        void SetId(T& id)
        {
            Id = id;
        }
    };
}