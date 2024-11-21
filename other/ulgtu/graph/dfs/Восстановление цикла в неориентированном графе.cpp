// В ориентированном графе есть цикл, если при дфс мы встретим вершину,
// которую мы начали, но ещё не закончили обрабатывать.

#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

// Если хочется, чтобы вершина, на которой цикл замкнулся, была последней
// vector<int> getCycle(vector<int> &from, int lastVertex)
// {
//     vector<int> cycle = {lastVertex};
//     for (int v = from[lastVertex]; v != lastVertex; v = from[v])
//     {
//         cycle.push_back(v);
//     }
//     reverse(cycle.begin(), cycle.end());
//     return cycle;
// }

// Если хочется, чтобы вершина, на которой цикл замкнулся, была бы не последней, а первой
vector<int> getCycle(vector<int> &from, int lastVertex)
{
    vector<int> cycle;
    for (int v = from[lastVertex]; v != lastVertex; v = from[v])
    {
        cycle.push_back(v);
    }
    cycle.push_back(lastVertex);
    reverse(cycle.begin(), cycle.end());
    return cycle;
}

// Базовая версия O(v + e), если граф задан списком смежности
// visited[v] == 0 Обработка ещё не началась
// visited[v] == 1 Обработка началась, но ещё не закончилась
// visited[v] == 2 Обработка уже закончилась
void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &from, vector<int> &cycle)
{
    visited[v] = 1;

    for (int to : graph[v])
    {
        if (to == from[v]) {
            continue;
        } else if (!visited[to])
        {
            from[to] = v;
            dfs(graph, to, visited, from, cycle);
            if (!cycle.empty())
            {
                return;
            }
        }
        else if (visited[to] == 1)
        {
            // в графе есть цикл
            from[to] = v;
            cycle = getCycle(from, to);
            return;
        }
    };

    visited[v] = 2;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    for (int v = 0; v < edgeCount; ++v)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(vertexCount);
    vector<int> from(vertexCount, -1);
    vector<int> cycle;

    bool hasCycle = false;
    for (int v = 0; cycle.empty() && v < vertexCount; ++v)
    {
        if (!visited[v])
        {
            dfs(graph, v, visited, from, cycle);
        }
    }

    if (!cycle.empty())
    {
        cout << "YES\n";
        for (int v : cycle)
        {
            cout << v + 1 << " ";
        }
    }
    else
    {
        cout << "NO";
    }

    return 0;
}