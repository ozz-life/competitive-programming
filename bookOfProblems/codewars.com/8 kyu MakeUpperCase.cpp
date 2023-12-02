#include <string>
#include <algorithm>

std::string makeUpperCase (const std::string& input_str)
{
  std::string str = input_str;
  std::transform(str.begin(), str.end(),str.begin(), ::toupper);
  return str;
}

//////////

#include <string>

std::string makeUpperCase (const std::string& input_str)
{
  std::string temp = input_str;
  for(int i = 0; i < temp.length(); i++){
    temp[i] = toupper(temp[i]);
  }
  return temp;
}

///////////

std::string str_toupper(std::string &s) {
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c) { return std::toupper(c); });
  return s;
}

////////////

