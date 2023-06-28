// DATE: 29-06-2023
/* PROGRAM: 13_Alphabet Pattern I
Print the following pattern where for given N = 5, the pattern is.
ABCDE
ABCD
ABC
AB
A

INPUT
8
OUTPUT
ABCDEFG
ABCDEF
ABCDE
ABCD
ABC
AB
A

EXPLANATION
- incrementing a character goes to the next character in ASCII
*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
void printPattern(int n){
	for (int i =1; i<=n; i++) {
		int cnt_=n-i;
		char alphabet='A';
		for(int j = 1;j<=cnt_;j++){
			cout<<alphabet;
			alphabet++;
		}
		cout<<endl;
	}
}

int main() {
    int n;
    cin >> n;
    printPattern(n);
	return 0;
}
