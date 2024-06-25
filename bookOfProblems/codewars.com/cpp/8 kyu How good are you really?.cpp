#include <vector>

bool betterThanAverage(std::vector<int> classPoints, int yourPoints) {
  double sum = 0;
  for(int i = 0; i < classPoints.size(); ++i) {
    sum += classPoints[i];
  }
  int average = sum / classPoints.size();
  return (yourPoints > average ? true : false);
}

///////////

#include <vector>
#include <numeric>

bool betterThanAverage(const std::vector<int>& classPoints, const int yourPoints) {
  return std::accumulate(classPoints.cbegin(), classPoints.cend(), 0) < classPoints.size() * yourPoints;
}