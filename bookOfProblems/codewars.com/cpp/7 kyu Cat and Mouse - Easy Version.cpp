#include <string>
#include <cmath>

std::string cat_mouse(std::string x) 
{
  return abs((int)x.find('m') - (int)x.find('C')) < 5 ? "Caught!" : "Escaped!";
}

