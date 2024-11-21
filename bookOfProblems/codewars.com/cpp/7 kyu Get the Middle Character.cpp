std::string get_middle(std::string input) {
  if (input.length() % 2 == 0) {
    return input.substr(input.length() / 2 - 1, 2);
  } else {
    return input.substr(input.length() / 2, 1);
  }
}

/////////////////

std::string get_middle(std::string input) 
{
  int i = input.length();

	if ((i % 2) == 0) 
		return input.substr(i/2 - 1, 2);
    
  else
	  return input.substr(i/2, 1);
}