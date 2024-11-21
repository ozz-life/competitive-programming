#include <numeric>
#include <vector>
using namespace std;

int sum(vector<int> numbers) {
  std::vector<int> v;
  std::sort(numbers.begin(), numbers.end());
  int len = numbers.size() - 1;
  for (int i = 1; i < len; ++i) {
    v.push_back(numbers[i]);
  }

  return std::accumulate(v.begin(), v.end(), 0);
}

////

#include <vector>
using namespace std;

int sum(vector<int> numbers) {
  if (numbers.size() < 2)
    return 0;
  int sum = 0;
  int low = numbers[0], high = numbers[0];
  for (int n : numbers) {
    if (n < low)
      low = n;
    else if (n > high)
      high = n;
    sum += n;
  }
  return sum - high - low;
}

////////////////

#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int sum(vector<int> numbers) {
  if (numbers.size() <= 1)
    return 0;
  return accumulate(numbers.begin(), numbers.end(), 0) -
         *max_element(numbers.begin(), numbers.end()) -
         *min_element(numbers.begin(), numbers.end());
}

////////////////

#include <algorithm>
#include <numeric>
#include <vector>

int sum(std::vector<int> numbers) {
  if (numbers.size() < 2)
    return 0;
  auto minmax = std::minmax_element(numbers.begin(), numbers.end());
  return std::accumulate(numbers.begin(), numbers.end(), 0) - *minmax.first -
         *minmax.second;
}