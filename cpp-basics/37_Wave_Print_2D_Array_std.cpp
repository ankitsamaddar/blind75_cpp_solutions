// DATE: 15-07-2023
/* PROGRAM: 37_Wave Print 2D Array_std
You are given a two-dimensional integer array of size N x M. You need to print the array in a wave-like order. You Are Given A Two-Dimensional Integer Array Of Size N X M. You Need To Print The Array In A Wave-Like Order. i.e., print the elements of the first column in the downward direction, then print the elements of the second column in the upward direction, then print the elements of the third column in the downward direction, and so on until all the elements are printed.
Example:
INPUT:
3 3
1 2 3
4 5 6
7 8 9

OUTPUT:
1 4 7 8 5 2 3 6 9

EXPLANATION:
- If columns number is even go Top to Down first else if odd go Down to Top first. (As it starts from 0)
The elements of the first column are printed in the downward direction, then the elements of the second column are printed in the upward direction, and finally, the elements of the third column are printed in the downward direction.

*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,m=0;
    cin >> n>>m;
	int** arr = new int*[n];
	for (int i = 0; i<n; i++) {
		arr[i] = new int[m];
		for (int j = 0; j<m; j++) {
			cin>>arr[i][j];
		}
	}
	// Wave Print
	for (int col = 0; col<n; col++) {
		if(col%2==0){
			// Top to down
			for (int row = 0; row<m; row++) {
				cout<<arr[row][col]<<" ";
			}
		}
		else{
			// Down to Bottom
			for (int row=m-1; row>=0; row--) {
				cout<<arr[row][col]<<" ";
			}
		}

	}
    return 0;
}
