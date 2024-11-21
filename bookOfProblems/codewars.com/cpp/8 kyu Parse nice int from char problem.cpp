#include <string>
#include <sstream>

int get_age(const std::string& she_said) {
  std::stringstream ss(she_said);
  int age;
  ss >> age;
  return age;
}

//////////////

#include <string>
#include <sstream>
using namespace std;
int get_age(const std::string& she_said) {
  stringstream ss; int num;
      ss << (she_said[0]);
      ss >> num;
  return num;
}

//////////////

#include <string>

int get_age(const std::string& she_said) {
    return she_said[0] - '0';
}

///////////////

#include <string>

using namespace std;

int get_age(const string& she_said) {
  return stoi(she_said);
}

//////////////////