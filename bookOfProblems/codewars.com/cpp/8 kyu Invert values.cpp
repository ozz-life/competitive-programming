#include <vector>

std::vector<int> invert(std::vector<int> values)
{
  for(int i = 0; i < values.size(); ++i) {
    values[i] *= -1;
  }
    return values;
}

/////////////

#include <vector>
#include <algorithm>

std::vector<int> invert(std::vector<int> values)
{
    transform(values.begin(), values.end(), values.begin(), std::negate<int>());;
    return values;