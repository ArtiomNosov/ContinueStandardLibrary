#pragma once
/*
* In this graph vertex connects to other vertexs
*/
/*
*	GraphV2V.h
*	Version 0.2
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/
#include "Combinatorics.cpp"
#include "RandomGraphV2V.cpp"

namespace csl {
    template<class IdTy>
    class GraphV2V//: Graph<VertexV2V<IdTy>, EdgeV2V<IdTy>>
    {
        std::vector<VertexV2V<IdTy>> V; // Vertexs
        std::vector<EdgeV2V<IdTy>> E; // Edges - not actual sometimes because there no function sync

    public:
        GraphV2V();
        GraphV2V(VertexV2V<IdTy>& v);
        GraphV2V(std::map<IdTy, VertexV2V<IdTy>> v);
        GraphV2V(std::vector<VertexV2V<IdTy>> v) { *this = v; };
        GraphV2V(GraphV2V& g)
        {
            *this = g;
        }
        GraphV2V(GraphV2V&& g) noexcept
        {
            *this = std::move(g);
        }
        ~GraphV2V();
        GraphV2V& operator=(const GraphV2V& g);
        GraphV2V& operator=(std::vector<VertexV2V<IdTy>>& v);
        GraphV2V& operator=(GraphV2V&& g) noexcept;
        VertexV2V<IdTy>& operator[](IdTy& id) noexcept;

    public:
        GraphV2V<IdTy>&& Coloring(GraphV2V& g)
        {
            size_t cv = g.V.size();
            int nOfColrs = 0;
            auto colorGraph = g;
            int counter = 0;
            std::vector<int> a;
            a.resize(cv);
            for (int i = 0; i < a.size(); i++)
            {
                a[i] = 0;
            }
            // Do refactoring 
            while (isColoring(colorGraph) == false)
            {
                nOfColrs++;
                while (next_combination(a, nOfColrs) == true)
                {
                    for (auto it = colorGraph.V.begin(); it != colorGraph.V.end(); it++, counter++)
                    {
                        (*it).SetColor(a[counter]);
                    }
                    if (isColoring(colorGraph) == true)
                    {
                        return std::move(*(new GraphV2V<IdTy>(colorGraph)));
                    }
                    counter = 0;
                }
            }
            return std::move(*(new GraphV2V<IdTy>(colorGraph)));
        }  // O(n!)
        GraphV2V&& Coloring();              // O(n!)
        bool isColoring(GraphV2V& g);       // Linear O(n)
        bool isColoring();                  // Linear O(n)

    public:

        VertexV2V<IdTy>* Find(std::vector<VertexV2V<IdTy>>& v, IdTy& id) // Linear O(n)
        {
            auto isEquelIdVertexV2V = [&](VertexV2V<IdTy>& v) { return v.GetId() == id; };
            return &(*(std::find_if(v.begin(), v.end(), isEquelIdVertexV2V)));
        }
        VertexV2V<IdTy>* Find(IdTy& id) { return Find(V, id); }
        int Size() { return V.size(); };                        // Linear O(n)
        decltype(V.begin()) Begin() { return V.begin(); };      // Linear O(n)
        decltype(V.begin()) End() { return V.end(); };          // Linear O(n)

    public:
        void AddVertex(std::vector<VertexV2V<IdTy>&>& addVertexs);
        void AddVertex(VertexV2V<IdTy>* addVertex);
        void Clear();

    private:
        VertexV2V<IdTy>* Dfs(IdTy& id); // Depth-First Search
        void UnVisit();

    public:
        VertexV2V<IdTy>& DfsCopy(IdTy& id) { return *Dfs(id); };

    private:
        void RebuildGraph();

    private:    // Checks
        template<class T>
        void CheckNullptr(T* ptr) { if (ptr == nullptr)throw std::exception("Nullptr except!"); }
        void ExcepHasVertex() { if (V.size() <= 0)throw std::exception("No vertex in GraphV2V!"); }

    public:
        class IteratorDfs // Iterator depth
        {
            VertexV2V<IdTy>* Ptr = nullptr;

        public:
            IteratorDfs(VertexV2V<IdTy>* ptr) :
                Ptr(ptr)
            {
            }

        private:
            IteratorDfs() = delete;
            IteratorDfs(IteratorDfs&) = delete;
            IteratorDfs(IteratorDfs&& o) = delete;
            IteratorDfs& operator=(const IteratorDfs&) = delete;
            IteratorDfs& operator=(const IteratorDfs&&) = delete;

        public:
            void operator++(int)
            {
                static std::vector<VertexV2V<IdTy>*> que;
                static std::vector<VertexV2V<IdTy>*> procesed;
                static VertexV2V<IdTy>* BefCurrVer = nullptr;
                static bool isDeadlock = false;
                ExcepHasVertex();
                Ptr = &(*(V.begin()));
                que.push_back(Ptr);
                Ptr = que.back();
                procesed.push_back(Ptr);
                for (auto it = Ptr->Begin(); it != Ptr->End(); it++)
                {
                    isDeadlock = true;
                    if (procesed.end() == std::find(procesed.begin(), procesed.end(), *it))
                    {
                        BefCurrVer = Ptr;
                        Ptr = *it;
                        que.push_back(Ptr);
                        isDeadlock = false;
                        break;
                    }
                }
                if (isDeadlock == true)
                {
                    que.pop_back();
                }
                if (que.empty() == true)
                {
                    Ptr = nullptr;
                }
            }
            VertexV2V<IdTy>* operator*()
            {
                return Ptr;
            }
        };

    public: // Shortest path problem methods 
        // Source Ru: https://ru.wikipedia.org/wiki/%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0_%D0%BE_%D0%BA%D1%80%D0%B0%D1%82%D1%87%D0%B0%D0%B9%D1%88%D0%B5%D0%BC_%D0%BF%D1%83%D1%82%D0%B8#:~:text=%D0%97%D0%B0%D0%B4%D0%B0%CC%81%D1%87%D0%B0%20%D0%BE%20%D0%BA%D1%80%D0%B0%D1%82%D1%87%D0%B0%CC%81%D0%B9%D1%88%D0%B5%D0%BC%20%D0%BF%D1%83%D1%82%D0%B8%CC%81%20%E2%80%94%20%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B0,%D0%BC%D0%BD%D0%BE%D0%B6%D0%B5%D1%81%D1%82%D0%B2%D0%BE%20%D0%B0%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%D0%BE%D0%B2%20%D0%B4%D0%BB%D1%8F%20%D0%B5%D1%91%20%D1%80%D0%B5%D1%88%D0%B5%D0%BD%D0%B8%D1%8F.
        // Source Eng: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
        // virtual GraphV2V& DijkstrasAlgorithm(VertexV2V<IdTy>& vertex) override;

    };
}

#include "GraphV2V.cpp"
