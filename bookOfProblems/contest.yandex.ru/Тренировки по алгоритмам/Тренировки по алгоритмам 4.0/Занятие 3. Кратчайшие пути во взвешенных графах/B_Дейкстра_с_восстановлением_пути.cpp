#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
};

struct Node {
    int index;
    int distance;

    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

vector<int> dijkstra(vector<vector<Edge>> &graph, int start, int finish) {
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<int> from(n, -1);
    vector<bool> visited(n, false);

    priority_queue<Node, vector<Node>, greater<Node>> pq;

    dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int currentIndex = current.index;
        if (visited[currentIndex]) {
            continue;
        }

        visited[currentIndex] = true;

        for (const Edge& neighbor : graph[currentIndex]) {
            int nextIndex = neighbor.to;
            int newDistance = dist[currentIndex] + neighbor.weight;

            if (newDistance < dist[nextIndex]) {
                dist[nextIndex] = newDistance;
                from[nextIndex] = currentIndex;
                pq.push({nextIndex, newDistance});
            }
        }
    }

    vector<int> path;
    if (dist[finish] == INF) {
        path.push_back(-1);  // Unreachable
    } else {
        for (int v = finish; v != -1; v = from[v]) {
            path.push_back(v + 1); // Convert to 1-based indexing
        }
        reverse(path.begin(), path.end());
    }

    return path;
}

int main() {
    int N, S, F;
    cin >> N >> S >> F;

    vector<vector<Edge>> graph(N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int weight;
            cin >> weight;

            if (weight != -1 && i != j) {  // Avoid self-loops
                graph[i].push_back({j, weight});
            }
        }
    }

    vector<int> path = dijkstra(graph, S - 1, F - 1);

    for (int vertex : path) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
