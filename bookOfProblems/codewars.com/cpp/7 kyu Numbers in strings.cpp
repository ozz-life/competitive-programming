#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

int solve(std::string s) {
    std::vector<std::string> v;
    std::string current_num;
  
    for (char c : s) {
        if (std::isdigit(c)) {
            current_num.push_back(c);
        } else {
            if (!current_num.empty()) {
                v.push_back(current_num);
                current_num.clear();
            }
        }
    }

    if (!current_num.empty()) {
        v.push_back(current_num);
    }

    int max_value = 0;
    for (const std::string& num_str : v) {
        int num = std::stoi(num_str);
        max_value = std::max(max_value, num);
    }

    return max_value;
}

////////////////////

int solve(std::string s){
    int max = 0;
    std::string tmp("");
    for(int i = 0; i < s.length() + 1; ++i){
        if(isdigit(s[i]))
        {
            tmp += s[i];
            continue;
        }
        if(!tmp.empty()){
            if(std::stoi(tmp) > max){
                max = std::stoi(tmp);
            } 
            tmp = "";
        }
    }
    
    return max;
}

///////////////
