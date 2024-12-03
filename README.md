# Social Graph — Поиск знакомств через три рукопожатия
Этот проект предлагает оригинальное решение задачи поиска в глубину, применяемое для анализа социальных сетей и моделирования взаимосвязей. Наша программа способна выявлять всех людей, находящихся на расстоянии трех рукопожатий от заданного, что открывает новые горизонты в понимании сложных социальных структур.

## 📋 Описание задачи
### Задача:
Представьте себе граф, в котором каждая вершина соответствует человеку, а каждое ребро — связи между ними, например, дружбе. Наша цель — найти всех людей, находящихся на расстоянии трех рукопожатий от заданного.

Пример
Олег знаком с Никитой
Никита знаком с Настей
Настя знакома с Ваней и так далее

Если задать в качестве отправной точки Олега, программа выведет всех людей, с которыми он связан через три рукопожатия (включительно).

# 🚀 Как работает программа
## Основные этапы
### Создание графа социальных связей.
Граф формируется с использованием структуры unordered_map, где ключи представляют имена людей, а значения — списки их друзей.

### Добавление связей между людьми.
Метод add_edge позволяет легко добавлять ребра между вершинами графа, создавая необходимые связи.

### Обход графа.
Алгоритм поиска в глубину (DFS) позволяет обойти граф, начиная с заданного человека, и учитывать только тех, кто находится на расстоянии не более трех рукопожатий.

### Вывод результатов.
Если ограничение в три рукопожатия достигнуто, программа завершает обход текущей ветви графа и выводит человека, с которого прервался поиск.

# 🛠️ Основные компоненты
## Класс Graph
Этот класс содержит все необходимые функции для работы с графом. Он определяет:

Структуру графа (unordered_map<std::string, std::vector>)

Множество посещенных вершин (unordered_set)

Методы для добавления связей, отображения графа и выполнения поиска в глубину

## Методы класса
### Назначение:
Этот метод добавляет двустороннюю связь (ребро) между двумя людьми.

Пример работы:
g.add_edge("Олег", "Никита");

После вызова этого метода Олег становится другом Никиты, и наоборот.

Назначение:
Выводит граф в удобном формате, отображая список людей и их друзей.

### Пример вывода:

makefileКопировать код Social graph:
Олег: Никита
Никита: Олег Настя
Настя: Никита Ваня
Ваня: Настя Женя
...

Назначение:
Реализует алгоритм поиска в глубину для обхода графа.

Как работает:

Проверяет, посещена ли текущая вершина (person):
   – Если уже посещена, функция завершается.
   – Если нет, помечает ее как посещенную.

Увеличивает счетчик глубины (counter).

Если счетчик превышает 3, выводит сообщение о прекращении поиска и завершает ветку обхода.

Рекурсивно вызывает себя для всех друзей текущей вершины, если они еще не посещены.

Пример вызова:
g.DFS("Олег", g.visited, 0);

# 📦 Как использовать
## Создание экземпляра графа
### Создайте экземпляр графа:
Graph g;

### Добавление связей между людьми
Добавьте связи между людьми:

g.add_edge("Олег", "Никита");

g.add_edge("Никита", "Настя");

g.add_edge("Настя", "Ваня");


Вывод графа на экран (по желанию)
Выведите граф на экран (по желанию):

g.print_graph();

Запуск поиска для конкретного человека
Запустите поиск для конкретного человека:

g.DFS("Олег", g.visited, 0);

# 🔍 Пример выполнения
Входные данные
g.add_edge("Олег", "Никита");

g.add_edge("Никита", "Настя");

g.add_edge("Настя", "Ваня");

g.add_edge("Ваня", "Женя");

g.add_edge("Женя", "Жора");

## Вывод программы
Social graph:
Олег: Никита
Никита: Олег Настя
Настя: Никита Ваня
Ваня: Настя Женя
Женя: Ваня Жора

Этот персонаж не знаком с начальным: Женя
Этот персонаж не знаком с начальным: Жора

# 💡 Идеи для доработки
## Гибкость в настройке глубины поиска
Добавьте параметр для задания максимального числа рукопожатий (например, не только 3, но и 4 или 5).

## Визуализация графа
Используйте библиотеки вроде Graphviz для построения графического отображения социальных связей.

## Обратный поиск
Реализуйте возможность поиска от конечной точки к начальной (поиск в ширину).

## Хранение данных
Сохраните граф в файл и считывайте его при необходимости.

# 📚 Зависимости
## Компилятор с поддержкой C++11 и выше.

### Стандартные библиотеки C++:

<unordered_map>
<unordered_set>
<vector>
<string>
<iostream>
