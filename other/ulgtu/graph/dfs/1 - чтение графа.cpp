#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ////////////////////////////////////////////////////////////////////////////
    // Список рёбер, предпочтителен для описания графа в задачах
    // Используемая память: O(E)
    // Проверка существования, добавление, удаление, изменение ребра(a, b): O(E)
    // Перебор соседей вершины a: O(E)

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<pair<int, int>> edges(edgeCount);

    for (auto &[a, b] : edges)
    {
        cin >> a >> b;
        a--;
        b--;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Матрица смежности, предпочтительна для плотных графов
    // Используемая память: O(V^2)
    // Проверка существования, добавление, удаление, изменение ребра(a, b): O(1)
    // Перебор соседей вершины a: O(V)

    int64_t vertexCount, edgeCount;
    std::cin >> vertexCount >> edgeCount;

    std::vector<std::vector<int64_t>> adjacencyMatrix(vertexCount, vector<int64_t>(vertexCount));

    for (int64_t i = 0; i < edgeCount; ++i)
    {
        int64_t vertex1, vertex2;
        cin >> vertex1 >> vertex2;

        // Преобразование 1-индексации в 0-индексацию
        vertex1--;
        vertex2--;

        // Если граф ориентированный, то мы добавляем единицу в одну ячейку
        adjacencyMatrix[vertex1][vertex2] = 1;
        // Если же граф неориентированный, то добавляем единицы в обе ячейки
        adjacencyMatrix[vertex2][vertex1] = 1;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Списки смежностей предпочтительны для разреженных графов
    // Большинство графов в реальной жизни разреженные
    // Списки смежности не предполагают, что они сортированы
    // Используемая память: O(V+E)
    // Проверка существования, добавление, удаление, изменение ребра(a, b): O(deg a)
    // Перебор соседей вершины a: O(deg a)

    int64_t vertexCount, edgeCount;
    std::cin >> vertexCount >> edgeCount;

    std::vector<std::vector<int64_t>> adjacencyList(vertexCount);

    for (int64_t i = 0; i < edgeCount; ++i)
    {
        int64_t vertex1, vertex2;
        std::cin >> vertex1 >> vertex2;

        // Преобразование 1-индексации в 0-индексацию
        vertex1--;
        vertex2--;

        // Добавляем ребро в список смежности
        adjacencyList[vertex1].push_back(vertex2);
        // Если граф неориентированный, добавляем обратное ребро
        adjacencyList[vertex2].push_back(vertex1);
    }
}