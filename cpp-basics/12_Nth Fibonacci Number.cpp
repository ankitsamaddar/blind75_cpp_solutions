// DATE: 29-06-2023
/* PROGRAM: 12_Nth Fibonacci Number
Calculate the nth Fibonacci number where n is a given positive number.

Fibonacci’s sequence is characterized by the fact that every number after the first two is the sum of the two preceding ones. For example, consider the following series:

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, … and so on.

INPUT
7

OUTPUT
0 1 1 2 3 5 8 13
13

EXPLANATION
As we can see above, each subsequent number is the sum of the previous two numbers. The starting point of the sequence is sometimes considered 1, resulting in the first two numbers in the Fibonacci sequence as 1 and 1.

*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;

int findFibo(int n){
	int a,c = 0;
	int b = 1;
	cout<<a<<" "<<b<<" ";
	for (int i = 1; i<n; i++) {
		c = a+b;
		cout<<c<<" ";
		a = b;
		b = c;
	}
	cout<<endl;
	return c;
}
int main() {
    int n;
    cin >> n;
    cout << findFibo(n)<<endl;
    return 0;
}
