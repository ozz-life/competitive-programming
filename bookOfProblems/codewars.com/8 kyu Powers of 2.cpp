#include <cmath>
#include <cstdint>
#include <vector>

std::vector<uint64_t> powers_of_two(int n) {
  std::vector<uint64_t> v;
  for (int i = 0; i <= n; ++i) {
    v.push_back(std::pow(2, i));
  }

  return v;
}

////////////////////

#include <vector>
#include <cstdint>

std::vector<uint64_t> powers_of_two(int n) {
  std::vector<uint64_t> v;
  uint64_t t = 1;
  for (int i = 0; i <= n; ++i) {
    v.push_back(t);
    t = t << 1;
  }
  return v;
}

//////////////////

#include <vector>
#include <cstdint>

std::vector<uint64_t> powers_of_two(int n) {
    std::vector<uint64_t> res;
    for(uint64_t i = 1; n + 1; i <<= 1, --n) res.push_back(i);
    return res;
}