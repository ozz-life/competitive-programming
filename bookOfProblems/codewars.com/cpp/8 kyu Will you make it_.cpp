bool zero_fuel(uint32_t distance_to_pump, uint32_t mpg, uint32_t fuel_left)
{
  if (fuel_left * mpg >= distance_to_pump) return true;
  else return false;
}