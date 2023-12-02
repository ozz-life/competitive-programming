#include <string>
#include <algorithm>

bool isPalindrom(const std::string &str)
{
    std::string temp = str;
    std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);

    bool result = false;
    int l = 0;
    int r = temp.size() - 1;
    while (l < r) {
        if (temp[l] == temp[r])
            result = true;
        else
            return false;
        l++;
        r--;
    }

    return true;
}

/////////////////////////

#include <string>

bool isPalindrom (const std::string& str) {
  std::string lstr = str;
  for (char& c : lstr) c = toupper(c);
  return lstr == std::string(lstr.rbegin(), lstr.rend());
}

////////////////////////////

#include <string>

bool isPalindrom (const std::string& str) {
  std::string::size_type slen = str.size();
  for(std::string::size_type i=0;i<slen/2;i++)
    if(std::tolower(str[i]) != std::tolower(str[slen-i-1])) return false;
  return true;
}

//////////////////////////
