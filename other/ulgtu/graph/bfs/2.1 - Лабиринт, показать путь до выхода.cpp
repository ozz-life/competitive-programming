// Найти расстаояние от S до F

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int INF = 1e9;

int bfs(vector<string> &a, int startY, int startX, int finishY, int finishX)
{
    int h = a.size(), w = a[0].size();
    vector<vector<int>> dist(h, vector<int>(w, INF));
    vector<vector<pair<int, int>>> from(h, vector<pair<int, int>>(w, {-1, -1}));
    queue<pair<int, int>> q;

    dist[startY][startX] = 0;
    q.push({startY, startX});

    vector<int> dy = {-1, 0, 1, 0};
    vector<int> dx = {0, 1, 0, -1};

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        // в ряде ситуаций допустимо возвращать сразу, но может быть недостижимо
        // if(y == finishY && x == finishX) {
        //     return dist[y][x];
        // }

        for (int d = 0; d < dy.size(); ++d)
        {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < h && 0 <= tx && tx < w &&
                a[ty][tx] != '#' && dist[ty][tx] > dist[y][x] + 1)
            {
                dist[ty][tx] = dist[y][x] + 1;
                from[ty][tx] = {y, x};
                q.push({ty, tx});
            }
        }
    }

    if (dist[finishY][finishX] != INF)
    {
        int y = finishY;
        int x = finishX;
        while (y != -1 && x != -1) {
            a[y][x] = '*';
            auto [py, px] = from [y][x];
            y = py;
            x = px;
        }
    }

    return dist[finishY][finishX];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    int startY, startX;
    int finishY, finishX;

    for (int y = 0; y < h; ++y)
    {
        std::getline(std::cin >> std::ws, a[y]);
        // cin >> a[y];
        for (int x = 0; x < w; ++x)
        {
            if (a[y][x] == 'S')
            {
                startY = y;
                startX = x;
            }
            else if (a[y][x] == 'F')
            {
                finishY = y;
                finishX = x;
            }
        }
    }

    int stepCount = bfs(a, startY, startX, finishY, finishX);

    if (stepCount != INF)
    {
        cout << stepCount;
        for (string &row : a) {
            cout << row << "\n";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }

    return 0;
}

// input.txt
// 8 10
// ...#......
// ......#.F.
// ...#######
// ..........
// #######.##
// .....#....
// .S.#.#....
// ...#......