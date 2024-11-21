#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

// Базовая версия O(v + e), если граф задан списком смежности
void dfs(vector<vector<int>> &adjacencyList, int v, vector<int> &visited)
{
    visited[v] = 1;

    for (int to : adjacencyList[v])
    {
        if (!visited[to])
        {
            dfs(adjacencyList, to, visited);
        };
    };
};

// Если граф задан матрицей смежности O(v^2)
void dfs(vector<vector<int>> &adjacencyMatrix, int v, vector<int> &visited)
{
    visited[v] = 1;

    for (int to = 0; to < adjacencyMatrix.size(); ++to)
    {
        if (adjacencyMatrix[v][to] && !visited[to])
        {
            dfs(adjacencyMatrix, to, visited);
        }
    }
};

// Расскраска - назначить номера вершинам по количеству компонентов связанности
void dfs(vector<vector<int>> &adjacencyList, int v, vector<int> &visited, int component)
{
    visited[v] = component;

    for (int to : adjacencyList[v])
    {
        if (!visited[to])
        {
            dfs(adjacencyList, to, visited, component);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // Если мы ищем компоненты связанности, запускаем счётик, сколько раз запустился dfs
    for (int v = 0; v < adjacencyList.size(); ++v)
    {
        if (!visited[v])
        {
            dfs(adjacencyList, v, visited);
        }
    };

    return 0;
}