#include <vector>

int positive_sum (const std::vector<int> arr){
  int sum = 0;
  for(auto&i : arr) {
    if(i > 0) {
      sum += i;
    }
  }
  return sum;
}