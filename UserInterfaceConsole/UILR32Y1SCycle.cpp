#include "pch.h"
/*
*	UILR32Y1SCycle.cpp
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/
#include "UILR32Y1SCycle.h"
#include "../Graph/GraphV2V.h"
/**/

enum class UILR32Y1SMenuCodes
{
	Back,
	Graph,
	Count,
};
std::ostream& operator<<(std::ostream& os, UILR32Y1SMenuCodes Token)
{
	switch (Token)
	{
	case UILR32Y1SMenuCodes::Back:
		os << "Back";
		break;
	case UILR32Y1SMenuCodes::Graph:
		os << "Graph";
		break;
	}
	return os;
}
void UIUILR32Y1SCycle()
{
	bool isCycle = true;
	int up = 0;
	while (isCycle)
	{
		std::cout << "***Выберите структуру данных***\n";
		printOptions<UILR32Y1SMenuCodes>();
		std::cin >> up;
		switch (up)
		{
		case (int)UILR32Y1SMenuCodes::Graph:
			GraphMenu();
			break;
		case (int)MenuCodes::Exit:
			isCycle = (bool)MenuCodes::Exit;
			break;
		default:
			break;
		}
	}
	system("cls");
}
enum class UILR32Y1SGraphMenuCodes
{
	Back,
	VertexsInArrayGraph,
	Count,
};
std::ostream& operator<<(std::ostream& os, UILR32Y1SGraphMenuCodes Token)
{
	switch (Token)
	{
	case UILR32Y1SGraphMenuCodes::Back:
		os << "Back";
		break;
	case UILR32Y1SGraphMenuCodes::VertexsInArrayGraph:
		os << "VertexsInArrayGraph";
		break;
	}
	return os;
}
void GraphMenu()
{
	bool isCycle = true;
	int up = 0;
	while (isCycle)
	{
		std::cout << "***Выберите реализацию структуры данных***\n";
		printOptions<UILR32Y1SGraphMenuCodes>();
		std::cin >> up;
		switch (up)
		{
		case (int)UILR32Y1SGraphMenuCodes::VertexsInArrayGraph:
			СhoiceGraphIdTypeMenu(UILR32Y1SGraphMenuCodes::VertexsInArrayGraph);
			break;
		case (int)MenuCodes::Exit:
			isCycle = (bool)MenuCodes::Exit;
			break;
		default:
			break;
		}
	}
	system("cls");
}
enum class UILR32Y1SGraphIdTypeMenuCodes
{
	Back,
	Integer,
	Count,
};
std::ostream& operator<<(std::ostream& os, UILR32Y1SGraphIdTypeMenuCodes Token)
{
	switch (Token)
	{
	case UILR32Y1SGraphIdTypeMenuCodes::Back:
		os << "Back";
		break;
	case UILR32Y1SGraphIdTypeMenuCodes::Integer:
		os << "Integer";
		break;
	}
	return os;
}
void СhoiceGraphIdTypeMenu(UILR32Y1SGraphMenuCodes graphTy)
{
	bool isCycle = true;
	int up = 0;
	while (isCycle)
	{
		std::cout << "***Выберите тип id вершины графа***\n";
		printOptions<UILR32Y1SGraphIdTypeMenuCodes>();
		std::cin >> up;
		if (graphTy == UILR32Y1SGraphMenuCodes::VertexsInArrayGraph && \
			up == (int)UILR32Y1SGraphIdTypeMenuCodes::Integer)
		{
			WorkWithGraphMenu<  csl::GraphV2V< int >, csl::VertexV2V<int>, int  >();
		}
		else if (up == (int)MenuCodes::Exit)
		{
			isCycle = (bool)MenuCodes::Exit;
		}
		else
		{

		}
		system("cls");
	}
}
enum class UILR32Y1SWorkWithGraphMenuCodes
{
	Back,
	ClearGraph,
	CINGraph,
	COUTGraph,
	COUTGraphWithColor,
	CINGraphFromFile,
	COUTGraphInFile,
	RandomGraph,
	ColoringGraph,
	Count,
};
std::ostream& operator<<(std::ostream& os, UILR32Y1SWorkWithGraphMenuCodes Token)
{
	switch (Token)
	{
	case UILR32Y1SWorkWithGraphMenuCodes::Back:
		os << "Back";
		break;
	case UILR32Y1SWorkWithGraphMenuCodes::ClearGraph:
		os << "Clear graph";
		break;
	case UILR32Y1SWorkWithGraphMenuCodes::CINGraph:
		os << "Cin graph";
		break;
	case UILR32Y1SWorkWithGraphMenuCodes::COUTGraph:
		os << "Cout graph";
		break;
	case UILR32Y1SWorkWithGraphMenuCodes::COUTGraphWithColor:
		os << "Cout graph with color";
		break;
	case UILR32Y1SWorkWithGraphMenuCodes::CINGraphFromFile:
		os << "Cin graph from file";
		break;
	case UILR32Y1SWorkWithGraphMenuCodes::COUTGraphInFile:
		os << "Cout graph in file";
		break;
	case UILR32Y1SWorkWithGraphMenuCodes::RandomGraph:
		os << "Random graph";
		break;
	case UILR32Y1SWorkWithGraphMenuCodes::ColoringGraph:
		os << "Coloring graph";
		break;
	}
	return os;
}
template<class GraphTy>
void outputGraph(GraphTy& g)
{
	for (auto it = g.Begin(); it != g.End(); it++)
	{
		std::cout << (*it).GetId() << ": ";
		for (auto it_2 = (*it).Begin(); it_2 != (*it).End(); it_2++)
		{
			std::cout << (*it_2)->GetId() << "\t";
		}
		std::cout << "\n";
	}
}
template<class GraphTy>
void outputGraphWithColor(GraphTy& g)
{
	HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);
	for (auto it = g.Begin(); it != g.End(); it++)
	{
		printNumberWithColor((*it).GetId(), colour((*it).GetColor()));
		std::cout << ": ";
		for (auto it_2 = (*it).Begin(); it_2 != (*it).End(); it_2++)
		{
			printNumberWithColor((*it_2)->GetId(), colour((*it_2)->GetColor()));
			std::cout << "\t";
		}
		std::cout << "\n";
	}
}
template<class GraphTy>
void outputGraphInFile(GraphTy& g)
{
	std::fstream fs;
	std::string path;
	std::cout << "Введите имя файла: ";
	std::cin >> path;
	path = path + std::string(".txt");
	fs.open(path, std::fstream::out | std::fstream::trunc);
	if (fs.is_open() == false)
	{
		std::cout << "Ошибка открытия файла!\n";
		return;
	}
	else
	{
		std::cout << "Файл открыт!\n";
	}
	fs << g.Size();
	fs << "\n";
	for (auto it = g.Begin(); it != g.End(); it++)
	{
		fs << (*it).GetId();
		fs << "\n";
		fs << (*it).CountOfEdges();
		fs << "\n";
		for (auto it_2 = (*it).Begin(); it_2 != (*it).End(); it_2++)
		{
			fs << (*it_2)->GetId() << "\n";
		}
	}
	fs.close();
	std::cout << "Граф записан в файл!\n";
}
template<class VertexTy, class IdTy, class GraphTy>
void inputGraph(GraphTy& g)
{
	g.Clear();
	int vertexsCount = 0, AdjacentVertexCount = 0;
	IdTy currentId;
	VertexTy currentVertex;
	std::cout << "Введите количество вершин: ";
	std::cin >> vertexsCount;
	for (int i = 1; i <= vertexsCount; i++)
	{
		std::cout << "Введите id " << i << "-й вершины: ";
		std::cin >> currentId;
		std::cout << "\nВведите количество смежных вершин: ";
		std::cin >> AdjacentVertexCount;
		std::cout << "\n";
		currentVertex.Clear();
		currentVertex.SetId(currentId);
		for (int j = 1; j <= AdjacentVertexCount; j++)
		{
			std::cout << "Введите id " << j << "-й смежной ей вершины: ";
			std::cin >> currentId;
			currentVertex.AddVertexIds(currentId);
			std::cout << "\n";
		}
		g.AddVertex(&currentVertex);
	}
}
template<class VertexTy, class IdTy, class GraphTy>
void inputGraphFromFile(GraphTy& g)
{
	std::fstream fs;
	std::string path;
	std::cout << "Введите имя файла: ";
	std::cin >> path;
	path = path + std::string(".txt");
	fs.open(path);
	if (fs.is_open() == false)
	{
		std::cout << "Ошибка открытия файла!\n";
		return;
	}
	else
	{
		std::cout << "Файл открыт!\n";
	}
	g.Clear();
	int vertexsCount = 0, AdjacentVertexCount = 0;
	IdTy currentId;
	VertexTy currentVertex;
	fs >> vertexsCount;
	for (int i = 1; i <= vertexsCount; i++)
	{
		fs >> currentId;
		fs >> AdjacentVertexCount;
		currentVertex.Clear();
		currentVertex.SetId(currentId);
		for (int j = 1; j <= AdjacentVertexCount; j++)
		{
			fs >> currentId;
			currentVertex.AddVertexIds(currentId);
		}
		g.AddVertex(&currentVertex);
	}
	std::cout << "Граф считан из файла!\n";
}
template<class GraphTy, class IdTy>
GraphTy&& RandomGraph()
{
	int vCount = 0, eCount = 0;
	std::cout << "Введите количество вершин: ";
	std::cin >> vCount;
	std::cout << "Введите количество рёбер большее, чем количество вершин: ";
	std::cin >> eCount;
	if (eCount < vCount)
	{
		return std::move(*(new GraphTy()));
	}
	return RandomGraph<GraphTy, IdTy>(vCount, eCount, csl::GraphTypeConnect::ConnectedGraph, csl::ConnectivityComponent::One);
}
template<class GraphTy>
GraphTy ColoringGraph(GraphTy& g)
{
	if (g.Size() > 10)
	{
		std::cout << "Граф слишком большой, в нём " << g.Size() << " вершин. Можно разукрасить граф с 10-ю и менее вершинами\n";
		return g;
	}
	return std::move(g.Coloring());
}
template<class GraphTy, class VertexTy, class IdTy>
void WorkWithGraphMenu()
{
	bool isCycle = true;
	auto* G = new GraphTy();
	while (isCycle)
	{
		std::cout << "***Выберите операцию***\n";
		printOptions<UILR32Y1SWorkWithGraphMenuCodes>();
		int up = 0;
		std::cin >> up;
		switch (up)
		{
		case (int)UILR32Y1SWorkWithGraphMenuCodes::CINGraph:
			inputGraph<VertexTy, IdTy>(*G);
			break;
		case (int)UILR32Y1SWorkWithGraphMenuCodes::COUTGraph:
			outputGraph(*G);
			break;
		case (int)UILR32Y1SWorkWithGraphMenuCodes::COUTGraphWithColor:
			outputGraphWithColor(*G);
			break;
		case (int)UILR32Y1SWorkWithGraphMenuCodes::CINGraphFromFile:
			inputGraphFromFile<VertexTy, IdTy>(*G);
			break;
		case (int)UILR32Y1SWorkWithGraphMenuCodes::COUTGraphInFile:
			outputGraphInFile(*G);
			break;
		case (int)UILR32Y1SWorkWithGraphMenuCodes::RandomGraph:
			*G = RandomGraph<GraphTy, IdTy>();
			break;
		case (int)UILR32Y1SWorkWithGraphMenuCodes::ClearGraph:
			G->Clear();
			break;
		case (int)UILR32Y1SWorkWithGraphMenuCodes::ColoringGraph:
			*G = ColoringGraph(*G);
			break;
		case (int)MenuCodes::Exit:
			G->Clear();
			isCycle = (bool)MenuCodes::Exit;
			break;
		default:
			break;
		}
	}
}
