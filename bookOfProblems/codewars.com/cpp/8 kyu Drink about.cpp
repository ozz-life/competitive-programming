#include <string>

std::string people_with_age_drink(int age) {
  if (age < 14)
    return "drink toddy";
  else if (age < 18)
    return "drink coke";
  else if (age < 21)
    return "drink beer";
  else if (age >= 21)
    return "drink whisky";
}

//////////////////

#include <string>

std::string people_with_age_drink(int age) {

  switch (age) {

  case 0 ... 13:
    return "drink toddy";

  case 14 ... 17:
    return "drink coke";
  case 18 ... 20:
    return "drink beer";
  case 21 ... 90:
    return "drink whisky";
  }

  return "";
}

////////////////////

#include <string>

std::string people_with_age_drink(int age) {
  
  switch(age){
      
      case 0 ... 13: return "drink toddy";
      
      case 14 ... 17: return "drink coke";
      case 18 ... 20: return "drink beer";
      case 21 ... 90: return "drink whisky";
  }
  
  
  return "";
}