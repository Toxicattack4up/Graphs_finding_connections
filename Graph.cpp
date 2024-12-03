#include <iostream>
#include <unordered_set>
#include "Graph.h"

void Graph::add_edge(const std::string& person1, const std::string& person2)
{
	// “ут добавл€етс€ св€зь между персонами, что позвол€ет отследить кто с кем общаетс€
	list[person1].push_back(person2);
	list[person2].push_back(person1);
}

void Graph::print_graph() const
{
	std::cout << "Social graph: " << std::endl;
	for (const auto& entry : list)
	{
		// person €вл€етс€ ключом, то есть именем человека
		const std::string& person = entry.first;
		// friends €вл€етс€ значением, то есть списком друзей
		const std::vector<std::string>& friends = entry.second;

		std::cout << person << ": ";
		// ¬ этом цикле мы перебираем всех друзей, то есть выводим св€зи
		for (const auto& friend_name : friends)
		{
			std::cout << friend_name << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::DFS(const std::string& person, std::unordered_set<std::string>& visited, int counter)
{

	// ≈сли данна€ вершина была посещена, то ничего не делаем
	if (visited.count(person))
	{
		return;
	}
	// ≈сли вершина не была посещена, то помечаем еЄ как посещенную
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
		std::cout << "Ётот персонаж не знаком с начальным: " << person << std::endl;
	}
}

