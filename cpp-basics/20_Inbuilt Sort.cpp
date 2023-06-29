// DATE: 30-06-2023
/* PROGRAM: 20_Inbuilt Sort
Enter N elements in an array and sort the elements of the array in ascending order using Inbuilt Sort function in C++.
INPUT
10
4 98 7 54 3 6 41 10 1 2

OUTPUT
1 2 3 4 6 7 10 41 54 98

EXPLANATION
- use <algorithm> library which contains the sort() function which can sort containers(array,vector..)
- inline void sort(int *__first, int *__last, bool (*__comp)(int, int))
- sort(first_element,last_element,comparator)
- first element = arr(which is arr[0]) , last element = arr+n
- sort() takes a third parameter that is used to specify the order in which elements are to be sorted.
- We can pass the 'greater<int>()' function to sort in descending order. This function does a comparison in a way that puts greater elements before.
*/
// @ankitsamaddar @2023
#include <iostream>
#include <algorithm>
using namespace std;

// We use a Comparator and pass it to the sort() function to sort in specific order
bool compare(int a,int b){
	return a>b; // sort in descending order
}
int main() {
    int n=0;
    cin >> n;
	int arr[100];
	for (int i = 0; i<n; i++) {
		cin>>arr[i];
	}
	sort(arr,arr+n,compare);
	for (int i = 0; i<n; i++) {
		cout<<arr[i]<<" ";
	}
    return 0;
}
