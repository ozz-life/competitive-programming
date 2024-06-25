#include <vector>
#include <string>
#include <iostream>

std::vector<int> solve(const std::vector<std::string>& arr) {
  std::vector<int> v;
  for(const std::string& word : arr) {
    int cnt = 0;
    for(size_t i = 0; i < word.size(); i++) {
      char letter = std::toupper(word[i]);
      int position = letter - 65;
      if(position == i) {
        ++cnt;
      }
    }
    v.push_back(cnt);
  }
  return v;
}

/////////////////////////////

#include <cctype>
#include <string>
#include <vector>

std::vector<int> solve(std::vector<std::string> arr) {
  std::vector<int> result(arr.size());
  for (int i = 0; i < arr.size(); i++)
    for (int j = 0; j < arr[i].length(); j++)
      if (toupper(arr[i][j]) - 65 == j)
        result[i]++;
	
  return result;
}

/////////////////////

#include <vector>
#include <string>

std::vector<int> solve(std::vector<std::string> arr) {
    //your code herw
    std::vector<int> solution;
    int counter = 0;
    for (std::string word : arr) {
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == i + 97 || word[i] == i + 65) counter++;
        }
        solution.push_back(counter);
        counter = 0;
    }
    return solution;
};

//////////////////////

#include <vector>
#include <string>

std::vector<int> solve(const std::vector<std::string>& arr) {
    std::vector<int> v;
    for(auto &word : arr) {
        int ans = 0;
        for(size_t i = 0; i < word.length(); ++i) {
            if (tolower(word[i]) - 97 == i) {
                ans++;
            }
        }
        v.push_back(ans);
    }
    return v;
}