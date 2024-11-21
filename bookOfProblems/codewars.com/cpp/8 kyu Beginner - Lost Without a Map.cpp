std::vector<int> maps(const std::vector<int> & values) {
  std::vector<int> v = values;
  for(auto& i : v) {
    i *= 2;
  }
  return v;
}

/////////////////////

