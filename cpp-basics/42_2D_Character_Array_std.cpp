// DATE: 17-07-2023
/* PROGRAM: 42_2D Character Array_std

Problem Statement:
Write a C++ program to store a list of strings in a 2D character array. The program should take the dimensions of the array and the strings as input and print the array.

Input Format:
The first line of input contains two integers n and m, representing the number of rows and columns of the array, respectively. The next n lines contain m strings each, representing the elements of the array.

Output Format:
The program should print the 2D character array.

Sample Input:
3 20
Hello World
Programming in C++
Code is Fun

Sample Output:
Hello World
Programming in C++
Code is Fun

EXPLANATION
- cin.get() after the cin is to absorb the the Enter which would else be a entry of the array.
- using dynamic allocation of the character array
*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,m=0;
    cin >> n>>m;
	cin.get();
	char** arr= new char*[n];
	for (int i=0; i<n; i++) {
		arr[i] = new char[m];
		cin.getline(arr[i],m);
	}
	for (int i=0; i<n; i++) {
		cout<<arr[i]<<endl;
	}
	return 0;
}
