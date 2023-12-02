#include <algorithm>
#include <string>
#include <vector>

bool check(const std::vector<std::string> &seq, const std::string &elem) {
  auto it = std::find(seq.begin(), seq.end(), elem);

  return (it != seq.end());
}

//////////

#include <string>
#include <vector>

bool check(const std::vector<std::string> &seq, const std::string &elem) {
  return std::find(seq.begin(), seq.end(), elem) != seq.end();
}

/////////

bool check(const std::vector<std::string> &seq, const std::string &elem) {
  for (auto i : seq)
    if (i == elem)
      return 1;
  return 0;
}

//////////

#include <string>
#include <vector>

bool check(const std::vector<std::string> &seq, const std::string &elem) {
  return std::any_of(seq.begin(), seq.end(),
                     [&elem](const auto &str) { return str == elem; });
}