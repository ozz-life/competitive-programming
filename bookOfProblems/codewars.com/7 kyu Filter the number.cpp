#include <string>

long long filter_string(const std::string &value)
{
  std::string s;
   for(auto &i : value) {
     if(isdigit(i)) {
       s += i;
     }
   }
  
  try {
    return std::stoll(s);
  } catch (...) {
    // Обработка ошибки, например, можно вернуть какое-то значение по умолчанию.
    return 0;
  }
}