#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

// Базовая версия O(v + e), если граф задан списком смежности
void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int component)
{
    visited[v] = component;

    for (int to : graph[v])
    {
        if (visited[to] == -1)
        {
            dfs(graph, to, visited, component);
        };
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

    for (int i = 0; i < edgeCount; ++i)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        // Если ребро неориентированно, то нужно ещё учитывать обратное направление
        graph[b].push_back(a);
    }

    vector<int> visited(vertexCount, -1);

    int componentCount = 0; 
    for (int v = 0; v < vertexCount; ++v)
    {
        if (visited[v] == -1)
        {
            dfs(graph, v, visited, componentCount);
            componentCount++;
        }
    }

    for (int color : visited) {
        cout << color << " ";
    }

    return 0;
}