
#include <iostream>

int main() {
  int i1 = 1;
  std::cout << "i1= " << i1 << '\n';
  int i2;
  i2 = 2;
  // static_cast<>() gives a compile time checking ability, C-Style cast doesn't and may give runtime error
  std::cout << "i2= " << i2 << '\n';
  auto div = static_cast<double>(i1) / i2;
  std::cout << "in double arithmetic, " << i1 << " divided by " << i2 << " is "<< div << '\n';
  double d1 = 2.2;
  // int i5 = d1;
  int i5 = static_cast<int>(d1);
  auto a1 = 1;
  auto a2 = 2.2;
  // a1 = a2;
  a1 = static_cast<int>(a2);
  return 0;
}
