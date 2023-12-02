#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

void dfs(vector<string> &a, int y, int x, int component)
{
    a[y][x] = 'A' + component - 1; // помечаем текущую клетку, как посещённую

    // Проверяем соседей, объявлены статическими, чтобы для всех запусков функции они были общими и не создавались заного при каждом рекурсивном запуске
    static vector<int> dy = {-1, 0, 1, 0}; // север, восток, юг, запад
    static vector<int> dx = {0, 1, 0, -1}; // север, восток, юг, запад
                                           // Проверяем соседей, если угловые тоже доступны
    // static vector<int> dy = {-1, 0, 1, 0, -1, -1, 1, 1};
    // static vector<int> dx = {0, 1, 0, -1, -1, 1, 1, -1};

    for (int d = 0; d < dy.size(); ++d)
    {
        // Сохраняем координаты соседа в ty и tx. Название по аналогии c to
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (0 <= ty && ty < a.size() && // Проверить не уйдёт ли сосед за границу карты
            0 <= tx && tx < a[ty].size() &&
            (a[ty][tx] == '#')) // Проверить находится ли в этой клетке суша (#), а не океан (.)
        {
            dfs(a, ty, tx, component);
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (string &row : a)
    {
        cin >> row;
    }

    vector<vector<int>> visited(h, vector<int>(w));

    int componentCount = 0;
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            if (a[y][x] == '#') {
                componentCount++;
                dfs(a, y, x, componentCount);
            }
        }
    }

    for (string &row : a) {
        cout << row << "\n";
    }

    return 0;
}

// input:
// 8 8
// .##..##.
// .#...###
// .##..#..
// ..##....
// #....##.
// .....##.
// .###....
// ...##...