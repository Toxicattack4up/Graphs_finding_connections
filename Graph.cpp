#include <iostream>
#include <unordered_set>
#include "Graph.h"

void Graph::add_edge(const std::string& person1, const std::string& person2)
{
	// ��� ����������� ����� ����� ���������, ��� ��������� ��������� ��� � ��� ��������
	list[person1].push_back(person2);
	list[person2].push_back(person1);
}

void Graph::print_graph() const
{
	std::cout << "Social graph: " << std::endl;
	for (const auto& entry : list)
	{
		// person �������� ������, �� ���� ������ ��������
		const std::string& person = entry.first;
		// friends �������� ���������, �� ���� ������� ������
		const std::vector<std::string>& friends = entry.second;

		std::cout << person << ": ";
		// � ���� ����� �� ���������� ���� ������, �� ���� ������� �����
		for (const auto& friend_name : friends)
		{
			std::cout << friend_name << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::DFS(const std::string& person, std::unordered_set<std::string>& visited, int counter)
{

	// ���� ������ ������� ���� ��������, �� ������ �� ������
	if (visited.count(person))
	{
		return;
	}
	// ���� ������� �� ���� ��������, �� �������� � ��� ����������
	visited.insert(person);

	if (counter <= 3)
	{
		counter++;
		for (const auto& friend_name : list[person])
		{
			if (!visited.count(friend_name))
			{
				DFS(friend_name, visited, counter);
			}
		}
	}
	else
	{
		std::cout << std::endl;
		std::cout << "���� �������� �� ������ � ���������: " << person << std::endl;
	}
}

