#pragma once
#define SIZE 10

class Graph
{
public:
	Graph();
	
	// ���������� �������
	void addVetrex(int vnumber);

	// ���������� �����
	void addEdge(Human *a, Human *p, int weight);

	// �������� �������
	void delVertex(int vnumber);

	// �������� �����
	void delEdge(int v1, int v2);

private:
	// �������� ������������� ����� 
	bool edgeExists(int v1, int v2);

	// �������� ������������� �������
	bool vertexExists(int v);

	// �������
	std::string matrix[SIZE][SIZE];

	// ��������� ������
	int vertexes[SIZE];

	// ���������� ���������� ������
	int vertexCount;
};