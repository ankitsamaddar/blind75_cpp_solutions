// DATE: 05-07-2023
/* PROGRAM: 33_String Tokenization using strtok()
Input a string and delimeter. Tokenize and print the words using a strtok() function.
INPUT

OUTPUT

EXPLANATION
- <cstring> library function inherited from C
- char *strtok(char *str, const char *delim) breaks string str into a series of tokens using the delimiter delim.
- returns a token on each subsequent call. On the first call function should be passed with string argument for 's' and on subsequent calls we should pass the string argument as NULL.
-  NULL indicates we are using the same pointer we used previously
- char* word will be NULL when there is no more tokens
*/
// @ankitsamaddar @2023
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char str[100];
	cin.getline(str,100);
	char* word = strtok(str, ",");
	cout << word<<endl;
	while (word!=NULL) {
	word = strtok(NULL, ",");
	cout << word<<endl;
	}
    return 0;
}
