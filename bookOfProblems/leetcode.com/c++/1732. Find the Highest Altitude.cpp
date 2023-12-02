std::vector<int> findPrefixSums(const vector<int> &a) {
  int n = a.size();
  std::vector<int> prefixSums(n + 1, 0);
  for (int i = 0; i < n; i++) {
    prefixSums[i + 1] = prefixSums[i] + a[i];
  }
  return prefixSums;
}

class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    std::vector<int> altitudes = findPrefixSums(gain);
    return *std::max_element(altitudes.begin(), altitudes.end());
  }
};
