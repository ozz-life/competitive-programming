#include <iostream>
using namespace std;
int main() {
  int a,b,c; cin >> a >> b >> c;
  int capacity = 2;
  a = (a + capacity - 1) / capacity;
  b = (b + capacity - 1) / capacity;
  c = (c + capacity - 1) / capacity;
  
  std::cout << a + b + c;
}