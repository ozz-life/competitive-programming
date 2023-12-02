//////// НЕ ЗАВЕРШЕНО, но делать по аналогии с BFS

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int INF = 1e9;

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int start)
{
    vector<int> dist(graph.size(), INF);
    dist[start] = 0;
    vector<int> from(graph.size(), -1);
    vector<bool> visited(graph.size());

    for (int i = 0; i < graph.size(); ++i)
    {
        int nearest = -1;
        for (int v = 0; v < graph.size(); ++v)
        {
            if (!visited[v] && (nearest == -1 || dist[nearest] > dist[v]))
            {
                nearest = v;
            }
        }
        visited[nearest] = true;

        for (auto &[to, weight] : graph[nearest])
        {
            if (dist[to] > dist[nearest] + weight)
            {
                dist[to] = dist[nearest] + weight;
                from[to] = nearest;
            }
        }
    }

    /// нет переменной finish
    vector<int> path;
    for(int v = finish; v != -1; v = from[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

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
        graph[b].push_back({a, weight});
    }

    int start;
    cin >> start;

    vector<int> dist = dijkstra(graph, start);

    for (int d : dist)
    {
        if (d != INF)
        {
            cout << d << " ";
        }
        else
        {
            cout << "X ";
        }
    }

    return 0;
}

// input.txt
// 15 19
// 0 1 15
// 1 2 25
// 2 3 10
// 0 5 20
// 1 6 0
// 2 7 70
// 3 8 50
// 4 9 10
// 6 7 40
// 7 8 30
// 5 10 30
// 6 10 10
// 7 12 60
// 8 12 5
// 8 13 70
// 9 14 25
// 10 11 10
// 11 12 35
// 12 13 70
// 7