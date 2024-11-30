#include <iostream>
#include <string>
#include <unordered_map>
#include "Graph.h"
#include "Graphs_finding_connections.cpp"

Graph::Graph()
{
	
}

// Добавление вершины
void Graph::addVetrex(int vnumber)
{
	vertexes[vertexCount] = vnumber;
	vertexCount++;
}

// Добавление ребра
void Graph::addEdge(Human* a, Human* p, int weight)
{
	if (a == nullptr || p == nullptr)
	{
		std::cerr << "Ошибка: один из указателей равен nullptr";
		return;
	}

	matrix[a->name][p->name] = weight;
	matrix[p->name][a->name] = weight;
}

// Удаление вершины
void Graph::delVertex(int vnumber)
{
	
}

// Удаление ребра
void Graph::delEdge(int v1, int v2)
{
}

// Проверка существования ребра
bool Graph::edgeExists(int v1, int v2)
{
	return matrix[v1][v2] > 0;
}

// Проверка существования вершины
bool Graph::vertexExists(int v)
{
	for (int i = 0; i < vertexCount; i++)
	{
		if (vertexes[i] == v)
		{
			return true;
		}
	}
	return false;
}