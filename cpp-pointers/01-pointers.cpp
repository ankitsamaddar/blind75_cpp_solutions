/*	* OPERATOR
* operator is used to declare a pointer variable or to dereference a pointer variable.

When used in a declaration, the * operator is used to indicate that the variable being declared is a pointer.
For example, int* ptr declares a pointer to an integer variable.

When used to dereference a pointer variable, the * operator is used to access the value stored at the memory location pointed to by the pointer.
For example, *ptr accesses the value stored at the memory location pointed to by ptr.
*/

/*	& OPERATOR
& operator is used to get the address of a variable or to declare a reference variable.

When used to get the address of a variable, the & operator is used to return the memory address of the variable.
For example, &x returns the memory address of the variable x.

When used in a declaration, the & operator is used to indicate that the variable being declared is a reference.
For example, int& ref = x declares a reference variable ref that refers to the variable x.
*/

#include <iostream>

int main() {

	int x = 10;
  	int* ptr = &x; // ptr is a pointer to x
  	int& ref = x; // ref is a reference to x

	std::cout << "Value of x: " << x << std::endl;
	std::cout << "Value of *ptr: " << *ptr << std::endl;
	std::cout << "Value of ref: " << ref << std::endl;

	*ptr = 20; // change the value of x using ptr
	std::cout << "New value of x: " << x << std::endl;

	ref = 30; // change the value of x using ref
	std::cout << "New value of x: " << x << std::endl;

	std::cout << "Address of x: " << &x << std::endl;
	std::cout << "Address of ptr: " << ptr << std::endl;
	std::cout << "Address of ref: " << &ref << std::endl;

	return 0;
}
