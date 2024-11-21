#include <algorithm>
#include <string>

std::string reverseString(const std::string& str) {
  return std::string(str.rbegin(), str.rend());
}

/////////////

#include <algorithm>
#include <string>

std::string reverseString(std::string str) {
  std::reverse(str.begin(), str.end());
  return str;
}

////////////

#include <string>
using namespace std ; 

string reverseString (string ss )
{
  
	string s = "";
	for (int i = ss.length()-1; i >= 0; i--)
	{
		s = s + ss[i];
	}
	
	cout << s;

  return s ;
}