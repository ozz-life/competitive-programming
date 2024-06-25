#include <string>

bool feast(std::string beast, std::string dish){
  char f1 = beast.at(0);
  char e1 = beast.back();
  char f2 = dish.at(0);
  char e2 = dish.back();
  
  return (f1 == f2 && e1 == e2); 
}

////////////////

#include <string>

bool feast(std::string beast, std::string dish){
  return beast.front()==dish.front() && beast.back()==dish.back();
}

///////////////////

