int mango(int quantity, int price) {
  int q = quantity / 3;
  int qs = q * price;

  return quantity * price - qs;
}

///////////

int mango(int quantity, int price) { return (quantity - quantity / 3) * price; }

///////////

int mango(int quantity, int price) {
  int freebies = quantity / 3;
  return (quantity - freebies) * price;
}

//////////

int mango(int quantity, int price) {
  return ((quantity % 3) * price) + ((quantity / 3) * (2 * price));
}