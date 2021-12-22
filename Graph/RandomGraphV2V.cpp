#include "RandomGraphV2V.h"
/*
*	RandomGraphV2V.cpp
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/
/**/
// TODO: —делать функцию св¤зки вершин
// TODO: —делать дораспределение рЄбер если остаютс¤ лишние
#define YESADD false
#define DONTADD true

template<class T>
bool uniqueAddToStdVector(std::vector<T>& v, T& item)
{
    if (v.end() == std::find(v.begin(), v.end(), item))
    {
        v.push_back(item);
        return YESADD;
    }
    else
    {
        return DONTADD;
    }
}
void FillVectorRandomNumbers(std::vector<int>& v, int low, int high, int count)
{
    int rn;
    for (int i = 0; i < count; i++)
    {
        rn = low + (std::rand() % (high - low));
        v.push_back(rn);
    }
}
void FillVectorUniqueRandomNumbers(std::vector<int>& v, int low, int high, int count)
{
    int rn;
    size_t beginSize = v.size();
    if (high - low < count)
    {
        count = high - low;
    }
    while (v.size() - beginSize != count)
    {
        rn = low + (std::rand() % (high - low));
        uniqueAddToStdVector(v, rn);
    }
}

template<class VertexTy>
void interconnectionVertexs(VertexTy* v1, VertexTy* v2, csl::ConnectivityComponent cc)
{
    v1->AddVertex(v2);
    if (cc == csl::ConnectivityComponent::One)
    {
        v2->AddVertex(v1);
    }
}
template<class GraphTy, class idTy>
GraphTy&& RandomGraph(int countOfVertexs, int countOfEdges, \
    csl::GraphTypeConnect gtc, \
    csl::ConnectivityComponent cc)
{
    if (countOfVertexs <= 0 || countOfEdges <= 0) throw std::exception\
        ("countOfVertexs <= 0 || countOfEdges <= 0 in RandomGraph");
    if (cc == csl::ConnectivityComponent::One)
    {
        countOfEdges *= 2;
    }
    std::time_t t;
    std::srand(std::time(&t));
    auto* G = new csl::GraphV2V<int>();
    csl::VertexV2V<int>* p_1 = nullptr, * p_2 = nullptr;
    csl::VertexV2V<int>* currentVertexInGraph = nullptr;
    int numberOfAddingEdges = 0, rn = 0;
    int countOfAddEdges = 0, NumberEdgesLeftToInsert = 0, NumberVertexLeftToInsert = 0, countOfAddVertexs = 0;
    std::vector<int> uniqueInts;
    for (int i = 1; i <= countOfVertexs; i++)
    {
        p_1 = new csl::VertexV2V<int>(i);
        G->AddVertex(p_1);
        // Adding edges
        numberOfAddingEdges = std::rand() % i + 1;
        if (i == 1) { numberOfAddingEdges = 0; };
        // Fill vector random numbers
        uniqueInts.clear();
        FillVectorUniqueRandomNumbers(uniqueInts, 1, i, numberOfAddingEdges);
        currentVertexInGraph = G->Find(p_1->GetId());
        for (int j = 0; j < uniqueInts.size(); j++)
        {
            p_2 = G->Find(uniqueInts[j]);

            currentVertexInGraph->AddVertex(p_2);
            if (cc == csl::ConnectivityComponent::One)
            {
                p_2->AddVertex(currentVertexInGraph);
            }

            countOfAddEdges++;
            NumberEdgesLeftToInsert = countOfEdges - countOfAddEdges;
            NumberVertexLeftToInsert = countOfVertexs - i;
            if (gtc == csl::GraphTypeConnect::ConnectedGraph && NumberEdgesLeftToInsert <= NumberVertexLeftToInsert)
            {
                i = countOfVertexs + 1; // just for end this for 
                break;
            }
        }
        countOfAddVertexs++;
    }
    if (gtc == csl::GraphTypeConnect::ConnectedGraph)
    {
        for (int i = countOfAddVertexs + 1; i <= countOfVertexs; i++)
        {
            p_1 = new csl::VertexV2V<int>(i);
            G->AddVertex(p_1);
            // Adding edges
            numberOfAddingEdges = 1; // Our vertexs will have only one edge
            rn = std::rand() % countOfAddVertexs + 1;
            currentVertexInGraph = G->Find(p_1->GetId());
            p_2 = G->Find(rn);
            currentVertexInGraph->AddVertex(p_2);
            if (cc == csl::ConnectivityComponent::One)
            {
                p_2->AddVertex(currentVertexInGraph);
            }
            countOfAddVertexs++;
            countOfAddEdges++;
        }
    }
    return std::move(*G);
}
