#include <algorithm>
#include <numeric>

std::vector<int> pipe_fix(const std::vector<int>& nums) {  
    auto [min, max] = std::minmax_element(nums.begin(), nums.end());
    std::vector<int> v(*max - *min + 1);
    std::iota(v.begin(), v.end(), *min);
    return v;
}

///////////////////

#include <vector>
#include <algorithm>

std::vector<int> pipe_fix(const std::vector<int>& nums) {
  int mini = *min_element(nums.begin(), nums.end());
  int maxi = *max_element(nums.begin(), nums.end());
  std::vector<int> arr;
  for(int i = mini; i <= maxi; i++){
    arr.push_back(i);
  }
  return arr;
}