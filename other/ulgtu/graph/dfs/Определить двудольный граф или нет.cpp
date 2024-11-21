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
void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int color, bool &isBipartite)
{
    visited[v] = color;

    for (int to : graph[v])
    {
        if (!visited[to])
        {
            dfs(graph, to, visited, 3 - color, isBipartite);
        } else if (visited[to] == color) {
            isBipartite = false;
        }
    };
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
    bool isBipartite = true;

    for (int v = 0; v < vertexCount; ++v) {
        if (!visited[v]) {
            dfs(graph, v, visited, 1, isBipartite);
        }
    }

    if (isBipartite) {
        cout << "YES\n";
        for (int color : visited) {
            cout << color << " "; 
        }
    } else {
        cout << "NO";
    }

    return 0;
}