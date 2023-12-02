#include <string>

std::string removeExclamationMarks(std::string str) {
  for (int i = 0; i < str.size(); ++i) {
    if ('!' == str[i]) {
      str.erase(i, 1);
      --i;
    }
  }
  
  return str;
}

////////////////

#include <string>

std::string removeExclamationMarks(std::string str){
  str.erase(std::remove(str.begin(), str.end(), '!'), str.end());
  return str;
}

///////////////

#include <string>
#include <regex>

std::string removeExclamationMarks(std::string str){
  return std::regex_replace(str, std::regex ("!"), "");
}

////////////////

using namespace std;

string removeExclamationMarks(const string &s)
{
    string r;
    for (char c : s)
        if ( '!' != c )
            r.push_back(c);
    return r;
}