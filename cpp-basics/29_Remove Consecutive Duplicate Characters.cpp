// DATE: 03-07-2023
/* PROGRAM: 29_Remove Consecutive Duplicate Characters
Remove consecutive duplicate characters from a string.
Example: ccoooding -- > coding
INPUT
ttthisss isss ttexxxttt

OUTPUT
this is text

EXPLANATION

*/
// @ankitsamaddar @2023
#include <cstring>
#include <iostream>
using namespace std;

void removeDuplicates(char arr[]) {
	int n = strlen(arr);
	if (n==1 or n==0) {
		return;
	}
	int prev = 0;
	for (int cur = 1; cur<n; cur++) {
		if (arr[prev]!=arr[cur]) {
			arr[++prev]=arr[cur]; // swap next element of last not duplicate character with current character
		}
	}
	arr[prev+1]='\0';
	return;

}

int main() {
    char arr[1000];
	cin.getline(arr, 1000);
	removeDuplicates(arr);
	cout << arr << endl;
    return 0;
}
