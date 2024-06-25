std::vector<int> divisible_by(std::vector<int> numbers, int divisor) {
  std::vector<int> v;
  for (auto &i : numbers) {
    if (i % divisor == 0) {
      v.push_back(i);
    }
  }

  return v;
}

std::vector<int> divisible_by(std::vector<int> nums, int d) {
  nums.erase(
      std::remove_if(nums.begin(), nums.end(), [d](int n) { return (n % d); }),
      nums.end());
  return nums;
}