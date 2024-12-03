#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>


class Graph
{
private:
	// ������������� �����
	// ����� ��� ����/��������, ��� ����� ����� ����� ��� ������ � ����������� ����� ������
	std::unordered_map<std::string, std::vector<std::string>> list;
	

	int counter = 0;

public:
	// ��������� ��� ������������ ���������� �� ����� �������
	std::unordered_set<std::string> visited;

	// ��������� ����� ����� ���������
	void add_edge(const std::string& person1, const std::string& person2);

	// ����� �������� ���� �� �����
	void print_graph() const;

	// ������ ���������� �������� ������ � ��������
	void DFS(const std::string& person, std::unordered_set<std::string>& visited, int counter);
};