int quadrant(int x, int y) {
  if(x > 0 and y > 0) return 1;
  else if(x < 0 and y > 0) return 2;
  else if(x < 0 and y < 0) return 3;
  else if(x > 0 and y < 0) return 4;
}