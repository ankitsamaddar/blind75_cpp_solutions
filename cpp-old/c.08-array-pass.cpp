/*
Arrays and strings in C++ are closely related to pointers.
An array name is a constant pointer to the first element of the array, and
a string is an array of characters terminated by a null character '\0'.

When passing arrays or strings to a function in C++, we can pass them by reference or by pointer.

Passing by reference allows the function to modify the original array or string, while
passing by pointer allows the function to access the array or string using a pointer variable.
*/

#include <iostream>

void printArray(int* arr) // (&arr)[5] -> &arr -> arr[] -> int* arr
{
  for (int i = 0; i < 5; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

/* WAYS TO PASS AN ARRAY
int arr[5]      // a pointer to the first element of the array
int* arr        // a pointer to an integer (can be used as an array)
int *arr        // a pointer to an integer (can be used as an array)
int arr[]       // a pointer to the first element of the array
int *arr[5]     // an array of 5 pointers to integers
int (*arr)[5]   // a pointer to an array of 5 integers
int (&arr)[5]	// reference to an array of 5 integers
*/


/* SOME NOTES on int* ptr and int *ptr

In C++, int* arr and int *arr are equivalent in function parameters and declare a pointer to an integer named arr.

The space between the int and the * is optional in C++. However, it is a common convention to put the asterisk next to the variable name (int* arr) to make it clear that the * operator is part of the variable declaration, rather than the type. This is known as the "pointer to" notation, and it is often used to make the code more readable.

*/

void doubleValue(int* numPtr) {
    *numPtr *= 2;
}


/*
However, when declaring a pointer variable outside of a function parameter, it is important to note that the space between the int and * is significant. For example, the following declarations are not equivalent:

	int* a, b;   // a is a pointer to an int, b is an int
	int *a, *b;  // both a and b are pointers to ints
*/


int main() {
  int arr[5] = {1, 2, 3, 4, 5};

  std::cout << "Before modification: ";
  printArray(arr);

  arr[2] = 10;

  std::cout << "After modification: ";
  printArray(arr);

  return 0;
}
