#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> dijkstra(vector<vector<int>> &graph, int start, int end) {
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);

    dist[start] = 0;

    for (int i = 0; i < n; ++i) {
        int nearest = -1;
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && (nearest == -1 || dist[nearest] > dist[v])) {
                nearest = v;
            }
        }

        visited[nearest] = true;

        for (int to = 0; to < n; ++to) {
            if (graph[nearest][to] >= 0 && dist[to] > dist[nearest] + graph[nearest][to]) {
                dist[to] = dist[nearest] + graph[nearest][to];
            }
        }
    }

    return dist;
}

int main() {
    int n, start, end;
    cin >> n >> start >> end;

    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    vector<int> dist = dijkstra(graph, start - 1, end - 1);

    if (dist[end - 1] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[end - 1] << endl;
    }

    return 0;
}
