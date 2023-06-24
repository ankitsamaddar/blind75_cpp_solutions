#include <iostream>
#include <string>

using namespace std;
/*
length(): This function returns the length of the string.
assign(): This function assigns a new value to the string.
append(): This function appends a string to the end of the current string.
compare(): This function compares two strings and returns an integer value that indicates the result of the comparison.
find(): This function searches for a substring in the string and returns the position of the first occurrence of the substring.
substr(): This function returns a substring of the string.
replace(): This function replaces a portion of the string with another string.
erase(): This function erases a portion of the string.
c_str(): This function returns a C-style string that is compatible with the C-style string functions.
*/
int main() {
  string str;

  // Input a string from the user
  cout << "Enter a string: ";
  getline(cin, str);

  // Print the length of the string
  cout << "Length of the string: " << str.length() << endl;

  // Append a string to the original string
  str.append(" is awesome!");

  // Print the modified string
  cout << "Modified string: " << str << endl;

  // Find the position of a substring in the string
  size_t pos = str.find("awesome");
  if (pos != string::npos) {
    cout << "Substring found at position " << pos << endl;
  } else {
    cout << "Substring not found" << endl;
  }

  return 0;
}
