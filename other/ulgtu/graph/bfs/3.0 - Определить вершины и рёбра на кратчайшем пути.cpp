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

    int start, finish;
    cin >> start >> finish;

    vector<int> distFromStart = bfs(graph, start);
    vector<int> distFromFinish = bfs(graph, finish);

    // Вывести те вершины, для которых два расстояния в сумме дадут длину
    // кратчайшего пути от старта до финиша. Или все, которые могут быть
    // на кратчайшем пути.
    for (int v = 0; v < vertexCount; ++v) {
        if (distFromStart[v] + distFromFinish[v] == distFromStart[finish]) {
            cout << v << " ";
        }
    }
    
    cout << "\n\n";

    // Вывести все рёбра, которые могут быть частью кратчайшего пути.
    for (int v = 0; v < vertexCount; ++v) {
        for (int to : graph[v]) {
            if (distFromStart[v] + 1 + distFromFinish[to] == distFromStart[finish]) {
                cout << v << " " << to << "\n";
            }
        }
    }

    return 0;
}

// input.txt
// 13 17
// 0 1
// 1 2
// 2 3
// 3 4
// 4 12
// 3 6
// 0 5
// 5 6
// 6 8
// 8 12
// 5 7
// 7 8
// 0 9
// 9 10
// 10 7
// 7 11
// 11 12
// 0 12