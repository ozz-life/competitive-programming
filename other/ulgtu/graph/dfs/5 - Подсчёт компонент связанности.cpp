// Не работает
// Доделать
// ближайшие меньшие
// меньшие или равные
// большие или равные
// Так и слева такие же
// Во всех поддерживаем стек ожидающих ответа

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

// Базовая версия O(v + e), если граф задан списком смежности
void dfs(vector<vector<int>> &graph, int v, vector<int> &visited)
{
    visited[v] = 1;

    for (int to : graph[v])
    {
        if (!visited[to])
        {
            dfs(graph, to, visited);
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

    int componentCount = 0;
    vector<int> visited(vertexCount);
    for (int v = 0; v < vertexCount; ++v)
    {
        if (!visited[v])
        {
            componentCount++;
            dfs(graph, v, visited);
        }
    }

    cout << componentCount;

    return 0;
}