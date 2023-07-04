// DATE: 04-07-2023
/* PROGRAM: 31_String STL
String Class in STL alternative to char array
INPUT

OUTPUT

EXPLANATION
-  String is a class is a container and all objects that in string represent sequences of characters.
- all basic features of string class with comments below
*/
// @ankitsamaddar @2023
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s0;
	string s1 ="Hello ";
	string s2 =s1.append("World"); // append string
	string s3(s2);
	string s4 = s3 + " and Universe"; // adding strings
	char a[] = {'a','b','c','d','\0'};
	string s5(a); // ASSIGNING CHARACTER ARRAY
	cout << s0.empty() << endl; // Check if string is empty, if empty return 1(TRUE)
	cout << s1 << endl <<s2 << endl <<s3 << endl <<s4 << endl;
	cout <<s5.length()<<endl; // print length of string
	cout <<s5[3]<<endl; //print character at index
	s0 = "Ant"; s1= "Rat";
	cout<<s1.compare(s0)<<endl; // Returns 0 if equal , > 0 if s1 is greater, < 0 if s1 is smaller
	// Overloaded operator s1 > s2 or s1 < s2
	// Find at index substring
	string s = "I love coding.";
	cout << s.find("love") << endl; // prints starting index of the searched substring
	int len = s.length();
	s.erase(s.find("coding"),len-1); // erase substring till position
	cout << s << endl;

	// Iterate all characters
	//using index
	for (int i = 0; i<s.length(); i++) {
		cout<<s[i]<<" ";
	}
	cout<<endl;
	// using iterators
	for(auto it=s.begin();it != s.end();it++){ // auto uses iterator inside string class string::iterator
		cout<<(*it)<<" ";
	}
	cout << endl;
	// using for each item of array
	for (char c : s) {
		cout <<c<<" ";
	}
    return 0;
}
