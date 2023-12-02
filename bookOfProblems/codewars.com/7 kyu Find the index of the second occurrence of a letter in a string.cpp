#include <string>

int secondSymbol(const std::string &str, char symbol) {
  int first = str.find(symbol);
  if (first != std::string::npos) {
    int second = str.find(symbol, first + 1);
    if (second != std::string::npos) {
      return second;
    }
  }
  return -1;
}

//////////////

#include <string>

int secondSymbol(const std::string &str, char symbol) {
  return str.find(symbol, str.find(symbol) + 1);
}

///////////////////

#include <algorithm>
#include <string_view>

int secondSymbol(std::string_view haystack, char needle) {
  auto it = std::find(begin(haystack), end(haystack), needle);
  if (it != end(haystack))
    it = std::find(it + 1, end(haystack), needle);
  return it != end(haystack) ? it - begin(haystack) : -1;
}

/////////////////

#include <string>

int secondSymbol(const std::string &str, char symbol) {
  bool secondTime = false;
  for (int i = 0; i < (int)str.size(); ++i) {
    if (str[i] == symbol && secondTime)
      return i;

    else if (str[i] == symbol)
      secondTime = true;
  }

  return -1;
}