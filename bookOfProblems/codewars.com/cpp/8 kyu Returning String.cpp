#include <string>

std::string greet(const std::string& n){
  std::string s1 = "Hello, ", s2 = " how are you doing today?";
  return s1 + n + s2;
}

//////////////

std::string greet(const std::string& n) {return "Hello, " + n + " how are you doing today?";}

///////////////

using namespace std;
std::string greet(const std::string& n){
  string greet = "Hello, <name> how are you doing today?";
  return (greet.replace(7, 6, n));
}
////////////////


#include <sstream>
using namespace std;

std::string greet(const std::string& n){
  ostringstream oss;
  oss << "Hello, " << n << " how are you doing today?";
  return oss.str();
}