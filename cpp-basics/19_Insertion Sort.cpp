// DATE: 30-06-2023
/* PROGRAM: 19_Insertion Sort
Enter N elements in an array and sort the elements of the array in ascending order using Insertion Sort algorithm.
INPUT
10
4 98 7 54 3 6 41 10 1 2

OUTPUT
1 2 3 4 6 7 10 41 54 98

EXPLANATION
- Array is virtually split into a sorted and an unsorted part.
- Values from the unsorted part are picked and placed at the correct position in the sorted part.
*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
void insertionSort(int n,int arr[]){

	for (int i = 1; i<n; i++) {
		int ele = arr[i];
		int j = i-1;
		while (j>=0 and arr[j]>ele) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = ele;
	}
}
int main() {
    int n=0;
    cin >> n;
	int arr[100];
	for (int i = 0; i<n; i++) {
		cin>>arr[i];
	}
	insertionSort(n, arr);
	for (int i = 0; i<n; i++) {
		cout<<arr[i]<<" ";
	}
    return 0;
}
