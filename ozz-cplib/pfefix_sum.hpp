std::vector<int> findPrefixSums(const vector<int> &a) {
  int n = a.size();
  std::vector<int> prefixSums(n + 1, 0);
  for (int i = 0; i < n; i++) {
    prefixSums[i + 1] = prefixSums[i] + a[i];
  }
  return prefixSums;
}

int getSum(const vector<int> &prefix_sum, const int &l, const int &r) {
  return prefix_sum[r] - prefix_sum[l];
}

std::vector<std::vector<int>>
findPrefixSums2D(std::vector<std::vector<int>> &a) {
  int n = a.size();
  int m = a[0].size();
  std::vector<std::vector<int>> prefixSum(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      prefixSum[i + 1][j + 1] =
          prefixSum[i][j + 1] + prefixSum[i + 1][j] - prefixSum[i][j] + a[i][j];
    }
  }
  return prefixSum;
}

/// возможно дефектная, но тесты проходит
std::vector<int> calculateTotalAscents(const vector<int> &a) {
  int n = a.size();
  std::vector<int> prefixSums(n + 1);
  prefixSums[0] = 0;
  for (int i = 0; i < n; ++i) {
    prefixSums[i + 1] = prefixSums[i];
    int difference = a[i] - a[i - 1];
    if (difference > 0)
      prefixSums[i + 1] += difference;
  }
  return prefixSums;
}

////////////////////

#ifndef __PREFSUMS_HPP__
#define __PREFSUMS_HPP__

namespace algos {
namespace prefsums {

template <typename T> class PrefSums {
private:
  std::vector<T> pref;

public:
  PrefSums(const std::vector<T> &a) {
    pref = {0};
    for (auto it : a)
      pref.push_back(pref.back() + it);
  }

  T operator()(int l, int r) const { return l > r ? 0 : pref[r + 1] - pref[l]; }
};

////////

template <typename T> class PrefIncs {
private:
  std::vector<T> data;

public:
  PrefIncs(int n) : data(n + 1, T{}) {}

  void inc(int l, int r, T x) {
    data[l] += x;
    data[r + 1] -= x;
  }

  void build() {
    for (int i = 1; i < (int)data.size(); i++)
      data[i] += data[i - 1];
  }

  T operator[](int i) const { return data[i]; }
};

} // namespace prefsums
} // namespace algos

#endif // __PREFSUMS_HPP__