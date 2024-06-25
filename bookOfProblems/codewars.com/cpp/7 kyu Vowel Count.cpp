#include <string>

using namespace std;

int getCount(const string& inputStr){
  int num_vowels = 0;
  for (auto &i : inputStr) {
    if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
      num_vowels++;
    }
  }
  
  return num_vowels;
}

/////////////

#include <string>

using namespace std;

bool is_vowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}


int getCount(const string& inputStr) {
  return count_if(inputStr.begin(), inputStr.end(), is_vowel);
}

///////////////

int getCount(const std::string& str){
  std::string vowels = "aeiou";
  
  return std::count_if(str.begin(), str.end(), [&vowels](char c) -> bool{
    return vowels.find(std::tolower(c)) != std::string::npos;
  });
}