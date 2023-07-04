// DATE: 05-07-2023
/* PROGRAM: 33_String Tokenization using strtok()
Input a string. Tokenize and print the words using strtok() function.
INPUT
See,we are the aliens,Alas !

OUTPUT
See
we are the aliens
Alas !

EXPLANATION
- <cstring> library function inherited from C
- char *strtok(char *str, const char *delim) breaks string str into a series of tokens using the delimiter delim.
- If delimiter is found, it is replaced by '\0' and the pointer to the following character is stored in a static location for subsequent invocations. The function returns the pointer to the beginning of the token.

- returns a token on each subsequent call. On the first function call pass 's' for string argument and for subsequent calls we should pass the string argument as NULL, which indicates we are using the same pointer we used previously.
- char* word will be NULL when there is no more tokens.
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
