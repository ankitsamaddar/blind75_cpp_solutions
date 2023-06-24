/*
In C++, passing by value means that a copy of the argument is passed to the function,
While passing by reference means that the function receives a reference to the original argument.

passing by value creates a copy of the argument, while
passing by reference allows the function to modify the original argument.
*/

#include <iostream>

void swapByValue(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
	}

	void swapByReference(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
	}

	void swapByDereference(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	}


	int main() {
	int x = 10;
	int y = 20;
	std::cout <<"Passing BY VALUE"<<std::endl;
	std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
	swapByValue(x, y);
	std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

	std::cout <<"Passing BY REFERENCE"<<std::endl;
	std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
	swapByReference(x, y); // x and y will be changed
	std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

	std::cout <<"Passing BY DEREFERENCE"<<std::endl;
	std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
	swapByDereference(&x, &y); // passing address
	std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

	return 0;
}
