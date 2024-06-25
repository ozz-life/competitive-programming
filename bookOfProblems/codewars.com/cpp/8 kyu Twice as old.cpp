#include <cmath>

int twice_as_old(int dad, int son) {
  // f - x = 2 * (s - x)
  // f - x = 2s -2x
  // x = 2s - f
  return std::abs(dad - 2 * son);
}