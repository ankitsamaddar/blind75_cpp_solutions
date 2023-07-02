// DATE: 02-07-2023
/* PROGRAM: 25_Character Array
Learn about the working of character array input and output
INPUT
tomato

OUTPUT
0x....... // address of b[0]
abcde
tomato
hellotomato 5
hello 6

EXPLANATION
- all character should be terminated with null character(\0) else it will print garbage till it finds \0
- character array can be initialized using "texthere" which will auto add null character(\0)
*/
// @ankitsamaddar @2023
#include <iostream>
#include <ostream>
using namespace std;
int main() {
    int b[]  = {1, 2, 3};
	cout << b << endl; // output the starting address of the b[0]

	char a[] = {'a', 'b', 'c', 'd', 'e', '\0'};
	cout << a << endl; // output the whole array unless there is null(\0) in the contigious memory location

	// input and output without for loop
	char s[100];
	cin>>s; // ENTER from keyboard is converted to Null(\0)
	cout<<s<<endl;

	// assigning values into character array
	char s1[] = {'h', 'e', 'l', 'l', 'o'}; //doesnt terminate with null so will also print garbage
	char s2[] = "hello"; //another way

	cout << s1 << " " << sizeof(s1) << endl; //5 bytes - and will print garbage till it finds Null(\0) character
	cout << s2 << " " << sizeof(s2) << endl; //6 bytes
    return 0;
}
