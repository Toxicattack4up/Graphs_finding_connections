#include <iostream>
#include <string>
#include "Graph.h"
// Задача: дан граф социальных связей определенного круга людей. 
// Нужно найти все пары знакомств через три рукопожатия.


int main()
{
    setlocale(LC_ALL, "Rus");
   
    Graph g;
    g.add_edge("Олег", "Никита");
    g.add_edge("Никита", "Настя");
    g.add_edge("Настя", "Ваня");
    g.add_edge("Ваня", "Женя");
    g.add_edge("Женя", "Жора");
    g.add_edge("Жора", "Гена");
    g.add_edge("Гена", "Аркадий");
    g.add_edge("Аркадий", "Леонид");
    g.add_edge("Леонид", "Николай");


    g.print_graph();

    g.DFS("Женя", g.visited, 0);
}