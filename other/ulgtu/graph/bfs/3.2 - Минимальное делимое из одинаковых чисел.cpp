#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int INF = 1e9;

void printPath(vector<pair<int, int>> &from, int finish)
{
    vector<int> path;
    for (int v = finish; v != -1; v = from[v].first)
    {
        path.push_back(from[v].second);
    }
    reverse(path.begin(), path.end());
    for (int v : path)
    {
        cout << v;
    }
}

void bfs(vector<int> &sortedDigits, int divisor)
{
    vector<int> dist(divisor, INF);
    vector<pair<int, int>> from(divisor, {-1, -1});
    queue<int> q;

    for (int digit : sortedDigits)
    {
        int v = digit % divisor;
        if (dist[v] > 0)
        {
            dist[v] = 0;
            from[v] = {-1, digit};
            q.push(v);
        }
    }

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        if (v == 0)
        {
            printPath(from, v);
            return;
        }

        for (int digit : sortedDigits)
        {
            int to = (v * 10 + digit) % divisor;
            if (dist[to] > dist[v] + 1)
            {
                dist[to] = dist[v] + 1;
                from[to] = {v, digit};
                q.push(to);
            }
        }
    }
    cout << "Impossible";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    vector<int> sortedDigits = {1, 2};
    bfs(sortedDigits, 9);

    return 0;
} 