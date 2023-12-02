#include <string>

std::string switch_it_up(int number) {
  std::string name = number == 0   ? "Zero"
                     : number == 1 ? "One"
                     : number == 2 ? "Two"
                     : number == 3 ? "Three"
                     : number == 4 ? "Four"
                     : number == 5 ? "Five"
                     : number == 6 ? "Six"
                     : number == 7 ? "Seven"
                     : number == 8 ? "Eight"
                     : number == 9 ? "Nine"
                                   : "Wrong number";

  return name;
}

///////////////////

#include <bits/stdc++.h>

using namespace std;

string switch_it_up(int number)
{
    switch (number) {
        case 0: return "Zero";
        case 1: return "One";
        case 2: return "Two";
        case 3: return "Three";
        case 4: return "Four";
        case 5: return "Five";
        case 6: return "Six";
        case 7: return "Seven";
        case 8: return "Eight";
        case 9: return "Nine";
        default: return "";
    }
}