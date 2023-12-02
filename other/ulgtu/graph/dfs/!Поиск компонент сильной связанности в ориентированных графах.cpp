// Алгоритм Косараджу-Шарира
// Если запустить дфс из неправильной вершины, он покрасит слишком много
// Если запустить дфс из правильной вершины, он покрасит только одну КСС
// Если запустить дфс в правильном порядке, можно раскрасить все КСС
// Алгоритм поиска компонент сильной связанности
// 1. Построить вспомогательный граф, в котором направление
// всех рёбер изменено на противоположное
// 2. На инвертированном вспомогательном графе запустить
// топологическую сортировку
// 3. Раскрасить исходный граф, запуская дфс в порядке топологической сортировки

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;


class Graph {
    // Исходный граф (g) и инвертированный граф (gr)
    vector<vector<int>> g, gr;
    // Массивы посещённых вершин и порядка обхода
    vector<int> visited, order;

    // Запустить топологическую сортировку на инвертированном графе
    void dfs1(int v) {
        // Помечаем вершину как посещённую
        visited[v] = 1;

        // Рекурсивно обходим всех соседей вершины
        for (int to : gr[v]) {
            if (!visited[to]) {
                dfs1(to);
            }
        }

        // Добавляем вершину в порядок обхода
        order.push_back(v);
    }

    // Раскрасить компоненты исходного графа
    void dfs2(int v, int component) {
        // Помечаем вершину как посещённую и присваиваем ей номер компоненты
        visited[v] = component;

        // Рекурсивно обходим всех соседей вершины
        for (int to : g[v]) {
            if (!visited[to]) {
                dfs2(to, component);
            }
        }
    }

public:
    // Конструктор, создающий пустой граф заданного размера
    Graph(int vertexCount) {
        g.resize(vertexCount);
        gr.resize(vertexCount);
    }

    // Добавить ребро между вершинами a и b
    void addEdge(int a, int b) {
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    // Алгоритм поиска компонент сильной связанности
    vector<int> findScc() {
        // Обнуляем массив посещённых вершин и запускаем топологическую сортировку на инвертированном графе
        visited.assign(g.size(), 0);
        for (int v = 0; v < g.size(); ++v) {
            if (!visited[v]) {
                dfs1(v);
            }
        }

        // Переворачиваем порядок обхода вершин
        reverse(order.begin(), order.end());

        // Обнуляем массив посещённых вершин и раскрашиваем компоненты исходного графа
        visited.assign(g.size(), 0);
        int sccCount = 0;
        for (int v : order) {
            if (!visited[v]) {
                dfs2(v, ++sccCount);
            }
        }

        // Возвращаем массив, в котором для каждой вершины указан номер её компоненты
        return visited;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    Graph graph(vertexCount);

    for (int i = 0; i < edgeCount; ++i) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    vector<int> scc = graph.findScc();
    for (int color : scc) {
        cout << color << " ";
    }

    return 0;
}