#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>


class Graph
{
private:
	// Представление графа
	// Имеет вид ключ/значение, так будет лучше всего для работы с отношениями между людьми
	std::unordered_map<std::string, std::vector<std::string>> list;
	

	int counter = 0;

public:
	// Множество для отслеживания посещенных во время обходаы
	std::unordered_set<std::string> visited;

	// Добавляем связь между вершинами
	void add_edge(const std::string& person1, const std::string& person2);

	// Будем выводить граф на экран
	void print_graph() const;

	// Слегка измененный алгоритм поиска в гллубину
	void DFS(const std::string& person, std::unordered_set<std::string>& visited, int counter);
};