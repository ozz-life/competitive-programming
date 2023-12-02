#include <string>

using namespace std;

string sliceString(string str) {
  int len = str.length() - 2;
  std::string s = str.substr(1, len);
  return s;
}

////////////

#include <string>

using namespace std;

string sliceString(string str) {
  str.erase(str.begin());
  str.erase(str.length() - 1);
  return str;
}

///////////

#include <string>

using namespace std;

string sliceString(string str) {
  if (str.size() < 2)
    return str;
  str.erase(str.size() - 1).erase(0, 1);
  return str;
}

////////////

#include <string>

using namespace std;

string sliceString(string str) {
  string s;
  int size = str.length();
  for (int i = 1; i < str.length() - 1; i++)
    s += str[i];
  return s;
}