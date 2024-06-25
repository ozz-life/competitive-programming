#include <vector>
#include <string>
using namespace std;

vector<string> string_to_array(const string& s) {
  vector<string> res;
  stringstream ss(s + " ");
  string word;

  while (getline(ss, word, ' ')) res.push_back(word);
  return res;
}