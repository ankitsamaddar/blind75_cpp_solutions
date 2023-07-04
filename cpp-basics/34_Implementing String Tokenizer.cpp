// DATE: 05-07-2023
/* PROGRAM: 34_Implementing String Tokenizer
Implement a string tokenizer function. Input a string followed by the delimiter and print the tokens.
INPUT
See,we are the aliens,Alas !
,

OUTPUT
See
we are the aliens
Alas !

EXPLANATION
- use dynamic memory allocation for the output character array as we do not know the actual size of the input array.
- edge case when we get the last token add '\0' at the end so we print the whole word
- base case check if the input array is NULL if so return NULL.(No token left)
*/
// @ankitsamaddar @2023
#include <cstring>
#include <iostream>
using namespace std;

char *mystrtok(char *s,char delim){
	// string and single character
	static char* in=NULL;
	// if s is not NULL i.e first call we assign s to the input array pointer
	if(s!=NULL){
		in=s;
	}
	// base case when no tokens
	if (in==NULL) {
		return NULL;
	}
	// exract token
	char *out = new char[strlen(in)+1]; // dynamic memory allocation // + 1 as we add '\0' for edge case
	int i = 0;
	for (;in[i]!='\0' ; i++) {
		if(in[i]!=delim){
			out[i]=in[i];
		}
		else {
			out[i]='\0';
			in = in + i + 1;
			return out;
		}
	}
	// last token
	out[i] = '\0';
	in = NULL;
	return out;
}
int main() {
	char str[100],delim;
	cin.getline(str,100);
	cin.get(delim);
	char* word = mystrtok(str, delim);
	cout << word<<endl;
	while (word!=NULL) {
	word = mystrtok(NULL, delim);
	cout << word<<endl;
	}
	return 0;
}
