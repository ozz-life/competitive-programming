int duty_free(int price, int discount, int holiday_cost) {
  double savings_per_bottle = price * discount / 100.0;
  return holiday_cost / savings_per_bottle;
}

//////////

int duty_free(int price, int discount, int holiday_cost) {
 return holiday_cost * 100 /(price * discount);
}