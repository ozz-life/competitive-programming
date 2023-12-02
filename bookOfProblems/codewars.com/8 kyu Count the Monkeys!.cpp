#include <vector>
#include <algorithm>
#include <numeric>

std::vector<int> MonkeyCount(int n) {
  std::vector<int> v;
  for(int i = 1; i <= n; ++i) {
    v.push_back(i);
  }

  return v;
}

///////////////////

#include <numeric>
#include <vector>

std::vector<int> MonkeyCount(int n) {
  std::vector<int> res(n);
  std::iota(res.begin(), res.end(), 1);
  return res;
}