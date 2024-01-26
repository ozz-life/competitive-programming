#include <bits/stdc++.h>
using namespace std;
// Сделать свою pair<int,int>, но у нее первый будет не first, а, например, vert
// а второй параметр cost
// struct Edge auto [vert, cost] = pair<int,int>;
void example() {
  tuple<int, int, int> t{1, 4, 8};
  cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << endl;
  auto [_, __, ___] = t;
  cout << _ << ' ' << __ << ' ' << ___ << endl;
}
namespace KEK {
struct Edge {
  int vert, cost;
};
vector<vector<Edge>> adj;
set<int> path;

void dfs(int u, int p) {
  // ВХОД в вершину u
  // ПЕРЕБОР ИСХОДЯЩИХ РЁБЕР
  for (auto [v, cost] : adj[u]) { // C++17 или C++14??
    if (v == p)
      continue;
    // переход в дочернюю вершину v
    path.insert(cost);
    dfs(v, u);
    path.erase(cost);
    // возврат из вершины v
  }
  // ВЫХОД из вершины u
  if (path.size() > 0) {
    assert(!path.empty());
    cout << "u = " << u << ", минимальное ребро = " << *path.begin() << endl;
    cout << "u = " << u << ", максимальное ребро = " << *path.rbegin() << endl;
  }
}
} // namespace KEK

int main() {
  example();
  using namespace KEK;
  setlocale(LC_ALL, "Russian");
  int nV;
  cin >> nV;
  adj.assign(1 + nV, {});
  for (int i = 0; i < nV - 1; i++) {
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[u].push_back({v, cost});
    adj[v].push_back({u, cost});
  }
  // cout << sizeof(dfs) << endl;
  dfs(1, 0);
}