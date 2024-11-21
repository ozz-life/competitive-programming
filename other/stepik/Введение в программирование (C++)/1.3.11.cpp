#include <iostream>

using namespace std;

int main() {
  //   int N, H, M, m, S, s;
  //   cin >> N;
  //   H = N / 3600 % 24;
  //   M = N % 3600 / 60 / 10;
  //   m = N % 3600 / 60 % 10;
  //   S = N % 3600 % 60 / 10;
  //   s = N % 3600 % 60 % 10;
  //   cout << H << ":" << M << m << ":" << S << s;

  int h, m, s, h1, m1, s1;
  cin >> h >> m >> s >> h1 >> m1 >> s1;
  
  int t1, t2;
  h = h * 3600; m = m * 60;
  t1 = h + m + s;
  
  h1 = h1 * 3600; m1 = m1 * 60;
  t2 = h1 + m1 + s1;
  
  cout << t2 - t1;
}
