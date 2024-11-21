#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> findPrefixSums2D(vector<vector<int>> &a) {
  int n = a.size();
  int m = a[0].size();
  vector<vector<int>> b(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      b[i + 1][j + 1] = b[i][j + 1] + b[i + 1][j] - b[i][j] + a[i][j];
    }
  }
  return b;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  
  vector<vector<int>> prefixSums = findPrefixSums2D(arr);
  int queriesNumber;
  cin >> queriesNumber;
  for (int i = 0; i < queriesNumber; i++) {
    int lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;
    lx--;
    ly--;
    cout << prefixSums[rx][ry] - prefixSums[lx][ry] - prefixSums[rx][ly] +
                prefixSums[lx][ly]
         << '\n';
  }
}