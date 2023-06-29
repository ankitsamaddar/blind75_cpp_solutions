// DATE: 29-06-2023
/* PROGRAM: 14_Linear Search
Enter N elements in an array and enter the key. Find if key is present in the array, if present print the index.

INPUT
10
4 87 9 41 2 3 76 51 7 10
2

OUTPUT
4

EXPLANATION
- sequential search algorithm that starts at one end and goes through each element of a array until the desired element is found, otherwise the search continues till the end of the array.
*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
int main() {
    int n,key,i=0;
    cin >> n;
	int arr[n];
	for (int i = 0; i<n; i++) {
		cin>>arr[i];
		// cout<<arr[i]<<" ";
	}
	// cout<<endl;
	cin>>key;
	for (i = 0; i<n; i++) {
		if(arr[i]==key){
			cout<<i;
			break;
		}
	}
	if (i==n){
		cout<<"Not present";
	}

    return 0;
}
