#include <array>
#include <cmath>

int findDifference(std::array<int, 3> a, std::array<int, 3> b) {
  //cuboid = length × breadth × height
  int va = a[0] * a[1] * a[2];
  int vb = b[0] * b[1] * b[2];
  
  return std::abs(va - vb);
}