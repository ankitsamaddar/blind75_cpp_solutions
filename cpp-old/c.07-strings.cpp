/*
Strings are char arrays ending with '\0'
*/

/*
Why str and not &str in scanf?
int x = 5;
char str[] = "AwesomeC";
1.str[]=  passes the whole array || comparable to x
2.str = passes the base address || comparable to &x
3.*str = passes the whole array || comparable *&x ==x
4.&str[0] - Passes the address of 0th element in arr
*/

/*	%c and %s

char str[] = "AwesomeC";

1.%c denotes a Character - %c accepts the variable, not its address
	a. printf("%c %c\n", *(str+5), str[5]);
		*(str+5) = str[5]
2.%s denotes a String - %s accepts char* (i.e., the address of the char array)
	a. printf("%s %s\n", &str[5], str+5);
		&str[5] = str+5 = meC
Formally,

3.A String is an contiguous sequence of Characters, just as An Array is an contiguous sequence of Integers.

4.A Character is a Single Symbol representing A Letter or Number.

str[] denotes value string, str denotes address
*/

/*
gets() -> gives error
fgets() ->

#include<stdio.h>
void main()
{
char str[20];
printf("Enter the string? ");
fgets(str, 20, stdin);
printf("%s", str);
return 0;
}


#include<stdio.h>
#include <string.h>
int main(){
char name[50];
printf("Enter your name: ");
gets(name); //reads string from user printf("Your name is: ");
puts(name); //displays string
return 0;
}


*/

#include<stdio.h>
int main()
{
char str[] = "AwesomeCProgram";
printf("%s %s %s\n", &str[5], &5[str], str+5);
printf("%c %c %c\n", *(str+5), str[5], 5[str]);
return 0;
}
