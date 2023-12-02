// В ориентированном графе есть цикл, если при дфс мы встретим вершину,
// которую мы начали, но ещё не закончили обрабатывать.

#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

// Базовая версия O(v + e), если граф задан списком смежности
// visited[v] == 0 Обработка ещё не началась
// visited[v] == 1 Обработка началась, но ещё не закончилась
// visited[v] == 2 Обработка уже закончилась
void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int from, bool &hasCycle)
{
    visited[v] = 1;

    for (int to : graph[v])
    {
        if (to == from)
        {
            continue;
        }
        else if (!visited[to])
        {
            dfs(graph, to, visited, v, hasCycle);
        }
        else if (visited[to] == 1)
        {
            // в графе есть цикл
            hasCycle = true;
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

    bool hasCycle = false;
    for (int v = 0; v < vertexCount; ++v)
    {
        if (!visited[v])
        {
            dfs(graph, v, visited, -1, hasCycle);
        }
    }

    if (hasCycle)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}