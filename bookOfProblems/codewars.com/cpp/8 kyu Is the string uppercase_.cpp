#include <string>

std::string str_toupper(std::string &s) {
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c) { return std::toupper(c); });
  return s;
}

bool is_uppercase(const std::string &s) {
  std::string s1 = s;
  str_toupper(s1);
  
  return (s1 == s ? true : false);
}

////////////

#include <string>
#include <algorithm>

bool is_uppercase(const std::string &s) {
  return std::none_of(s.begin(), s.end(), islower);
}