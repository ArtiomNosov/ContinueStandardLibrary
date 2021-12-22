#pragma once
#include "pch.h"
/*
*	VertexV2V.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/
#include "Vertex.h"
namespace csl {
    template<class T>
    class VertexV2V : public Vertex<T>
    {
        std::vector<VertexV2V<T>*> Vertexs;
        std::vector<T> VertexsIds;
        bool IsVisit_ = false;
        int Color = 0;
        bool Coloring = false;
    private:
        void InitVertexsIds()
        {
            VertexsIds.clear();
            for (auto it = Begin(); it != End(); it++)
            {
                VertexsIds.push_back((*it)->GetId());
            }
        }
    public:
        VertexV2V() :
            Vertex<T>()
        {
        }
        // Vertex has the same edges!
        VertexV2V(std::vector<VertexV2V<T>*>& v)
        {
            Vertexs = v;
            InitVertexsIds();
        }
        VertexV2V(T id) :
            Vertex<T>(id)
        {
        }
        VertexV2V(const VertexV2V& v)
        {
            *this = v;
        }
        VertexV2V(VertexV2V& v)
        {
            *this = v;
        }
        VertexV2V(VertexV2V&& v) noexcept
        {
            *this = std::move(v);
        }
    public:
        VertexV2V& operator=(const VertexV2V& v)
        {
            this->Id = v.Id;
            IsVisit_ = v.IsVisit_;
            Color = v.Color;
            Vertexs = v.Vertexs;
            VertexsIds = v.VertexsIds;
            return *this;
        }
        VertexV2V& operator=(const VertexV2V&& v)
        {
            if (&v != this)
            {
                this->Id = std::move(v.Id);
                IsVisit_ = v.IsVisit_;
                Color = v.Color;
                Vertexs = std::move(v.Vertexs);
                VertexsIds = std::move(v.VertexsIds);
            }
            return *this;
        }
        VertexV2V& operator=(VertexV2V& v)
        {
            this->Id = v.Id;
            IsVisit_ = v.IsVisit_;
            Color = v.Color;
            Vertexs = v.Vertexs;
            VertexsIds = v.VertexsIds;
            return *this;
        }
        VertexV2V& operator=(VertexV2V&& v) noexcept
        {
            if (&v != this)
            {
                this->Id = std::move(v.Id);
                IsVisit_ = v.IsVisit_;
                Color = v.Color;
                Vertexs = std::move(v.Vertexs);
                VertexsIds = std::move(v.VertexsIds);
            }
            return *this;
        }
    public:
        void SetColor(int c) { Color = c; };
        int GetColor() { return Color; };
        void Visit() { IsVisit_ = true; };
        void UnVisit() { IsVisit_ = false; };
        bool IsVisit() { return IsVisit_; };
        bool IsColoring(); // –аскрашена ли по правилам так что соседние вершины различаютс¤ по цвету с ней TODO: переназвать
        void AddVertex(std::vector<VertexV2V<T>*>& addVertexs);
        void AddVertex(VertexV2V<T>* addVertex, int addids = 0);
        void AddVertexIds(std::vector<T>& addVertexs) = delete;
        void AddVertexIds(T& addId) { VertexsIds.push_back(addId); };
        int CountOfEdges() { return Vertexs.size(); };
    public:
        decltype(Vertexs.begin()) Begin() { return Vertexs.begin(); };
        decltype(Vertexs.begin()) End() { return Vertexs.end(); };
        decltype(VertexsIds.begin()) BeginIds() { return VertexsIds.begin(); };
        decltype(VertexsIds.begin()) EndIds() { return VertexsIds.end(); };
    public:
        void ClearVertexs() { Vertexs.clear(); }
        void ClearVertexsIds() { VertexsIds.clear(); }
        void Clear() { ClearVertexs(); ClearVertexsIds(); }
    };
    template<class T>
    bool VertexV2V<T>::IsColoring()
    {
        Coloring = true;
        for (auto it = Begin(); it != End(); it++)
        {
            Coloring &= (*it)->Color != Color;
            if (Coloring == false)
            {
                return Coloring;
            }
        }
        return Coloring;
    }
    template<class T>
    void VertexV2V<T>::AddVertex(std::vector<VertexV2V<T>*>& addVertexs)
    {
        for (VertexV2V<T>* it : addVertexs)
        {
            Vertexs.push_back(it);
        }
        InitVertexsIds();
    }
    template<class T>
    void VertexV2V<T>::AddVertex(VertexV2V<T>* addVertex, int addids)
    {
        const int ADDIDS = 0;
        Vertexs.push_back(addVertex);
        if (addids == ADDIDS) VertexsIds.push_back(addVertex->GetId());
    }
}