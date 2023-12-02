#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

struct Edge {
    int to;
    long long weight;
};

struct Node {
    int index;
    long long distance;

    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

class Graph {
public:
    int size;
    vector<vector<Edge>> adjacencyList;

    Graph(int n) : size(n), adjacencyList(n) {}

    void addEdge(int from, int to, long long weight) {
        adjacencyList[from].push_back({to, weight});
        adjacencyList[to].push_back({from, weight});
    }

    long long dijkstra(int start, int end) {
        vector<long long> distance(size, INF);
        vector<bool> visited(size, false);
        priority_queue<Node, vector<Node>, greater<Node>> pq;

        distance[start] = 0;
        pq.push({start, 0});

        while (!pq.empty()) {
            Node current = pq.top();
            pq.pop();

            int currentIndex = current.index;
            if (visited[currentIndex]) {
                continue;
            }

            visited[currentIndex] = true;

            for (const Edge& neighbor : adjacencyList[currentIndex]) {
                int nextIndex = neighbor.to;
                long long newDistance = distance[currentIndex] + neighbor.weight;

                if (newDistance < distance[nextIndex]) {
                    distance[nextIndex] = newDistance;
                    pq.push({nextIndex, newDistance});
                }
            }
        }

        return (distance[end] == INF) ? -1 : distance[end];
    }
};

int main() {
    int N, K;
    cin >> N >> K;

    Graph roadNetwork(N);

    for (int i = 0; i < K; ++i) {
        int ai, bi;
        long long li;
        cin >> ai >> bi >> li;
        roadNetwork.addEdge(ai - 1, bi - 1, li);
    }

    int A, B;
    cin >> A >> B;

    long long shortestDistance = roadNetwork.dijkstra(A - 1, B - 1);

    cout << shortestDistance << endl;

    return 0;
}
