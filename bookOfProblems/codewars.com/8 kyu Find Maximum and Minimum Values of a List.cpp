#include <vector>
#include <algorithm>
using namespace std;

int min(vector<int> list){
    std::sort(list.begin(), list.end());
    return list.front();
}

int max(vector<int> list){
    std::sort(list.begin(), list.end());
    return list.back();
}

//////////////////////

#include <vector>
#include <algorithm>
using namespace std;

int min(vector<int> list) 
{
	return *(min_element(list.begin(), list.end()));
}

int max(vector<int> list) 
{
	return *(max_element(list.begin(), list.end()));
}

/////////////////////

#include <vector>
using namespace std;

int min(vector<int> list)  {
    int currentMin = list[0];
    for (int i = 1; i < list.size(); i++) {
        if (list[i] < currentMin) {
            currentMin = list[i];
        }
    }
    return currentMin;
}

int max(vector<int> list){
        int currentMax = list[0];
        for (int i = 1; i < list.size(); i++) {
            if (list[i] > currentMax) {
                currentMax = list[i];
            }
        }
    return currentMax;
}