#include <math.h>

double converter(int mpg) {
  const double imperial_gallon_to_litre = 4.54609188;
  const double mile_to_km = 1.609344;
  double result = mpg * mile_to_km / imperial_gallon_to_litre;
  return round(result * 100) / 100.00;
}