// DATE: 30-06-2023
/* PROGRAM: 16_Binary Search
Enter N elements in an array and enter the key. Find if key is present in the array using Binary Search, if present print the index.

INPUT
10
1 2 3 8 10 15 21 33 41 52
21

OUTPUT
6

EXPLANATION
- searching algorithm used in a sorted array by repeatedly dividing the search interval in half.
- The idea of binary search is to use a sorted array and reduce the time complexity to O(log N).
*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
int binarySearch(int n,int arr[],int key){
	int s,mid = 0;
	int e = n-1;
	while(s<=e){
		mid = (s+e)/2;
		if(arr[mid]==key){
			return mid;
		}
		else if (arr[mid]<key) {
			s = mid+1;
		}
		else{
			e = mid -1;
		}
	}
	return -1;
}
int main() {
    int n,key;
    cin >> n;
	int arr[100];
	for (int i = 0; i<n; i++) {
		cin>>arr[i];
		// cout<<arr[i]<<" ";
	}
	cin>>key;
	cout<<binarySearch(n, arr, key);
    return 0;
}
