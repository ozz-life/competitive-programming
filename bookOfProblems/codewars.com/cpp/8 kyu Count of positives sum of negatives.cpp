#include <vector>

std::vector<int> countPositivesSumNegatives(std::vector<int> input)
{
  int count = 0;
  int sum = 0;
  std::vector<int> v;
  for(auto&i : input) {
    if (i > 0) count++;
    if (i < 0) sum += i;
  }
  
  v.push_back(count);
  v.push_back(sum);
  
  if(count == 0 && sum == 0) {
    v.clear();
  }
  return v;
}