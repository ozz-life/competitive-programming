#include <string>

bool validParentheses(const std::string& str) {
  int balance = 0;
  for(size_t i = 0; i < str.size(); ++i) {
    if(str[i] == '(') balance++;
    else {
      balance--;
    }
    if(balance < 0) return false;
  }
  return balance == 0; // return !balance;
}