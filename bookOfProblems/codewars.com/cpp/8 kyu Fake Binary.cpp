std::string fakeBin(const std::string &s) {
  std::string result = s;

  std::transform(result.begin(), result.end(), result.begin(), [](char c) {
    if (std::isdigit(c) && c >= '5') {
      return '1';
    } else if (std::isdigit(c)) {
      return '0';
    } else {
      return c;
    }
  });

  return result;
}

//////////////

#include <string>

std::string fakeBin(std::string str) {
  for (int i = 0; i < str.length(); i++) {
    str[i] = ((str[i] - '0') > 4) ? '1' : '0';
  }
  return str;
}

std::string fakeBin(std::string str) {
  std::transform(str.cbegin(), str.cend(), str.begin(),
                 [](auto const &c) { return c >= '5' ? '1' : '0'; });
  return str;
}

/////////////////

#include <regex>
#include <string>
using namespace std;
string fakeBin(string str) {
  str = regex_replace(str, regex("[1234]"), "0");
  str = regex_replace(str, regex("[56789]"), "1");
  return str;
}