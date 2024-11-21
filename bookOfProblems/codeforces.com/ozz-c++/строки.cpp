c++ 17

string.erase(std::remove_if(string.begin(), string.end(), [](unsigned char x)
                            { return std::isspace(x); }),
             string.end());

c++ 20

std::erase(str, ' ');