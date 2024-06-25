#include <bits/stdc++.h>
using namespace std;

std::string countSheep(int number)
{
  std::string s;
  for(int i = 1; i <= number; ++i) {
    s += std::to_string(i);
    s += " sheep...";
  }
  
  return s;
};

////////////////

#include <string>

std::string countSheep(int number) {
  std::string res = "";
  for (int i = 1; i <= number; ++i) 
    res += std::to_string(i) + " sheep...";
  return res;
}

////////////////

#include <string>

std::string countSheep(int number) {
  return number ? countSheep(number - 1) + std::to_string(number) + " sheep..." : "";
}

///////////////

#include <sstream>
#include <string>

std::string countSheep(int n) {
  std::stringstream ss;
  for (int i = 1; i <= n; i++) {
    ss << i << " sheep...";
  }
  return ss.str();
}

////////////////////

#include <string>

std::string countSheep(int number) {
  std::stringstream return_string;
  
  for (size_t i = 1; i <= number; ++i) {
    return_string << i << " sheep...";
  }
  
  return return_string.str();
}