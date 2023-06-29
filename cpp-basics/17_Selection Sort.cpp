// DATE: 30-06-2023
/* PROGRAM: 17_Selection Sort
Enter N elements in an array and sort the elements of the array in ascending order using Selection Sort algorithm.
INPUT
10
4 98 7 54 3 6 41 10 1 2

OUTPUT
1 2 3 4 6 7 10 41 54 98

EXPLANATION
- Repeatedly select the smallest (or largest) element from the unsorted portion of the list and swaps it with the first element of the unsorted part (it is the last element in the sorted part).
- This process is repeated for the remaining unsorted portion until the entire list is sorted.
- can use swap() function to swap elements instead of using temp variable
*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;

void selectionSort(int n,int arr[]){
	int min_idx,temp=0;
		for(int i=0;i<n-1;i++){
			min_idx=i; // first element of unsorted list
			for (int j=i; j<n; j++) {
				if(arr[j]<arr[min_idx]){
					min_idx=j;
				}
			}
		temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
		// swap(arr[i],arr[min_idx]);
	}
}

int main() {
    int n=0;
    cin >> n;
	int arr[100];
	for (int i = 0; i<n; i++) {
		cin>>arr[i];
	}
	selectionSort(n, arr);
	for (int i = 0; i<n; i++) {
		cout<<arr[i]<<" ";
	}
    return 0;
}
