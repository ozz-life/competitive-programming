#include <array>
#include <string>
#include <algorithm>

std::array<std::string, 3> fixTheMeerkat(std::array<std::string, 3> arr) {
  std::reverse(arr.begin(), arr.end());
  return arr;
}

//////////////////

#include <array>
#include <string>
#include <algorithm>

std::array<std::string, 3> fixTheMeerkat(std::array<std::string, 3> arr) {
  swap(arr[0], arr[2]);
  return arr;
}