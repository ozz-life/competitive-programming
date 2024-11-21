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

ll n, m, k, t, q, l, r, x, y, z;
ll answer;
const ll template_array_size = 1e6 + 8432;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
std::string s;

ll dfs(vector<vector<int64_t>> &adjacencyList, ll v, vector<int64_t> &visited)
{
    ll mn = c[v];
    visited[v] = 1;

    for (ll to : adjacencyList[v])
    {
        if (!visited[to])
        {
            mn = min(mn, dfs(adjacencyList, to, visited));
        }
    }
    return mn;
}

void solve()
{
    int64_t vertexCount, edgeCount;
    std::cin >> vertexCount >> edgeCount;

    std::vector<std::vector<int64_t>> adjacencyList(vertexCount);

    for (ll i = 0; i < vertexCount; ++i)
    {
        cin >> c[i]; // array of costs
    }

    for (int64_t i = 0; i < edgeCount; ++i)
    {
        int64_t vertex1, vertex2;
        std::cin >> vertex1 >> vertex2;

        // Преобразование 1-индексации в 0-индексацию
        vertex1--;
        vertex2--;

        // Добавляем ребро в список смежности
        adjacencyList[vertex1].push_back(vertex2);
        // Если граф неориентированный, добавляем обратное ребро
        adjacencyList[vertex2].push_back(vertex1);
    }

    ll ans = 0;
    vector<int64_t> visited(vertexCount);
    for (ll i = 0; i < vertexCount; ++i)
    {
        if (!visited[i])
        {
            ans += dfs(adjacencyList, i, visited);
        }
    }

    cout << ans << "\n";
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

    int num_test_cases = 1;
    // cin >> num_test_cases;
    for (int current_case = 1; current_case <= num_test_cases; current_case++) // проходим по всем тест-кейсам
    {
        // cout << "Case #" << current_case << ": ";
        solve();
    }

    return 0;
}
