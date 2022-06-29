#pragma once
#include <list>
enum Direction {
	Left,
	Right,
	Undirected,
};
struct Vertex {
	int id;
};
struct Edge {
	int vl, vr, mas;
	Direction d;
};
struct Graph {
	std::list<Vertex> V;
	std::list<Edge> E;
};