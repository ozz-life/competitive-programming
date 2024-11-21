std::string how_much_i_love_you(int nb_petals) {
  switch (nb_petals % 6) {
  case 0:
    return "not at all";
  case 1:
    return "I love you";
  case 2:
    return "a little";
  case 3:
    return "a lot";
  case 4:
    return "passionately";
  case 5:
    return "madly";
  default:
    return "I don't";
  }
}

///////////////

std::string how_much_i_love_you(int nb_petals) {
  static const std::vector<std::string> sentences{
      "I love you", "a little", "a lot", "passionately", "madly", "not at all"};

  return sentences[(nb_petals - 1) % sentences.size()];
}