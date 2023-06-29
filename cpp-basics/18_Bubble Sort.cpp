// DATE: 30-06-2023
/* PROGRAM: 18_Bubble Sort
Enter N elements in an array and sort the elements of the array in ascending order using Bubble Sort algorithm.
INPUT
10
4 98 7 54 3 6 41 10 1 2

OUTPUT
1 2 3 4 6 7 10 41 54 98

EXPLANATION
- traverse from left to right by repeatedly swapping the adjacent elements if they are in the wrong order(ascending or descending).
- Function Passing and using Comparator in Bubble Sort
*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
bool compare(int a,int b){
	return(a>b);
}
void bubbleSort(int n,int arr[],bool (&cmp)(int a,int b)){ // Function is passed by reference
	for (int i = 0; i<n-1; i++) {
		for (int j = 0; j<n-i-1; j++) {
			if(cmp(arr[j],arr[j+1]))
				swap(arr[j],arr[j+1]);
		}
	}
}
int main() {
    int n=0;
    cin >> n;
	int arr[100];
	for (int i = 0; i<n; i++) {
		cin>>arr[i];
	}
	bubbleSort(n, arr,compare); // function passing
	for (int i = 0; i<n; i++) {
		cout<<arr[i]<<" ";
	}
    return 0;
}
