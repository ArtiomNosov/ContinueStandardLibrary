#pragma once

#include "pch.h"

/*
*	RandomGraphV2V.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/
#include "Graph.h"
#include "VertexV2V.h"
#include "EdgeV2V.h"
namespace csl 
{
	template<class IdTy>
	class GraphV2V;
}
/**/
// TODO: —делать функцию св¤зки вершин
// TODO: —делать дораспределение рЄбер если остаютс¤ лишние

// For RandomGraph()
template<class T>
bool uniqueAddToStdVector(std::vector<T>& v, T& item);
void FillVectorRandomNumbers(std::vector<int>& v, int low, int high, int count);
void FillVectorUniqueRandomNumbers(std::vector<int>& v, int low, int high, int count);
template<class VertexTy>
void interconnectionVertexs(VertexTy* v1, VertexTy* v2, csl::ConnectivityComponent cc);
template<class GraphTy, class idTy>
GraphTy&& RandomGraph(int countOfVertexs, int countOfEdges, csl::GraphTypeConnect gtc, csl::ConnectivityComponent cc);
