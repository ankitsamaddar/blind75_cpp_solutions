// DATE: 03-07-2023
/* PROGRAM: 30_Largest String
Read N, followed by N strings and print the largest string(word) of the given string.
INPUT
3
hello this is line 1
hi this is c++ console
this is the longest text

OUTPUT
this is the longest text  24

EXPLANATION

*/
// @ankitsamaddar @2023
#include <cstring>
#include <iostream>
using namespace std;
int main() {
    int n,cur_len,max_len=0;
    cin >> n;
    cin.get();
	char s[1000];
	char largest[1000];
	for (int i = 0; i<n; i++) {
		cin.getline(s,1000);
		cur_len=strlen(s);
		if(cur_len>max_len){
			max_len = cur_len;
			strcpy(largest, s);
		}
	}
	cout<<largest<<"  "<<max_len;
	return 0;
}
