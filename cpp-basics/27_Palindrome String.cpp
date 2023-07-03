// DATE: 03-07-2023
/* PROGRAM: 27_Palindrome String
Read a sentence/paragraph and check if its palindrome or not
INPUT
abdcdba

OUTPUT
True

EXPLANATION

*/
// @ankitsamaddar @2023
#include <iostream>
#include <cstring>
using namespace std;
bool isPalindrome(char arr[]){
	int i = 0;
	int j = strlen(arr) - 1;
	while (i<j) {
	if(arr[i] == arr[j]){
		i++;
		j--;
	}
	else
		return false;
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
