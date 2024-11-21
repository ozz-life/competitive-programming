#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int INF = 1e9;

void printPath(vector<vector<pair<int, int>>> &from, int a, int b)
{
    vector<pair<int, int>> path;
    while (a != -1 && b != -1)
    {
        path.push_back({a, b});
        auto [pa, pb] = from[a][b];
        a = pa;
        b = pb;
    }

    reverse(path.begin(), path.end());
    for (auto [a, b] : path)
    {
        cout << a << " " << b << "\n";
    }
}

void bfs(int capacityA, int capacityB, int target)
{
    vector<vector<int>> dist(capacityA + 1, vector<int>(capacityB + 1, INF));
    vector<vector<pair<int, int>>> from(capacityA + 1, vector<pair<int, int>>(capacityB + 1, {-1, -1}));
    queue<pair<int, int>> q;

    dist[0][0] = 0;
    q.push({0, 0});

    while (!q.empty())
    {
        auto [a, b] = q.front();
        q.pop();

        if (a == target || b == target)
        {
            cout << "Quantity steps: " << dist[a][b] << "\n";
            printPath(from, a, b);
            return;
        }

        vector<pair<int, int>> to{
            {0, b},
            {a, 0},
            {capacityA, b},
            {a, capacityB}};

        int deltaAB = min(a, capacityB - b);
        to.push_back({a - deltaAB, b + deltaAB});
        int deltaBA = min(capacityA - a, b);
        to.push_back({a + deltaBA, b - deltaBA});

        for (auto [ta, tb] : to)
        {
            if (dist[ta][tb] > dist[a][b] + 1)
            {
                dist[ta][tb] = dist[a][b] + 1;
                from[ta][tb] = {a, b};
                q.push({ta, tb});
            }
        }
    }

    cout << "IMPOSSIBLE";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    bfs(3, 5, 4);

    return 0;
}