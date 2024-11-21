#include <vector>

int sum(std::vector<int> nums) {
  int sum = 0;
  for(auto& i : nums) {
    sum += i;
  }
  return sum;
}

//////////////////

#include <vector>
#include <numeric>

int sum(std::vector<int> nums) {
  return std::accumulate(nums.begin(), nums.end(), 0);
}