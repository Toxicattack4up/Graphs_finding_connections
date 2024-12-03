#include <iostream>
#include <unordered_set>
#include "Graph.h"

void Graph::add_edge(const std::string& person1, const std::string& person2)
{
	// Тут добавляется связь между персонами, что позволяет отследить кто с кем общается
	list[person1].push_back(person2);
	list[person2].push_back(person1);
}

void Graph::print_graph() const
{
	std::cout << "Social graph: " << std::endl;
	for (const auto& entry : list)
	{
		// person является ключом, то есть именем человека
		const std::string& person = entry.first;
		// friends является значением, то есть списком друзей
		const std::vector<std::string>& friends = entry.second;

		std::cout << person << ": ";
		// В этом цикле мы перебираем всех друзей, то есть выводим связи
		for (const auto& friend_name : friends)
		{
			std::cout << friend_name << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::DFS(const std::string& person, std::unordered_set<std::string>& visited, int counter)
{

	// Если данная вершина была посещена, то ничего не делаем
	if (visited.count(person))
	{
		return;
	}
	// Если вершина не была посещена, то помечаем её как посещенную
	visited.insert(person);

	// Если счетчик ещё не дошел до 3 рукопожатий, то продолжаем рекурсивно вызывать функцию и проверять
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
		// Вывод тех, кто не знаком с искомым человеком
		std::cout << std::endl;
		std::cout << "Этот персонаж не знаком с начальным: " << person << std::endl;
	}
}

