// DATE: 28-06-2023
/* PROGRAM: 06_Final Displacement

Find the final displacement in terms of x and y.

        N
        |
        |
W--------------E
        |
        |
        S

Going N north is y+1 and going S south is y-1
Going E east is x+1 and going W west is x-1

INPUT
NNNSSEEWE

OUTPUT
2 1

EXPLANATION
1.  cin doesnot read whitespaces as whitespace is buffer pointer in cin
2.  cin.get() method reads any single char including spaces/newlines from the input buffer

*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
int main() {
	char ch;
	int x,y = 0;
	while(ch != '\n'){
		if (ch=='N' or ch =='n') {
			y++;
		}
		if (ch=='S' or ch =='s') {
			y--;
		}
		if (ch=='E' or ch =='e') {
			x++;
		}
		if (ch=='W' or ch =='w') {
			x--;
		}
		// cin >> ch; // doesnot reads spaces/newline
		ch = cin.get(); // also reads spaces/newline
	}
	cout << "Final Displacement ("<<x<<","<<y<<").\n";
    return 0;
}
