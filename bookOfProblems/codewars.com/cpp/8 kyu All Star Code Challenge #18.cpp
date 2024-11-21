#include <bits/ranges_algo.h>
#include <string>
#include <ranges>

unsigned int strCount(const std::string& word, char letter){
  auto count = std::ranges::count(word, letter);
  return count;
}

//////////

#include <string>

unsigned int strCount(const std::string& word, char letter){
  std::string::difference_type n = std::count(word.begin(), word.end(), letter);
  return n;
}

///////////

#include <algorithm>
#include <string>

unsigned strCount(const std::string& word, char letter) {
  return std::count(word.cbegin(), word.cend(), letter);
}

/////////

#include <string>

unsigned int strCount(std::string word, char letter){
  int occurence=0;
    for(int i=0; i<word.size(); i++)
    {
        if(word.at(i) == letter) occurence++;
    }
    return occurence;
}

////////////

#include <string>

unsigned int strCount(std::string word, char letter){
  unsigned int i = 0;
  
  for(char& c : word)
    if (c == letter)
      i++;
  
  return i;
}