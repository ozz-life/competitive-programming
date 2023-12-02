unsigned int hotpo(unsigned int n) {
  int cnt = 0;
  if (n == 0)
    return 0;
  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
      ++cnt;
    } else {
      n = 3 * n + 1;
      ++cnt;
    }
  }
  return cnt;
}

//////////

unsigned int hotpo(unsigned int n) {
  unsigned int count = 0;

  while (n > 1) {
    n = n % 2 == 0 ? n / 2 : 3 * n + 1;
    ++count;
  }
  return count;
}