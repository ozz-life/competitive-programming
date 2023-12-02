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
          Author: Stanislav "Oz" Ozeransky | Site: https:://ozz.life/

We are what we think.
All that we are arises with our thoughts.
With our thoughts we make the world.
Speak or act with a pure mind
And happiness will follow you
As your shadow, unshakable. ― Gautama Buddha

*/

#include <climits>
#include <iostream>
#include <vector>

class HamiltonianCycleSolver {
private:
  int n;
  std::vector<std::vector<int>> adjacencyMatrix;
  std::vector<int> currentPath;
  int shortestCycleLength;

public:
  HamiltonianCycleSolver() : shortestCycleLength(INT_MAX) {}

  bool canExtendPath(int vertex, int position) {
    if (adjacencyMatrix[currentPath[position - 1]][vertex] == 0) {
      return false;
    }

    for (int i = 0; i < position; i++) {
      if (currentPath[i] == vertex) {
        return false;
      }
    }

    return true;
  }

  void findShortestHamiltonianCycleUtil(int position, int currentLength) {
    if (position == n) {
      if (adjacencyMatrix[currentPath[position - 1]][currentPath[0]] > 0) {
        int cycleLength =
            currentLength +
            adjacencyMatrix[currentPath[position - 1]][currentPath[0]];
        shortestCycleLength = std::min(shortestCycleLength, cycleLength);
      }
      return;
    }

    for (int vertex = 1; vertex < n; vertex++) {
      if (canExtendPath(vertex, position)) {
        currentPath[position] = vertex;
        findShortestHamiltonianCycleUtil(
            position + 1,
            currentLength + adjacencyMatrix[currentPath[position - 1]][vertex]);
        currentPath[position] = -1;
      }
    }
  }

  int findShortestHamiltonianCycle() {
    currentPath.resize(n + 1, -1);
    currentPath[0] = 0;

    findShortestHamiltonianCycleUtil(1, 0);

    return (shortestCycleLength == INT_MAX) ? -1 : shortestCycleLength;
  }

  void solve() {
    std::cin >> n;
    adjacencyMatrix.resize(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        std::cin >> adjacencyMatrix[i][j];
      }
    }

    if (n == 1) {
      std::cout << 0 << std::endl;
      return;
    }

    std::cout << findShortestHamiltonianCycle() << std::endl;
  }
};

int main() {
  HamiltonianCycleSolver solver;
  solver.solve();

  return 0;
}