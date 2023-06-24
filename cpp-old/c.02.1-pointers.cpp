/*
it is important to note that the space between the int and * is significant. For example, the following declarations are not equivalent:
*/

#include <iostream>

int main() {
	int* a, b; // a is a pointer to an int, b is an int
    b = 20;
    std::cout << b;
    a = &b;
    *a = 12; // will change b
    std::cout <<std::endl<< b;

	int *x,*y; // both x and y are pointers to ints
	x=&b;
	y=x;
	std::cout << std::endl << *x;
	*y=18;
	std::cout << std::endl << *y;
    return 0;
}
