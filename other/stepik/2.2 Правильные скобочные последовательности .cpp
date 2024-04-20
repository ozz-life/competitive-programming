#include <iostream>
#include <vector>

// Заметим, что на любом начальном отрезке (или, как говорят, на префиксе)
// правильной скобочной последовательности число открывающихся скобок не меньше
// числа закрывающихся.

bool correct(std::string s) {
  int balance = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == '(') {
      balance++;
    } else {
      balance--;
    }
    if (balance < 0)
      // Если баланс отрицательный — критерий нарушился, и наша скобочная
      // последовательность неправильная. Функция возвращает значение false.
      return false;
  }
  // В конце мы проверяем, что баланс равен нулю, то есть общее число
  // открывающихся скобок совпадает с числом закрывающихся.
  return (balance == 0);
}

int n;
std::vector<char> s;

void out() {
  for (int i = 0; i < 2 * n; i++) {
    std::cout << s[i];
  }
  std::cout << std::endl;
}

void recursive(int idx, int balance) {
  if (idx == 2 * n) {
    if (balance == 0)

    {
      for (int i = 0; i < 2 * n; i++) {
        std::cout << s[i];
      }
      std::cout << "\n";
    }

    return;
  }

  s[idx] = '(';
  recursive(idx + 1, balance + 1);
  if (balance == 0)
    return;
  s[idx] = ')';
  recursive(idx + 1, balance - 1);
}

int main() {
  n = 8; // Задайте значение n
  s.assign(2 * n, ' ');

  recursive(0, 0);
  // std::cout << correct("()(()()))");

  return 0;
}