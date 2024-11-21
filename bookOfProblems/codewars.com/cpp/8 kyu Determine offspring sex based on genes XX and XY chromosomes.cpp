std::string chromosomeCheck(std::string sperm) {
  if("XY" == sperm) {
    return "Congratulations! You're going to have a son.";
  }
  else if("XX" == sperm) {
    return "Congratulations! You're going to have a daughter.";
  }
}