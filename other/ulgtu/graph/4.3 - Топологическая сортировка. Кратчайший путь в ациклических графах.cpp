// Алгоритм Флойда (алгоритм Флойда–Уоршелла) — алгоритм нахождения длин кратчайших путей между всеми парами вершин во взвешенном ориентированном графе. Работает корректно, если в графе нет циклов отрицательной величины, а в случае, когда такой цикл есть, позволяет найти хотя бы один такой цикл. Разработан в 1962 году. 

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int INF = 1e9;

// DFS топологическая сортировка
void dfs(vector<vector<pair<int, int>>> &graph, int v, vector<int> &visited, vector<int> &order)
{
    visited[v] = 1;

    for (auto [to, weigth] : graph[v])
    {
        if (!visited[to])
        {
            dfs(graph, to, visited, order);
        }
    }

    order.push_back(v);
}

vector<int> topSortShortestPath(vector<vector<pair<int, int>>> &graph, int start)
{
    vector<int> visited(graph.size());
    vector<int> order;

    for (int v = 0; v < graph.size(); ++v)
    {
        if (!visited[v])
        {
            dfs(graph, v, visited, order);
        }
    }

    reverse(order.begin(), order.end());
    vector<int> dist(graph.size(), INF);
    dist[start] = 0;

    for (int v : order)
    {
        for (auto &[to, weight] : graph[v])
        {
            if (dist[v] != INF && dist[to] > dist[v] + weight)
            {
                dist[to] = dist[v] + weight;
            }
        }
    }

    return dist;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;


    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; ++i)
    {
        int a, b, weight;
        cin >> a >> b >> weight;

        graph[a].push_back({b, weight});
    }

    int start;
    cin >> start;
    // start--

    vector<int> dist = topSortShortestPath(graph, start);

    for (int d: dist) {
        cout << d << " ";
    }

    return 0;
}

// input.txt
// 12 17
// 0 1 1
// 1 2 4
// 2 3 5
// 4 0 7
// 5 1 2
// 6 2 3
// 3 7 -3
// 5 4 5
// 5 6 -2
// 6 7 7
// 8 4 -6
// 5 9 4
// 6 10 6
// 7 11 4
// 9 8 3
// 9 10 1
// 10 11 2
// 5
