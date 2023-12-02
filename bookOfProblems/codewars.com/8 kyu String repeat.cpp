#include <string>

std::string repeat_str(size_t repeat, const std::string &str) {
  std::ostringstream os;
  for (int i = 0; i < repeat; i++)
    os << "str";
  return os.str();
}

//////////////

#include <string>

std::string repeat_str(size_t repeat, const std::string& str)
{
  std::string ret = "";
  while(repeat--)
    ret += str;
  return ret;
}

////////////////

#include<bits/stdc++.h>

using std::string;

string repeat_str(size_t r, const string& str) {
    string res;
    for(int i = 0; i < r; ++i) {
        res.append(str);
    }
    
    return res;
}