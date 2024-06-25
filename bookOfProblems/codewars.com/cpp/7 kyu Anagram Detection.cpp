#include <map>
#include <string>

bool isAnagram(std::string test, std::string original) {
  std::map<char, int> mpT, mpO;
  for (auto &c : test) {
    ++mpT[tolower(c)];
  }
  for (auto &c : original) {
    ++mpO[tolower(c)];
  }

  return mpT == mpO;
}

////////////////////////////////////////

#include <cctype>
#include <map>
#include <string>

bool isAnagram(std::string test, std::string original) {
  std::map<char, unsigned> map_to_test;
  for (char &c : test + original)
    map_to_test[std::toupper(c)]++;
  for (const auto &[k, v] : map_to_test)
    if (v % 2)
      return false;
  return true;
}

////////////////////////////////////////

#include <string>

bool isAnagram(std::string t, std::string o) {

  if (t.size() != o.size())
    return false;

  std::transform(t.begin(), t.end(), t.begin(), ::tolower);
  std::transform(o.begin(), o.end(), o.begin(), ::tolower);
  std::sort(t.begin(), t.end());
  std::sort(o.begin(), o.end());

  return t == o;
}

//////////////////////////////////////////
