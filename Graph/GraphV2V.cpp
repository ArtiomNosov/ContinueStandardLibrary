namespace csl
{
    template<class IdTy>
    GraphV2V<IdTy>::GraphV2V()
    {
        // There is nothing
    }
    template<class IdTy>
    GraphV2V<IdTy>::GraphV2V(VertexV2V<IdTy>& v)
    {
        *this = v;
    }
    template<class IdTy>
    GraphV2V<IdTy>::GraphV2V(std::map<IdTy, VertexV2V<IdTy>> v)
    {
        std::vector<VertexV2V<IdTy>> vector;
        for (auto it = v.begin(); it != v.end(); it++)
        {
            vector.push_back((*it).second);
        }
        *this = std::move(vector);
    }
    template<class IdTy>
    GraphV2V<IdTy>::~GraphV2V()
    {
        V.clear();
    }

    template<class IdTy>
    GraphV2V<IdTy>& GraphV2V<IdTy>::operator=(const GraphV2V& g)
    {
        V.clear();
        V = g.V;
        // Clear old edges
        for (auto it = V.begin(); it != V.end(); it++)
        {
            (*it).ClearVertexs();
        }
        // Set the same edges
        for (auto it_1 : g.V)
        {
            for (auto it_2 = it_1.Begin(); it_2 != it_1.End(); it_2++)
            {
                (Find(it_1.GetId()))->\
                    AddVertex(Find( /**/ (*it_2)->GetId() /**/));
            }
        }
        return *this;
    }
    template<class IdTy>
    GraphV2V<IdTy>& GraphV2V<IdTy>::operator=(std::vector<VertexV2V<IdTy>>& v)
    {
        V.clear();
        V = v;
        // Clear old edges
        for (auto it = V.begin(); it != V.end(); it++)
        {
            (*it).ClearVertexs();
        }
        // Set the same edges
        for (auto it_1 : v)
        {
            for (auto it_2 = it_1.Begin(); it_2 != it_1.End(); it_2++)
            {
                (Find(it_1.GetId()))->AddVertex(Find((*it_2)->GetId()));
            }
        }
        return *this;
    }
    template<class IdTy>
    GraphV2V<IdTy>& GraphV2V<IdTy>::operator=(GraphV2V<IdTy>&& g) noexcept
    {
        if (this != &g)
        {
            V = std::move(g.V); g.~GraphV2V();
        }
        return *this;
    }
    template<class IdTy>
    VertexV2V<IdTy>& GraphV2V<IdTy>::operator[](IdTy& id) noexcept
    {
        return *(Dfs(id));
    }
    template<class IdTy>
    GraphV2V<IdTy>&& GraphV2V<IdTy>::Coloring()
    {
        return this->Coloring(*this);
    }
    template<class IdTy>
    bool GraphV2V<IdTy>::isColoring(GraphV2V<IdTy>& g)
    {
        bool coloring = true;
        for (auto it = g.V.begin(); it != g.V.end(); it++)
        {
            coloring &= (*it).IsColoring();
            if (coloring == false)
            {
                return false;
            }
        }
        return true;
    }
    template<class IdTy>
    bool GraphV2V<IdTy>::isColoring()
    {
        bool coloring = true;
        for (auto it = V.begin(); it != V.end(); it++)
        {
            coloring &= (*it).IsColoring();
            if (coloring == false)
            {
                return false;
            }
        }
        return true;
    }

    template<class IdTy>
    void GraphV2V<IdTy>::AddVertex(VertexV2V<IdTy>* addVertex)
    {
        V.resize(V.size() + 1);
        V[V.size() - 1] = *addVertex; // Think about it
        RebuildGraph();
    }
    template<class IdTy>
    void GraphV2V<IdTy>::AddVertex(std::vector<VertexV2V<IdTy>&>& addVertexs)
    {
        for (auto it = addVertexs.begin(); it != addVertexs.end(); it++)
        {
            AddVertex((*it));
        }
    }
    template<class IdTy>
    void GraphV2V<IdTy>::Clear()
    {
        if (V.empty()) return;
        V.clear();
    }

    template<class IdTy>
    VertexV2V<IdTy>* GraphV2V<IdTy>::Dfs(IdTy& id)
    {
        std::vector<VertexV2V<IdTy>*> que;
        std::vector<VertexV2V<IdTy>*> procesed;
        VertexV2V<IdTy>* BefCurrVer = nullptr;
        VertexV2V<IdTy>* currVer = nullptr;
        bool isDeadlock = false;
        ExcepHasVertex();
        currVer = &(*(V.begin()));
        que.push_back(currVer);
        while (!(que.empty()))
        {
            currVer = que.back();
            if (currVer->GetId() == id)
            {
                return currVer;
            }
            procesed.push_back(currVer);
            for (auto it = currVer->Begin(); it != currVer->End(); it++)
            {
                isDeadlock = true;
                if (procesed.end() == std::find(procesed.begin(), procesed.end(), *it))
                {
                    BefCurrVer = currVer;
                    currVer = *it;
                    que.push_back(currVer);
                    isDeadlock = false;
                    break;
                }
            }
            if (isDeadlock == true)
            {
                que.pop_back();
            }
        }
        return nullptr;
    }
    template<class IdTy>
    void GraphV2V<IdTy>::UnVisit()
    {
        for (auto it = Begin(); it != End(); it++)
        {
            (*it).UnVisit();
        }
    }
    template<class IdTy>
    void GraphV2V<IdTy>::RebuildGraph()
    {
        int NOADDIDS = 1;
        // Clear Bad Edges
        for (auto it = V.begin(); it != V.end(); it++)
        {
            (*it).ClearVertexs();
        }
        for (auto it = V.begin(); it != V.end(); it++)
        {
            for (auto it_2 = (*it).BeginIds(); it_2 != (*it).EndIds(); it_2++)
            {
                (*it).AddVertex(\
                    Find((*it_2)), \
                    NOADDIDS);
            }
        }
    }
    //template<class IdTy>
    //GraphV2V<IdTy>& GraphV2V<IdTy>::DijkstrasAlgorithm(VertexV2V<IdTy>& vertex)
    //{
    //    VertexV2V<IdTy> currentVertex;
    //    auto nearestNotVisitVertex = GetNearestNotVisit(vertex);
    //    UnVisit();
    //    // REALIZATION 
    //}
}