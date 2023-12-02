#include <string>
#include <regex>

std::string correct(std::string str){
  str = std::regex_replace(str, std::regex("5"), "S");
  str = std::regex_replace(str, std::regex("0"), "O");
  str = std::regex_replace(str, std::regex("1"), "I");
  
  return str;
}

////////////

#include <string>

std::string correct(std::string str){
  replace(str.begin(), str.end(), '5', 'S');
  replace(str.begin(), str.end(), '0', 'O');
  replace(str.begin(), str.end(), '1', 'I');
  return str;
}

///////////

#include <string>
#include <algorithm>

std::string correct(std::string str){
for(size_t i=0; i<str.size(); i++)
{
  switch (str[i])
  {
    case '1': str[i]='I'; break; 
    case '0': str[i]='O'; break; 
    case '5': str[i]='S'; break; 
  }
}
return str;
}

//////////

#include <string>

std::string correct(std::string str){
  for(auto &i: str){
    if(i == '1') i = 'I';
    else if(i == '0') i = 'O';
    else if(i == '5') i = 'S';
  }
  return str;
}

/////////////

#include <string>

std::string correct(std::string str)
{
  std::map<char, char> corrections{ {'5', 'S'}, {'0', 'O'}, {'1', 'I'} };
  for(auto& c : str)
  {
    for(auto const cor : corrections)
      if(c == cor.first)
      {
        c = cor.second;
        break;
      }
  }
  return str;
}