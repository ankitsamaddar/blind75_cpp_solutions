// DATE: 30-06-2023
/* PROGRAM: 15_Largest and Smallest Number
Find the largest and the smallest number in an array of N elements
INPUT
5
4 21 6 1 7

OUTPUT
1 21

EXPLANATION
- can also be done using max() and min() fuctions which is present in the <climits> library
*/
// @ankitsamaddar @2023
#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n,min_num,max_num = 0;
    cin >> n;
	int arr[n];
	for (int i = 0; i<n; i++) {
		cin>>arr[i];
		if (arr[i]<min_num){
			min_num=arr[i];
		}
		// min_num = min(min_num,arr[i]);
		if (arr[i]>max_num){
			max_num=arr[i];
		}
		// max_num=max(max_num,arr[i]);
		// cout<<arr[i]<<" ";
	}
    cout <<min_num<< " "<<max_num << endl;
    return 0;
}
