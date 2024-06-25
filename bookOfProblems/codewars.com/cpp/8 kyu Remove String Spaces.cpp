#include <string>

std::string no_space(const std::string& x)
{
  std::string s = x;
  
  for(int i = 0; i < s.size(); ++i) {
   if (' ' == s[i]) {
     s.erase(i, 1);
     --i;
   }
  }
  
   return s;
}

///////////////

std::string no_space(std::string x)
{
    x.erase(std::remove(x.begin(), x.end(), ' '), x.end());
    return x;
}

///////////////

#include <string>
#include <regex>

std::string no_space(std::string s)
{
  return std::regex_replace(s, std::regex(" "), "");
}

///////////////

std::string no_space(std::string x)
{
    std::string result = "";
    for (char c: x) {
        if (c != ' ') 
            result += c;
    }
    return result;
}

///////////////

