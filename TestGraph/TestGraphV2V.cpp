#include "pch.h"
#include "../Graph/GraphV2V.h"

#define RANDOMTESTCASE 100
// Big graph
#define MANYVERTEXS 250
#define MANYEDGES 1000
// Small graph
#define FEWYVERTEXS 4
#define FEWEDGES 5



csl::GraphV2V<int>&& PetersenGraph()
{
	static csl::VertexV2V<int> v1(1);
	static csl::VertexV2V<int> v2(2);
	static csl::VertexV2V<int> v3(3);
	static csl::VertexV2V<int> v4(4);
	static csl::VertexV2V<int> v5(5);
	static csl::VertexV2V<int> v6(6);
	static csl::VertexV2V<int> v7(7);
	static csl::VertexV2V<int> v8(8);
	static csl::VertexV2V<int> v9(9);
	static csl::VertexV2V<int> v10(10);

	static std::vector <csl::VertexV2V<int>*> vertexs_1{ &v2, &v6, &v5 };
	static std::vector <csl::VertexV2V<int>*> vertexs_2{ &v1, &v7, &v3 };
	static std::vector <csl::VertexV2V<int>*> vertexs_3{ &v2, &v8, &v4 };
	static std::vector <csl::VertexV2V<int>*> vertexs_4{ &v3, &v9, &v5 };
	static std::vector <csl::VertexV2V<int>*> vertexs_5{ &v4, &v10, &v1 };
	static std::vector <csl::VertexV2V<int>*> vertexs_6{ &v1, &v8, &v9 };
	static std::vector <csl::VertexV2V<int>*> vertexs_7{ &v2, &v9, &v10 };
	static std::vector <csl::VertexV2V<int>*> vertexs_8{ &v3, &v10, &v6 };
	static std::vector <csl::VertexV2V<int>*> vertexs_9{ &v4, &v6, &v7 };
	static std::vector <csl::VertexV2V<int>*> vertexs_10{ &v5, &v7, &v8 };

	static bool SET_VERTEXS = false;

	if (!SET_VERTEXS) {
		v1.AddVertex(vertexs_1);
		v2.AddVertex(vertexs_2);
		v3.AddVertex(vertexs_3);
		v4.AddVertex(vertexs_4);
		v5.AddVertex(vertexs_5);
		v6.AddVertex(vertexs_6);
		v7.AddVertex(vertexs_7);
		v8.AddVertex(vertexs_8);
		v9.AddVertex(vertexs_9);
		v10.AddVertex(vertexs_10);
		SET_VERTEXS = true;
	}

	std::map<int, csl::VertexV2V<int>> vertexs{ {1, v1} , {2, v2}, {3, v3}, {4, v4},{5, v5},
		{6, v6},{7, v7},{8, v8},{9, v9},{10, v10} };

	return std::move(*(new csl::GraphV2V<int>(vertexs)));
}

class GraphV2VPetersenTest : public ::testing::Test {
protected:
	void SetUp() override {
		G = PetersenGraph();
	}

	// void TearDown() override {}

	csl::GraphV2V<int> G;
};
class GraphV2VRandomGraphTest : public ::testing::Test {
protected:
	virtual void SetUp() override {
	}
public:
	virtual void CreateGraph(int countVertexs, int countEdges)
	{
		G = RandomGraph<csl::GraphV2V<int>, int>(countVertexs, countEdges, \
			csl::GraphTypeConnect::ConnectedGraph, csl::ConnectivityComponent::One);
	}
public:
	template<class Arg_1, class Arg_2>
	void RebuildGraph(Arg_1 arg_1, Arg_2 arg_2)
	{
		CreateGreaph(arg_1, arg_2);
	}
	// void TearDown() override {}

	csl::GraphV2V<int> G;
};
class GraphV2VBigRandomGraphTest : public GraphV2VRandomGraphTest {
protected:
	void SetUp() override {
		CreateGraph(MANYVERTEXS, MANYEDGES);
	}
public:
	void RebuildGraph()
	{
		CreateGraph(MANYVERTEXS, MANYEDGES);
	}
	csl::GraphV2V<int> G;
};
class GraphV2VSmallRandomGraphTest : public GraphV2VRandomGraphTest {
protected:
	void SetUp() override {
		CreateGraph(FEWYVERTEXS, FEWEDGES);
	}
public:
	void RebuildGraph()
	{
		CreateGraph(FEWYVERTEXS, FEWEDGES);
	}
	csl::GraphV2V<int> G;
};
TEST(TestGraphV2V, PetersenGraphCreate) {
	auto a = PetersenGraph();
	EXPECT_EQ(a.isColoring(), false);
}

TEST(TestGraphV2VAdditionFunctions, RandomGraphConnectedCreate) {
	auto a = RandomGraph<csl::GraphV2V<int>, int>(FEWYVERTEXS, FEWEDGES, \
		csl::GraphTypeConnect::ConnectedGraph, csl::ConnectivityComponent::One);
	EXPECT_EQ(a.isColoring(), false);
	a = a.Coloring();
	EXPECT_TRUE(a.isColoring());
}

TEST(TestGraphV2VAdditionFunctions, RandomGraphConnectedCreateMany) {
	auto a = RandomGraph<csl::GraphV2V<int>, int>(MANYVERTEXS, MANYEDGES, \
		csl::GraphTypeConnect::ConnectedGraph, csl::ConnectivityComponent::One);
	EXPECT_EQ(a.isColoring(), false);
}
// TestIsColoring
TEST_F(GraphV2VPetersenTest, TestIsColoring) {
	EXPECT_EQ(G.isColoring(), false);
}

TEST_F(GraphV2VPetersenTest, TestColoring) {
	EXPECT_EQ(G.isColoring(), false);
	G = G.Coloring();
	EXPECT_TRUE(G.isColoring());
}
// TestDfsCopy
TEST_F(GraphV2VPetersenTest, TestDfsCopy) {
	for (auto it = G.Begin(); it != G.End(); it++)
	{
		EXPECT_TRUE((*it).GetId() == (G.DfsCopy((*it).GetId())).GetId());
	}
}

TEST_F(GraphV2VSmallRandomGraphTest, TestDfsCopy) {
	for (int i = 0; i < RANDOMTESTCASE; i++)
	{
		for (auto it = G.Begin(); it != G.End(); it++)
		{
			EXPECT_TRUE((*it).GetId() == (G.DfsCopy((*it).GetId())).GetId());
		}
		RebuildGraph();
	}
}

TEST_F(GraphV2VBigRandomGraphTest, TestDfsCopy) {
	for (auto it = G.Begin(); it != G.End(); it++)
	{
		EXPECT_TRUE((*it).GetId() == (G.DfsCopy((*it).GetId())).GetId());
	}
}