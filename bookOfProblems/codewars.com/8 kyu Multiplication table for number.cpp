#include <string>

std::string multi_table(int number)
{
    std::string result;
    for (int i = 1; i <= 10; ++i) {
      result += std::to_string(i);
      result += " * ";
      result += std::to_string(number);
      result += " = ";
      result += std::to_string(i * number);
      if (i != 10) {
        result += "\n";
      }
    }
  
    return result;
}

//////////////

#include <string>
#include <sstream>

std::string multi_table(int number)
{
	std::ostringstream os;
	for (int i = 1; i <= 10; i++) {
		os << i << " * " << number << " = " << i*number << (i<10 ? "\n" : "");
	}
	return os.str();
}

//////////////////

#include <string>

std::string multi_table(int number)
{
  std::string ans;
  for (size_t i = 1; i <= 10; i++)
    ans += std::to_string(i) + " * " + std::to_string(number) + " = " + std::to_string(i*number) + "\n";
  ans.pop_back();
  return ans;
}
////////////////////

