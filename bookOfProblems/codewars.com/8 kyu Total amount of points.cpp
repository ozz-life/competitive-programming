#include <array>
#include <string>

int points(const std::array<std::string, 10>& games) {
  int res = 0;
  for (const std::string& g : games)
    res += g[0] > g[2] ? 3 : g[0] == g[2] ? 1 : 0;
  return res;
}

///////////////////

#include <array>
#include <string>
#include <cstdio>

int points(const std::array<std::string, 10>& games) {
    int sum = 0;
    for(int i=0; i<10; i++){
        int x, y;
        sscanf(games[i].c_str(), "%d:%d", &x, &y);
        if( x == y ) sum += 1;
        if( x > y ) sum += 3;
    }
    return sum;
}

//////////////////

#include <array>
#include <string>
#include <numeric>

int points(const std::array<std::string, 10>& games) {
  return std::accumulate(games.begin(), games.end(), 0, [](auto r, auto s) {
    if(s[0] > s[2]) return r + 3;
    if(s[0] < s[2]) return r;
    return r + 1;
  });
}

//////////////////

