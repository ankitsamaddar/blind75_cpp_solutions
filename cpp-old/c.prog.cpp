#include <iostream>
#include <string>

using namespace std;

/*
String concate using = or using append
*/

int main() {
  // Declare three strings
  string str1 = "Hello";
  string str2 = ", ";
  string str3 = "world!";

  // Concatenate the strings using the + operator
  string result1 = str1 + str2 + str3;
  cout << "Result using + operator: " << result1 << endl;

  // Concatenate the strings using the append() function
  string result2 = str1;
  result2.append(str2);
  result2.append(str3);
  cout << "Result using append() function: " << result2 << endl;

  return 0;
}
