#include <vector>

int square_sum(const std::vector<int> &numbers) {
  int sq = 0;
  for (auto &i : numbers) {
    sq += i * i;
  }
  return sq;
}

//////////////////

#include <numeric>
#include <vector>

int square_sum(const std::vector<int> &numbers) {
  return std::accumulate(numbers.begin(), numbers.end(), 0,
                         [](int a, int b) { return a + b * b; });
}