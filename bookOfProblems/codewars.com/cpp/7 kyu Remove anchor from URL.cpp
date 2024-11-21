#include <string>

std::string replaceAll(std::string str) {
    size_t pos = str.find('#');
    if (pos != std::string::npos) {
        str.erase(pos);
    }
    return str;
}

///////////////

std::string replaceAll(std::string str) {
  return str.substr(0, str.find('#'));
}
///////////////

