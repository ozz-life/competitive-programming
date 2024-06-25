#include <string>

std::string abbrevName(std::string name)
{
  std::string ret;
  ret.push_back(toupper(name[0]));
  ret.push_back('.');
  ret.push_back(toupper(name[name.find(' ') + 1] ));
  return ret;
}

//////////

std::string abbrevName(std::string name)
{
  name.erase(1, name.find(' ')).erase(2).insert(1, ".");
  for (auto & c: name) c = toupper(c);
  return name;
}