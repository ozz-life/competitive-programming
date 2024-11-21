#include <string>

std::string number_to_string(int num) {
  return std::to_string(num);
}

///////////////

#include <string>
#include <sstream>

std::string number_to_string(int num) {
      std::string s;
      std::stringstream ss;
      ss << num;
      ss >> s;
      return s;
}

