#include <string>
#include <vector>

std::vector<int> digitize(unsigned long n) 
{        
  std::string s = std::to_string(n);
  std::vector<int> v;
  for(int i = s.size() - 1; i >= 0; i--) {
        int digit = s[i] - '0';  // Convert character to integer
        v.push_back(digit);
  }
  return v;
}

//////////////////////////////////

std::vector<int> digitize(unsigned long n) 
{     
    std::vector<int> digits;
   
    do {
        digits.push_back (n % 10);
        n /= 10;
    } while (n > 0);
   
    return digits;
}