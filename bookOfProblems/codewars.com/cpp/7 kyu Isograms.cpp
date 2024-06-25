#include <map>
#include <cctype>

bool is_isogram(std::string str) {
  std::map<char, int> mp;
  
  for(auto &c : str) {
    char lowercase_c = std::tolower(c);
    if(mp.count(lowercase_c) > 0) {
      return false;
    }
    ++mp[lowercase_c];
  }

  return true;
}

//////////////

#include <cctype>
#include <unordered_set>

bool is_isogram(std::string str)
{
    std::unordered_set<char> char_set;
    for (const auto &c : str) {
        auto c_lower = std::tolower(c);
        if (char_set.count(c_lower) == 0) char_set.insert(c_lower);
        else return false;
    }
    return true;
}

////////////////

bool is_isogram(std::string str) {
  for (int i = 0; i < str.length(); i++)
	{
		for (int j = i + 1; j < str.length(); j++)
		{
			if (tolower(str[i]) == tolower(str[j]))
			{
				return false;
			}
		}
	}
	return true;
}

///////////////////

