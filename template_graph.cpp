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

class Graph {
public:
  Graph(int vertexCount) : adjacencyList(vertexCount) {}

  void addEdge(int vertex1, int vertex2, bool isDirected) {
    adjacencyList[vertex1].push_back(vertex2);
    if (!isDirected) {
      adjacencyList[vertex2].push_back(vertex1);
    }
  }

  void printGraph() const {
    int vertexCount = adjacencyList.size();
    for (int i = 0; i < vertexCount; ++i) {
      std::cout << "Vertex " << i + 1 << ": ";
      for (int neighbor : adjacencyList[i]) {
        std::cout << neighbor + 1 << " ";
      }
      std::cout << std::endl;
    }
  }

  int findDegree(int vertex) const { return adjacencyList[vertex].size(); }

private:
  std::vector<std::vector<int>> adjacencyList;
};

void solve() {
  int64_t vertexCount, edgeCount;
  std::cin >> vertexCount >> edgeCount;

  Graph graph(vertexCount);
  for (int64_t i = 0; i < edgeCount; ++i) {
    int64_t vertex1, vertex2;
    std::cin >> vertex1 >> vertex2;

    vertex1--;
    vertex2--;

    bool isDirected = false;
    graph.addEdge(vertex1, vertex2, isDirected);
  }
}

int main() {
  // Отключение синхронизация между С и C++ вводом/выводом
  std::ios::sync_with_stdio(false);
  // Отключение синхронизации между cin и cout
  // Важно! При решении интерактивных задач рекомендуется не отключать
  // синхронизацию (или хотя бы держать в голове возможность проблем из-за
  // отключения).
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  // Перенаправление потоков cin/cout с помощью freopen
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int64_t num_test_cases;
  cin >> num_test_cases;
  for (int64_t current_case = 1; current_case <= num_test_cases;
       current_case++) // проходим по всем тест-кейсам
  {
    // cout << "Case #" << current_case << ": ";
    solve();
  }

  return 0;
}
