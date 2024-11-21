#include <vector>
int grow(std::vector<int> nums) {
  int sum = 1;
  for(auto&i : nums) {
    sum *= i;
  }
  return sum;
}

/////////////////

#include <vector>
#include <numeric>
#include <functional>

int grow(const std::vector<int>& nums) {
  return std::accumulate(nums.cbegin(), nums.cend(), 1, std::multiplies<int>());
}