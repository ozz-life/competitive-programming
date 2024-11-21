// #stringstream

#include <string>
#include <iostream>

std::string reverse_words(const std::string& str) {
  std::string s;
  std::stringstream ss(str);
  std::string w;
  while (ss >> w) s = w + " " + s;
  s.pop_back();
  return s;
}

////////////////////

#include <string>

std::string reverse_words(const std::string& str) {
    std::string res = "";
    std::string buffer = "";
    for(int i = 0; i< str.length(); i++)
    {
        if(str[i]==' ') {res = buffer +" "+ res; buffer = ""; }
        else buffer+= str[i];
    }
    res = buffer +" "+ res; 
    res.pop_back();
    return res;
}

/////////////////////

#include <string>

using namespace std;

string reverse_words(const string& str) {
  string result = "";
  string temp = ""; // this
  
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == ' ')
    {
      result = temp + " " + result;
      temp = "";
    }
    else
    {
      temp += str[i];
    }
  }
  
  result = temp + " " + result;
  result.pop_back();
  
  // [1] yoda " "
  // [2] doesn't " " yoda " "
  // [3] speak " " doesn't " " yoda " "
  // [4] like " " speak " " doesn't " " yoda " "
  // [5] this " " like " " speak " " doesn't " " yoda " "
  
  return result;
}
////////////
