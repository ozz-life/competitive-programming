#include <string>

std::string rps(const std::string &p1, const std::string &p2) {
  if (p1 == p2)
    return "Draw!";
  else if (p1 == "scissors" and p2 == "paper")
    return "Player 1 won!";
  else if (p1 == "paper" and p2 == "rock")
    return "Player 1 won!";
  else if (p1 == "rock" and p2 == "scissors")
    return "Player 1 won!";
  else if (p2 == "scissors" and p1 == "paper")
    return "Player 2 won!";
  else if (p2 == "paper" and p1 == "rock")
    return "Player 2 won!";
  else if (p2 == "rock" and p1 == "scissors")
    return "Player 2 won!";
}

///////

#include <string>

std::string rps(const std::string &p1, const std::string &p2) {
  if (p1 == p2)
    return "Draw!";
  if ((p1[0] == 's' && p2[0] == 'p') || (p1[0] == 'p' && p2[0] == 'r') ||
      (p1[0] == 'r' && p2[0] == 's'))
    return "Player 1 won!";
  return "Player 2 won!";
}

///////

#include <string>
#include <unordered_map>

namespace {
std::unordered_map<std::string, std::string> win_map = {
    {"rock", "scissors"}, {"scissors", "paper"}, {"paper", "rock"}};
}

std::string rps(const std::string &p1, const std::string &p2) {
  if (p1 == p2) {
    return "Draw!";
  }

  if (win_map[p1] == p2) {
    return "Player 1 won!";
  } else {
    return "Player 2 won!";
  }
}