bool amIWilson(unsigned n) {
  if (n == 5 or n == 13 or n == 563)
    return true;
  else
    return false;
}

///////////////

bool isPrime(unsigned n) {
  if (n < 2)
    return false;
  for (int i = 2; i < n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}
bool amIWilson(unsigned n) {
  if (!isPrime(n))
    return false;
  unsigned rst = 1;
  for (unsigned i = 2; i < n; i++)
    rst = rst * i % (n * n);
  return rst == n * n - 1;
}