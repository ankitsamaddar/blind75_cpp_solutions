// DATE: 02-07-2023
/* PROGRAM: 26_Reading Sentences - cin.get() & cin.getline()
Read a sentence/paragraph and store it using cin.get() and cin.getline()
INPUT
This is a paragraph
ends with a dollar. $

OUTPUT
This is a paragraph
ends with a dollar.

EXPLANATION
-
- cin.get() reads a single character and use a loop to read characters till you get a new line '\n'
- cin.getline() is a inbuilt function which takes input for character arrays and we can specify the delimiter.
*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;

void readline(char arr[], int maxLen, char delim = '\n') {
	int i = 0;
	char ch = cin.get();
	while (ch != delim) {
		arr[i] = ch;
		i++;
		if (i == (maxLen - 1)) {
			break;
		}
		ch = cin.get();
	}
	//once out of the loop
	arr[i] = '\0';
	return;

}

int main() {

	char arr[1000];
	//readline(a, 1000, '$');
	cin.getline(arr, 1000, '$'); // inbuilt method which works like readline()
	cout << arr << endl;

	return 0;
}
