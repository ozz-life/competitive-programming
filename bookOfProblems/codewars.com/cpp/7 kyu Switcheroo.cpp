#include <string>

std::string switcheroo(const std::string &s) {
  std::string result = s;

  for (char &c : result) {
    if (c == 'a') {
      c = 'b';
    } else if (c == 'b') {
      c = 'a';
    }
  }

  return result;
}

/////////////

#include <algorithm>
#include <string>

std::string switcheroo(const std::string &s) {
  std::string r = s;
  transform(r.begin(), r.end(), r.begin(), [](char c) {
    return c == 'a' ? 'b' : c == 'b' ? 'a' : c;
  });
  return r;
}