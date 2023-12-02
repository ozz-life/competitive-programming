int sumOfDigits(int n) {
    int ans = 0;
    while (n > 0) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int nextEven(int n) {
  return (n | 1) + 1;
}