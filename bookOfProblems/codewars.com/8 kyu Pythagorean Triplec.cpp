bool PythagoreanTriple(const int a, const int b, const int c) {
  if (a * a + b * b == c * c)
    return true;
  else if (a * a + c * c == b * b)
    return true;
  else if (b * b + c * c == a * a)
    return true;
  else
    return false;
}