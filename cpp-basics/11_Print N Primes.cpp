// DATE: 29-06-2023
/* PROGRAM: 11_Print N Primes
Find all prime numbers upto N terms using functions. Take N as input.
INPUT
50
OUTPUT
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47
EXPLANATION
- prime numbers have two factors one and the number itself
*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;

bool isPrime(int n){
	for(int i =2;i<n;i++){
		if(n%i==0) {
			return false;
		}
	}
	return true;
}

void printPrime(int n){
	for (int i = 2; i<=n; i++) {
		if(isPrime(i)){
			cout<<i<<" ";
		}
	}
}
int main() {
    int n;
    cin >> n;
    printPrime(n);
    return 0;
}
