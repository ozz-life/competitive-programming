using namespace std;

bool is_vowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int solve(string s) {
    int current_vow = 0;
    int ans = 0;

    for (auto& c : s) {
        if (is_vowel(c)) {
            current_vow++;
            ans = max(ans, current_vow);
        } else {
            current_vow = 0;
        }
    }

    return ans;
}

//////////////

#include <string>
#include <unordered_set>
using namespace std;

int solve(string word){
  std::unordered_set<char> vowels {'a', 'e' ,'i', 'o' , 'u'};
  int longest = 0, longSub = 0;
  
	for (const char& s : word) {
    longSub = (vowels.count(s)) ? (longSub + 1) : 0;
    if (longSub > longest)
      longest = longSub;  
  }
  
  return longest;
}