#include <vector>

int get_average(std::vector <int> marks)
{
  int sum = 0;
for(int i = 0; i < marks.size(); ++i) {
  sum += marks[i];
}
  int average = sum / marks.size();
  return average;
}

////////////////

#include <vector>
#include <numeric>

int get_average(std::vector <int> marks)
{
  return accumulate(marks.begin(), marks.end(), 0) / marks.size();
}