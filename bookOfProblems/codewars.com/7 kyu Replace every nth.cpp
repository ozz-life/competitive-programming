class Kata {
public:
  std::string replaceNth(std::string text, int n, char oldValue,
                         char newValue) {
    if (n <= 0 || n > oldValue)
      return text;
    else {
      int count = 0; // Счетчик вхождений oldValue.
      for (size_t i = 0; i < text.size(); ++i) {
        if (text[i] == oldValue) {
          count++;
          if (count % n == 0) {
            text[i] = newValue; // Заменить символ oldValue на newValue при
                                // каждом n-м вхождении.
          }
        }
      }

      return text;
    }
  }
};