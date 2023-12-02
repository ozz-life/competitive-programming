#include <string>

std::string sum_str(const std::string& a, const std::string& b) {
  return std::to_string(std::stoi(a == "" ? "0" : a) + std::stoi(b == "" ? "0" : b));
}
