// DATE: 04-07-2023
/* PROGRAM: 32_String Sorting
Input N and n strings and sort it in descending order lexicographically.
INPUT
3
Apple
Pineapple
Green Apple

OUTPUT
Pineapple
Green Apple
Apple

EXPLANATION
- greater<string>() to give comparator to sort in descending order
- for (range-declaration : range-expression) to iterate over the items of the string array
*/
// @ankitsamaddar @2023
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int n=0;
	cin >> n;
    string s[n];
    cin.get();
	for (int i = 0; i<n; i++) {
		getline(cin,s[i]);
	} cout << endl;
	/* To print the strings
	for (string it : s) {
		cout<<it<<endl;
	}  cout << endl;
	*/

	sort(s,s+n,greater<string>());

	for (string it : s) {
		cout<<it<<endl;
	}
    return 0;
}
