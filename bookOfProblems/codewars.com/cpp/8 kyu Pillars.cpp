long pillars(int num_of_pillars, int distance, int width) {
  if (num_of_pillars == 1)
    return 0;
  else {
    int allDistanceMetr =
        distance * (num_of_pillars - 1); // Exclude the last pillar's width
    int allDistanceCm = allDistanceMetr * 100;
    int allWidthPillars =
        (num_of_pillars - 2) *
        width; // Exclude both the first and last pillar's width
    return allDistanceCm + allWidthPillars;
  }
}

///////////

long pillars(int n, int d, int w) {
  return n == 1 ? 0 : --n * d * 100 + --n * w;
}

/////////////

long pillars(int num_of_pillars, int distance, int width) {
  if (num_of_pillars > 1)
    return (num_of_pillars - 2) * width + (num_of_pillars - 1) * distance * 100;
  return 0;
}