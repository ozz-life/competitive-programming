// Работает, есть оптимизации SPFA
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int INF = 1e9;

struct Edge {
    int a, b, weight;
};

// O(VE)
vector<int> BellmanFord(int vertexCount, vector<Edge> &edges, int start) {
    vector<int> dist(vertexCount, INF);
    dist[start] = 0;

    for (int i = 0; i < vertexCount - 1; ++i) {
        for (auto &[a, b, weight] : edges) {
            if (dist[a] != INF && dist[b] > dist[a] + weight) {
                dist[b] = dist[a] + weight;
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

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, weight] : edges) {
        cin >> a >> b >> weight;
        // a--;
        // b--;
    }

    int start;
    cin >> start;
    // start--

    vector<int> dist = BellmanFord(vertexCount, edges, start);
    for (int d : dist) {
        cout << d << " ";
    }

    return 0;
}

// input.txt
// 12 17
// 0 1 1
// 1 2 4
// 2 3 5
// 4 0 7
// 5 1 2
// 6 2 3
// 3 7 -3
// 5 4 5
// 5 6 -2
// 6 7 7
// 8 4 -6
// 5 9 4
// 6 10 6
// 7 11 4
// 9 8 3
// 9 10 1
// 10 11 2
// 5
