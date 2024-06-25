#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> flip(const char dir, const std::vector<int>& arr) {
    std::vector<int> sorted_arr = arr;

    if (dir == 'R') {
        std::sort(sorted_arr.begin(), sorted_arr.end());
    } else {
        std::sort(sorted_arr.rbegin(), sorted_arr.rend());
    }
    return sorted_arr;
}

////////////////////

#include <vector>

std::vector<int> flip(const char dir, std::vector<int> arr) {
    if(dir == 'R')
      sort(arr.begin(),arr.end());
    else
      sort(arr.rbegin(),arr.rend());
    return arr;
}
