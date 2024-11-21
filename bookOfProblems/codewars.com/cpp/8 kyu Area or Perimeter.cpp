int area_or_perimeter(int l, int w) {
  if (l == w) {
    // It's a square, so return the area
    return l * w;
  } else {
    // It's a rectangle, so return the perimeter
    return 2 * (l + w);
  }
}