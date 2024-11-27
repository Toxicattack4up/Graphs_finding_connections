#pragma once
#define SIZE 10

class Graph
{
public:
	Graph();
	
	// Добавление вершины
	void addVetrex(int vnumber);

	// Добавление ребра
	void addEdge(int v1, int v2, int weight);

	// Удаление вершины
	void delVertex(int vnumber);

	// Удаление ребра
	void delEdge(int v1, int v2);

private:
	// Проверка существования ребра 
	bool edgeExists(int v1, int v2);

	// Проверка существования вершины
	bool vertexExists(int v);

	// Матрица
	int matrix[SIZE][SIZE];

	// Хранилище вершин
	int vertexes[SIZE];

	// Количество добавленых вершин
	int vertexCount;
};