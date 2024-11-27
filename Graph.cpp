#include "Graph.h"

Graph::Graph()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			matrix[i][j] = 0;
		}
		vertexCount++;
	}
}

// ���������� �������
void Graph::addVetrex(int vnumber)
{
	vertexes[vertexCount] = vnumber;
	vertexCount++;
}

// ���������� �����
void Graph::addEdge(int v1, int v2, int weight)
{
	matrix[v1][v2] = weight;
	matrix[v2][v1] = weight;
}

// �������� �������
void Graph::delVertex(int vnumber)
{
	
}

// �������� �����
void Graph::delEdge(int v1, int v2)
{
}

// �������� ������������� �����
bool Graph::edgeExists(int v1, int v2)
{
	return matrix[v1][v2] > 0;
}

// �������� ������������� �������
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