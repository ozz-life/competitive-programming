#include <iostream>
#include <vector>

using namespace std;

/*
 * Scanning/printing the whole vector in a single std::cin/std::cout
 ******************************************************************************/

template <typename T> istream &operator>>(istream &in, vector<T> &a) {
  for (auto &x : a)
    in >> x;
  return in;
};

template <typename T> ostream &operator<<(ostream &out, vector<T> &a) {
  for (auto &x : a)
    out << x << ' ';
  return out;
};

std::vector<int> findPrefixSums(const std::vector<int> &a) {
  int n = a.size();
  std::vector<int> prefixSums(n + 1, 0);
  for (int i = 0; i < n; i++) {
    prefixSums[i + 1] = prefixSums[i] + a[i];
  }
  return prefixSums;
}

class Solution {
public:
    int pivotInteger(int n) {
        std::vector<int> v;
		for (int i = 1; i <= n; ++i) {
			v.push_back(i);
		}
		std::vector<int> pref_sum = findPrefixSums(v);
		// Верните что-то из функции, например, первый элемент префиксных сумм:
		return pref_sum[1];
    }
};

int main () {
	Solution sol;
	int result = sol.pivotInteger(2);
	std::cout << "Result: " << result << std::endl;
	return 0;
}