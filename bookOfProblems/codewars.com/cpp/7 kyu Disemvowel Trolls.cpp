# include <string>

bool is_vowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

std::string disemvowel(const std::string& str) {
  std::string s = str;
  
  for(size_t i = 0; i < s.size(); ++i) {
    if(is_vowel(s[i])) {
      s.erase(i, 1);
      i--;
      }
  }
  
  return s;
}

//////////////////

# include <string>
# include <regex>
std::string disemvowel(std::string str)
{
  std::regex vowels("[aeiouAEIOU]");
  return std::regex_replace(str, vowels, "");
}

//////////////////

#include <string>

std::string disemvowel(std::string str)
{
    for ( auto letter : "AEIOUaeiou" ) {
      str.erase(std::remove(str.begin(), str.end(), letter), str.end());
    }
    
    return str;
}

////////////////

# include <string>
# include <regex>

std::string disemvowel(std::string str)
{
    return std::regex_replace(str,static_cast<std::regex>("([AaEeIiOoUu])"),"");
}