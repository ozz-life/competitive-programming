#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int INF = 1e9;

// Стандартный BFS
pair<vector<int>, vector<int>> bfs(vector<vector<int>> &graph, int start)
{
    vector<int> dist(graph.size(), INF);
    vector<int> from(graph.size(), -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int to : graph[v])
        {
            if (dist[to] > dist[v] + 1)
            {
                dist[to] = dist[v] + 1;
                from[to] = v;
                q.push(to);
            }
        }
    }

    return {dist, from};
}

vector<int> getPath(vector<int> &from, int finish)
{
    vector<int> path;
    for (int v = finish; v != -1; v = from[v])
    {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    return path;
}

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

        // на неориентированных графах добавляем дважды
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int start;
    cin >> start;

    auto [dist, from] = bfs(graph, start);

    for (int v : getPath(from, 4)) {
        cout << v << " ";
    }

  return 0;
}

// input.txt
// 10 13
// 0 1
// 1 8
// 8 5
// 0 3
// 8 2
// 5 6
// 7 3
// 3 2
// 2 6
// 7 9
// 3 9
// 2 9
// 2 4
// 0