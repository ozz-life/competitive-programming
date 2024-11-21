// #include <vector>
// #include <string>

// std::string twoSort(std::vector<std::string> s)
// {
//     std::sort(s.begin(), s.end());
//     std::string result;
//     int length = s[0].size();
//     for(int i = 0; i < length; ++i) {
//       result += s[0][i];
//       result += "***";
//     }
//     result.pop_back();
//     result.pop_back();
//     result.pop_back();

    
//     return result;
// }

////////////////////////////////////////////////////////////////////////////////

// #include <algorithm>
// #include <string>

// using namespace std;

// std::string twoSort(std::vector<std::string> s)
// {
//     string result = *min_element(s.begin(), s.end());
//     for (int i = 1; i < result.size(); i += 4)
//       result.insert(i, "***");
//     return result;
// }

////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string twoSort(vector<string> s)
{
    sort(s.begin(), s.end());

    string str = s[0];
    string answer;

    for(char &s: str)
    {
        answer.push_back(s);
        answer.push_back('*');
        answer.push_back('*');
        answer.push_back('*');
    }
    
    return answer.substr(0, answer.length() - 3);
}