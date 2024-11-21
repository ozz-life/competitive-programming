// В задачах с графами в олимпиадном программировании могут быть полезны следующие методы:
// Проверка наличия ребра: Позволяет проверить, существует ли ребро между двумя вершинами.
// bool hasEdge(int vertex1, int vertex2) const;
// Удаление ребра: Позволяет удалить ребро между двумя вершинами.
// void removeEdge(int vertex1, int vertex2);
// Поиск соседей вершины: Возвращает список соседних вершин для данной вершины.
// std::vector<int> getNeighbors(int vertex) const;
// Поиск всех путей между двумя вершинами: Находит все пути между двумя заданными вершинами в графе.
// std::vector<std::vector<int>> findAllPaths(int startVertex, int endVertex) const;
// Поиск кратчайшего пути (алгоритм Дейкстры, алгоритм Беллмана-Форда или другие): Находит кратчайший путь между двумя вершинами или находит кратчайшие пути от одной вершины до всех остальных вершин в графе.
// std::vector<int> findShortestPath(int startVertex, int endVertex) const;
// std::vector<int> findShortestPathsFrom(int startVertex) const;
// Обход графа в глубину (DFS): Позволяет обойти все вершины графа, начиная с заданной вершины.
// void depthFirstSearch(int startVertex) const;
// Обход графа в ширину (BFS): Позволяет обойти все вершины графа, начиная с заданной вершины.
// void breadthFirstSearch(int startVertex) const;
// Проверка связности графа: Позволяет определить, является ли граф связным (каждая пара вершин имеет путь между ними).
// bool isConnected() const;
// Проверка наличия цикла: Позволяет определить, содержит ли граф циклы.
// bool hasCycle() const;
// Поиск компонент связности: Находит все компоненты связности в графе.
// std::vector<std::vector<int>> findConnectedComponents() const;
// Проверка наличия пути между двумя вершинами: Позволяет определить, существует ли путь между двумя заданными вершинами в графе.
// bool hasPath(int startVertex, int endVertex) const;
// Проверка наличия эйлерова цикла: Позволяет определить, содержит ли граф эйлеров цикл (проходящий по всем ребрам графа ровно один раз).
// bool hasEulerianCycle() const;
// Проверка наличия гамильтонова цикла: Позволяет определить, содержит ли граф гамильтонов цикл (проходящий по всем вершинам графа ровно один раз).
// bool hasHamiltonianCycle() const;
// Поиск минимального остовного дерева (алгоритм Прима, алгоритм Крускала или другие): Находит минимальное остовное дерево в связном неориентированном графе.
// std::vector<std::pair<int, int>> findMinimumSpanningTree() const;
// Поиск сильно связных компонент: Находит все сильно связные компоненты в ориентированном графе.
// std::vector<std::vector<int>> findStronglyConnectedComponents() const;

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_set>

class Graph
{
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyList;

public:
    Graph(int vertices) : numVertices(vertices), adjacencyList(vertices) {}

    void addEdge(int source, int destination)
    {
        adjacencyList[source].push_back(destination);
    }

    void printGraph() const
    {
        for (int i = 0; i < numVertices; ++i)
        {
            std::cout << "Vertex " << i + 1 << ": ";
            for (int neighbor : adjacencyList[i])
            {
                std::cout << neighbor + 1 << " ";
            }
            std::cout << std::endl;
        }
    }

    int getDegree(int vertex) const
    {
        return adjacencyList[vertex].size();
    }

    bool hasCycle() const
    {
        std::vector<bool> visited(numVertices, false);
        std::vector<bool> recursionStack(numVertices, false);

        for (int i = 0; i < numVertices; ++i)
        {
            if (hasCycleUtil(i, visited, recursionStack))
            {
                return true;
            }
        }

        return false;
    }

    bool hasPath(int startVertex, int endVertex) const
    {
        std::vector<bool> visited(numVertices, false);
        return hasPathUtil(startVertex, endVertex, visited);
    }

    std::vector<std::vector<int>> findConnectedComponents() const
    {
        std::vector<bool> visited(numVertices, false);
        std::vector<std::vector<int>> connectedComponents;

        for (int i = 0; i < numVertices; ++i)
        {
            if (!visited[i])
            {
                std::vector<int> component;
                dfs(i, visited, component);
                connectedComponents.push_back(component);
            }
        }

        return connectedComponents;
    }

    bool hasEulerianCycle() const
    {
        if (!isConnected())
        {
            return false;
        }

        for (int i = 0; i < numVertices; ++i)
        {
            if (adjacencyList[i].size() % 2 != 0)
            {
                return false;
            }
        }

        return true;
    }

    bool hasHamiltonianCycle() const
    {
        std::vector<int> path;
        std::vector<bool> visited(numVertices, false);
        return hamiltonianCycleUtil(0, visited, path, 0);
    }

    std::vector<std::pair<int, int>> findMinimumSpanningTree() const
    {
        std::vector<bool> visited(numVertices, false);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
        std::vector<std::pair<int, int>> minimumSpanningTree;

        minHeap.push(std::make_pair(0, 0));

        while (!minHeap.empty())
        {
            std::pair<int, int> current = minHeap.top();
            minHeap.pop();

            int vertex = current.second;
            int weight = current.first;

            if (visited[vertex])
            {
                continue;
            }

            visited[vertex] = true;
            minimumSpanningTree.push_back(std::make_pair(vertex, weight));

            for (int neighbor : adjacencyList[vertex])
            {
                if (!visited[neighbor])
                {
                    minHeap.push(std::make_pair(1, neighbor));
                }
            }
        }
    }

    return minimumSpanningTree;
}

std::vector<int>
topologicalSort() const
{
    std::vector<int> result;
    std::vector<bool> visited(numVertices, false);
    std::stack<int> stack;

    for (int i = 0; i < numVertices; ++i)
    {
        if (!visited[i])
        {
            topologicalSortUtil(i, visited, stack);
        }
    }

    while (!stack.empty())
    {
        result.push_back(stack.top());
        stack.pop();
    }

    return result;
}

bool isBipartite() const
{
    std::vector<int> color(numVertices, -1);

    for (int i = 0; i < numVertices; ++i)
    {
        if (color[i] == -1 && !isBipartiteUtil(i, color))
        {
            return false;
        }
    }

    return true;
}

bool isTree() const
{
    std::vector<bool> visited(numVertices, false);

    if (hasCycleUtil(0, visited, -1))
    {
        return false;
    }

    for (int i = 0; i < numVertices; ++i)
    {
        if (!visited[i])
        {
            return false;
        }
    }

    return true;
}

private:
bool hasCycleUtil(int vertex, std::vector<bool> &visited, std::vector<bool> &recursionStack) const
{
    visited[vertex] = true;
    recursionStack[vertex] = true;
    for (int neighbor : adjacencyList[vertex])
    {
        if (!visited[neighbor] && hasCycleUtil(neighbor, visited, recursionStack))
        {
            return true;
        }
        else if (recursionStack[neighbor])
        {
            return true;
        }
    }

    recursionStack[vertex] = false;
    return false;
}

bool hasPathUtil(int startVertex, int endVertex, std::vector<bool> &visited) const
{
    if (startVertex == endVertex)
    {
        return true;
    }

    visited[startVertex] = true;

    for (int neighbor : adjacencyList[startVertex])
    {
        if (!visited[neighbor] && hasPathUtil(neighbor, endVertex, visited))
        {
            return true;
        }
    }

    return false;
}

void dfs(int vertex, std::vector<bool> &visited, std::vector<int> &component) const
{
    visited[vertex] = true;
    component.push_back(vertex);

    for (int neighbor : adjacencyList[vertex])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, visited, component);
        }
    }
}

bool hamiltonianCycleUtil(int vertex, std::vector<bool> &visited, std::vector<int> &path, int count) const
{
    visited[vertex] = true;
    path.push_back(vertex);

    if (count == numVertices - 1)
    {
        if (adjacencyList[vertex].find(0) != adjacencyList[vertex].end())
        {
            path.push_back(0);
            return true;
        }
        else
        {
            path.pop_back();
            visited[vertex] = false;
            return false;
        }
    }

    for (int neighbor : adjacencyList[vertex])
    {
        if (!visited[neighbor] && hamiltonianCycleUtil(neighbor, visited, path, count + 1))
        {
            return true;
        }
    }

    path.pop_back();
    visited[vertex] = false;
    return false;
}

bool isConnected() const
{
    std::vector<bool> visited(numVertices, false);
    dfs(0, visited);

    for (bool visitStatus : visited)
    {
        if (!visitStatus)
        {
            return false;
        }
    }

    return true;
}

void topologicalSortUtil(int vertex, std::vector<bool> &visited, std::stack<int> &stack) const
{
    visited[vertex] = true;

    for (int neighbor : adjacencyList[vertex])
    {
        if (!visited[neighbor])
        {
            topologicalSortUtil(neighbor, visited, stack);
        }
    }

    stack.push(vertex);
}

bool isBipartiteUtil(int vertex, std::vector<int> &color) const
{
    std::queue<int> queue;
    queue.push(vertex);
    color[vertex] = 1;

    while (!queue.empty())
    {
        int currentVertex = queue.front();
        queue.pop();

        for (int neighbor : adjacencyList[currentVertex])
        {
            if (color[neighbor] == color[currentVertex])
            {
                return false;
            }
            else if (color[neighbor] == -1)
            {
                color[neighbor] = 1 - color[currentVertex];
                queue.push(neighbor);
            }
        }
    }

    return true;
}

bool hasCycleUtil(int vertex, std::vector<bool> &visited, int parent) const
{
    visited[vertex] = true;

    for (int neighbor : adjacencyList[vertex])
    {
        if (!visited[neighbor])
        {
            if (hasCycleUtil(neighbor, visited, vertex))
            {
                return true;
            }
        }
        else if (neighbor != parent)
        {
            return true;
        }
    }

    return false;
}
}
;

int main()
{
    // Пример использования класса Graph
    int numVertices, numEdges;
    std::cin >> numVertices >> numEdges;

    Graph graph(numVertices);

    for (int i = 0; i < numEdges; ++i)
    {
        int vertex1, vertex2;
        std::cin >> vertex1 >> vertex2;
        graph.addEdge(vertex1 - 1, vertex2 - 1);
    }

    graph.printGraph();
    // Вызов остальных методов класса Graph по необходимости

    return 0;
}