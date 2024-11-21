/*
            ▒█████  ▒███████▒▒███████▒      ██▓     ██▓  █████▒▓█████
           ▒██▒  ██▒▒ ▒ ▒ ▄▀░▒ ▒ ▒ ▄▀░     ▓██▒    ▓██▒▓██   ▒ ▓█   ▀
           ▒██░  ██▒░ ▒ ▄▀▒░ ░ ▒ ▄▀▒░      ▒██░    ▒██▒▒████ ░ ▒███
           ▒██   ██░  ▄▀▒   ░  ▄▀▒   ░     ▒██░    ░██░░▓█▒  ░ ▒▓█  ▄
           ░ ████▓▒░▒███████▒▒███████▒ ██▓ ░██████▒░██░░▒█░    ░▒████▒
           ░ ▒░▒░▒░ ░▒▒ ▓░▒░▒░▒▒ ▓░▒░▒ ▒▓▒ ░ ▒░▓  ░░▓   ▒ ░    ░░ ▒░ ░
             ░ ▒ ▒░ ░░▒ ▒ ░ ▒░░▒ ▒ ░ ▒ ░▒  ░ ░ ▒  ░ ▒ ░ ░       ░ ░  ░
           ░ ░ ░ ▒  ░ ░ ░ ░ ░░ ░ ░ ░ ░ ░     ░ ░    ▒ ░ ░ ░       ░
               ░ ░    ░ ░      ░ ░      ░      ░  ░ ░             ░  ░
                    ░        ░          ░
                             https:://ozz.life/
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

const char ENDL = '\n';

void printGraph(const std::vector<std::vector<int64_t>> &adjacencyList)
{
    int64_t vertexCount = adjacencyList.size();
    for (int64_t i = 0; i < vertexCount; ++i)
    {
        std::cout << "Vertex " << i + 1 << ": ";
        for (int64_t neighbor : adjacencyList[i])
        {
            std::cout << neighbor + 1 << " ";
        }
        std::cout << std::endl;
    }
}

int64_t findDegree(const std::vector<std::vector<int64_t>> &adjacencyList, int64_t vertex)
{
    return adjacencyList[vertex].size();
}

void solve()
{
    int64_t n, m;
    std::cin >> n >> m; // Читаем количество вершин и ребер

    std::vector<vector<int64_t>> adjacencyList(n);
    std::vector<int> deg(n); // Вектор для хранения степеней вершин

    for (int i = 0; i < m; i++)
    {
        int64_t u, v;
        std::cin >> u >> v; // Читаем ребра

        // Индексация вершин начинается с 1, поэтому уменьшаем на 1
        u--;
        v--;
        adjacencyList[u].push_back(v); // Добавляем ребро u -> v
        adjacencyList[v].push_back(u); // Добавляем ребро v -> u (если граф неориентированный)

        // deg[u]++; // Увеличиваем степень вершины u
        // deg[v]++; // Увеличиваем степень вершины v
    }

    int64_t y = 0;

    // Запускает цикл for, чтобы подсчитать количество вершин с степенью 1. В каждой итерации:
    // Проверяет, если степень вершины i равна 1, то увеличивает значение y на 1.
    for (int64_t i = 0; i < n; i++)
    {
        if (findDegree(adjacencyList, i) == 1)
        {
            y++; // Считаем количество вершин со степенью 1
        }
    }

    // Вычисляет значение x, которое равно разнице между общим количеством вершин n и количеством вершин с степенью 1 y, уменьшенным на 1.
    int x = n - y - 1;
    // Выводим значения x и y
    std::cout << x << ' ' << y / x << '\n';
}

int main()
{
    // Отключение синхронизация между С и C++ вводом/выводом
    std::ios::sync_with_stdio(false);
    // Отключение синхронизации между cin и cout
    // Важно! При решении интерактивных задач рекомендуется не отключать синхронизацию (или хотя бы держать в голове возможность проблем из-за отключения).
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // Перенаправление потоков cin/cout с помощью freopen
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int64_t num_test_cases;
    cin >> num_test_cases;
    for (int64_t current_case = 1; current_case <= num_test_cases; current_case++) // проходим по всем тест-кейсам
    {
        // cout << "Case #" << current_case << ": ";
        solve();
    }

    return 0;
}

// 3
// 21 20
// 21 20
// 5 20
// 13 20
// 1 3
// 11 3
// 10 3
// 4 8
// 19 8
// 14 8
// 9 7
// 12 7
// 17 7
// 18 6
// 16 6
// 2 6
// 6 15
// 7 15
// 8 15
// 20 15
// 3 15
// 7 6
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 3 7
// 9 8
// 9 3
// 3 6
// 6 2
// 2 1
// 5 2
// 2 7
// 4 3
// 3 8