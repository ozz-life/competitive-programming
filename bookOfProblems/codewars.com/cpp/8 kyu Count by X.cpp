#include <vector>

std::vector<int> countBy(int x, int n) {
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = x * (i + 1);
    }
    return v;
}

/////////////////////

#include <algorithm>
#include <vector>

std::vector<int> countBy(int x,int n){
  std::vector<int> v(n);
  std::generate(v.begin(), v.end(), [k=0, &x] () mutable {return k+=x;});
  return v;
}

///////////////////

#include <vector>
#include <numeric>
std::vector<int> countBy(int x, int n){
  std::vector<int> output(n, x);
  std::partial_sum(output.begin(), output.end(), output.begin());
  return output;
}