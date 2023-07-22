// DATE: 21-07-2023
/* PROGRAM: 47_Pointers Reference Dereference

This program contains explanation af POINTERS, REFERENCE and DEREFERENCE and each syntax and uses is
marked with comments.
*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;

int main() {
	int n = 10;
	cout << &n << endl;

	float y = 10.5;
	cout << &y << endl;
	char ch = 'A';
	cout << &ch << endl;	// This will output A as cout will print the character at the address as
												// << operator is overloaded
	cout << (void*)&ch << endl;	 // Explicit Type Casting from char * to void *

	// Pointers Stores address of another variable
	int* ptr;	 // Declare
	ptr = &n;	 // Assignment

	// Re-assign pointers
	int* xptr;
	xptr = &n;
	cout << &n << " = " << xptr << endl;
	int m = 30;
	xptr = &m;
	cout << &m << " = " << xptr << endl;

	// Size of a pointer variable is always same to another pointer variable of any type as size of
	// addresses are of fixed length
	float* fptr;												// Pointer of type float
	if (sizeof(ptr) == sizeof(fptr)) {	// a integer pointer has same size as a float pointer
		cout << "True" << endl;
	}

	// Always use the correct type when storing pointer although they have same size as it will
	// cause error when dereferencing the variable

	// DEREFERENCE
	/*
	 * -> Multiplication
	 * -> Pointer
	 * -> Dereference

	 & Bucket  -> Address
	 * Address -> Bucket
	 */

	cout << *(&m) << " = " << *xptr << endl;	// Dereferencing
	cout << *(&ptr) << " = " << &(*ptr) << endl;

	cout << *(xptr) + 1 << endl;
	cout << *(xptr + 1) << endl;	// Garbage Value as we are Pointing to the next address after xptr
																// which does not have any value

	// DOUBLE POINTER
	// Address to a pointer variable which in turn has address of another variable
	int** dptr = &xptr;
	cout << "address of xptr: " << *dptr << "\ndereference xptr: " << **dptr << endl;

	return 0;
}
