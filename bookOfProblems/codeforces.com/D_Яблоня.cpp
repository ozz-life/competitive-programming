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
          Author: Stanilav "Oz" Ozeransky | Site: https:://ozz.life/

We are what we think.
All that we are arises with our thoughts.
With our thoughts we make the world.
Speak or act with a pure mind
And happiness will follow you
As your shadow, unshakable. ― Gautama Buddha

*/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef int64_t ll;
typedef uint64_t ull;
typedef vector<int64_t> vi;
typedef pair<int64_t, int64_t> pi;

#define FOR(s, e, i) for (int64_t i = s; i < e; ++i)
#define FORE(s, e, i) for (int64_t i = s; i <= e; ++i)
#define ROF(e, s, i) for (int64_t i = e; i >= s; --i)

#define inp(x) for(auto &i:x) cin>>i;
#define print(x) for(auto i:x) cout<<i<<" ";
#define pprint(x) for(auto [i,j]:x) cout<<i<<" "<<j

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mine(v) *std::min_element(all(v));
#define maxe(v) *std::max_element(all(v));

const char ENDL = '\n';
#define YES cout << "YES" << '\n';
#define NO cout << "NO" << '\n';
#define YN(x) cout << (x ? "YES\n" : "NO\n"

#define pb push_back
#define mp make_pair

/*
 * Graph
 ******************************************************************************/

class Graph
{
public:
    Graph(int64_t vertexCount) : adjacencyList(vertexCount) {}

    void addEdge(int64_t vertex1, int64_t vertex2, bool isDirected)
    {
        adjacencyList[vertex1].push_back(vertex2);
        if (!isDirected)
        {
            adjacencyList[vertex2].push_back(vertex1);
        }
    }

    void printGraph() const
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

    int64_t findDegree(int64_t vertex) const
    {
        return adjacencyList[vertex].size();
    }

private:
    std::vector<std::vector<int64_t>> adjacencyList;
};

/*
 * Solve
 ******************************************************************************/

int64_t findFork(const std::vector<std::vector<int64_t>>& adjacencyList)
{
    for (int64_t vertex = 0; vertex < adjacencyList.size(); ++vertex)
    {
        if (adjacencyList[vertex].size() > 1)
            return vertex;
    }
    return -1; // Если развилка не найдена, возвращаем -1
}

void solve()
{
    int64_t vertexCount;
    std::cin >> vertexCount;
    int64_t edgeCount = vertexCount - 1;
    
    std::vector<std::vector<int64_t>> adjacencyList(vertexCount);
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
    
    int64_t q; cin >> q;
    for(int i = 0; i < q; ++i) {
        std::cerr << "cerr";
    }

    int64_t forkVertex = findFork(adjacencyList);
    if (forkVertex != -1)
        std::cout << "Развилка найдена на вершине " << forkVertex << "\n";
    else
        std::cout << "Развилка не найдена\n";

}

/*
 * Main
 ******************************************************************************/

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
    //setlocale(LC_ALL, "Russian");
    // auto time_start = steady_clock::now();

    int64_t num_test_cases = 1;
    cin >> num_test_cases;
    for (int64_t current_case = 1; current_case <= num_test_cases; current_case++) // проходим по всем тест-кейсам
    {
        // cout << "Case #" << current_case << ": ";
        solve();
    }

   //auto time_end = steady_clock::now();
    //cout << duration_cast<milliseconds>(time_end - time_start).count();

    return 0;
}