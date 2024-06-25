#include <vector>

double calcAverage(const std::vector<int>& values){
  int sum = 0;
  for(int i = 0; i < values.size(); ++i) {
    sum += values[i];
  }
  return static_cast<double>(sum) / values.size();
}

////////////////

#include <vector>
#include <numeric>
using namespace std; 

double calcAverage(const vector<int>& values){
  return accumulate(values.begin(),values.end(), 0.0) / values.size();
}