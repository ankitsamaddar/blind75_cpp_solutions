#include <iostream>

int main() {
  int i1 = 1;
  std::cout << "i1= " << i1 << '\n';
  int i2;
  i2 = 2;
  std::cout << "i2= " << i2 << '\n';
  int i3(3);
  std::cout << "i3= " << i3 << '\n';
  int i4{4};
  std::cout << "i4= " << i4 << '\n';

  auto div = i1 / i2;
  std::cout << "in integer arithmetic, " << i1 << " divided by " << i2 << " is "
            << div << '\n';

  int answer;
  std::cout << "Enter a number\n";
  std::cin >> answer;
  std::cout << "You entered " << answer << '\n';

  double d1 = 2.2;
  double d2 = i1;
  int i5 = d1;
  std::cout << "d1= " << d1 << '\n';
  std::cout << "d2= " << d2 << '\n';
  std::cout << "i5= " << i5 << '\n';

  char c1 = 'a';
//   char c2 = "b"; // ""-Ctype String(const char *) ''-character
  std::cout << "c1= " << c1 << '\n';
//   std::cout << "c2= " << c2 << '\n';

  bool flag = false;
  std::cout << "flag= " << flag << '\n';
  flag = i1;
  std::cout << "flag= " << flag << '\n';
  flag = d1;
  std::cout << "flag= " << flag << '\n';

  auto a1 = 1;
  auto a2 = 2.2;
  auto a3 = 'c';
  auto a4 = "s";
  auto a5 = true;
  auto a6 = 3L;
  auto a7 = 1'000'000'000'000;
  auto a8 = 0xFF;  // 255
  auto a9 = 0b111; // 7

  a1 = a2;
  /*
          unsigned char n1 = 128;
            char n2 = 128; // it will turn to -128 as there is
            std::cout << "n1= " << n1 << '\n';
            std::cout << "n2= " << n2 << '\n';
            n1 = 254;
            n2 = 254; // changes value from 254 to -2
            std::cout << "n1= " << n1 << '\n';
            std::cout << "n2= " << n2 << '\n';
            // Char can only hold upto 255 , signed char has range -128 to 127
            n1 = 300; // changes value from 300 to 44
            n2 = 300; // changes value from 300 to 44
            std::cout << "n1= " << n1 << '\n';
            std::cout << "n2= " << n2 << '\n';
  */
  return 0;
}
