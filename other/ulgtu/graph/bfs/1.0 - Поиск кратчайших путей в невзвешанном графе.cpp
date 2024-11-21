#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int INF = 1e9;

// Стандартный BFS
vector<int> bfs(vector<vector<int>> &graph, int start) {
    vector<int> dist(graph.size(), INF);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : graph[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
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

    vector<int> dist = bfs(graph, start);
    for (int d : dist)
    {
        if (d != INF)
        {
            cout << d << " ";
        }
        else
        {
            cout << "X";
        }
    }
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