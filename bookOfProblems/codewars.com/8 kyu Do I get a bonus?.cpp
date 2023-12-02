#include<string>
using namespace std;

string bonus_time(int salary, bool bonus)
{
    std::string s = "$";
    if (bonus == true) salary *= 10;
    
    return s += std::to_string(salary);
}

/////////////

#include<string>
using namespace std;

string bonus_time(int salary, bool bonus)
{
    return "$" + to_string(salary) + (bonus ? "0" : "");
}

//////////////

#include <string>
#include <sstream>

std::string bonus_time (int salary, bool bonus)
{
  std::ostringstream oss;
  
  oss << '$' << (bonus ? 10 * salary : salary);
  
  return oss.str();
}