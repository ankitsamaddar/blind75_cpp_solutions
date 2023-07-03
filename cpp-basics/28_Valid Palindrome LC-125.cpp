// DATE: 03-07-2023
/* PROGRAM: 28_Valid Palindrome LC-125
https://leetcode.com/problems/valid-palindrome/
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
INPUT
A man, a plan, a canal: Panama

OUTPUT
True

EXPLANATION
- iswalnum() to checks if the given character is an alphanumeric character or not. It is defined within the <cwctype> header file.
- tolower() function converts an uppercase alphabet to a lowercase alphabet. It is a predefined function of <ctype.h> header file.
*/
// @ankitsamaddar @2023
#include <cstring>
#include <iostream>
using namespace std;

bool isPalindrome(char s[]) {
	int i = 0;
	int j = strlen(s) - 1;
	// int j = s.size() - 1; // for string input
	while(i<j){
		if (!iswalnum(s[i])) {
			i++;
		}
		else if (!iswalnum(s[j])) {
			j--;
		}
		else{
			if(tolower(s[i])!=tolower(s[j]))
				return false;
			i++;
			j--;
		}
	}

	return true;
}

int main() {
    int n=1000;
	char arr[1000];
    cin.getline(arr,n);
	if(isPalindrome(arr)){
		cout<<"True\n";
	}
	else {
		cout<<"False\n";
	}
    return 0;
}
