#include <vector>
#include <algorithm>

using namespace std;

int sumOfDifferences(vector<int> arr){
  int sum = 0;
    sort(arr.rbegin(), arr.rend());
    if (arr.size() <= 1)
        sum = 0;
    else
        for (int i = 0; i < arr.size() - 1; i++) {
            sum += arr[i] - arr[i + 1];
        }
    return sum;
}

////////////////////////

#include <vector>
#include <algorithm>
int sumOfDifferences(const std::vector<int>& arr) {
  if (arr.empty()) return 0;
  auto p = std::minmax_element(arr.cbegin(), arr.cend());
  return *p.second - *p.first;
}

////////////////////////


#include <vector>
#include <algorithm>
int sumOfDifferences(const std::vector<int>& arr) {
  if (arr.empty()) return 0;
  auto [min, max] = std::minmax_element(arr.cbegin(), arr.cend());
  return *max - *min;
}