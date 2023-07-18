// DATE: 18-07-2023
/* PROGRAM: 46_Search Element (in Row & Col Wise Sorted Matrix)_std

Given an n x m matrix and an integer `key`, find the position of `key` in the matrix if it is present. Otherwise, print “Element not found”. Every row and column of the matrix is sorted in increasing order. The designed algorithm should have linear time complexity.

INPUT
3 4
10 20 30 40
13 23 33 43
27 29 37 48
29

OUTPUT
Found at (2,1).

*/
// @ankitsamaddar @2023
#include <iostream>
using namespace std;

void searchKey(int** arr, int n, int m, int key) {
	int row = 0, col = m - 1;
	while (row >= 0 and col >= 0) {
		if (key == arr[row][col]) {
			cout << "Found at (" << row << "," << col << ")." << endl;
			return;
		} else if (key > arr[row][col])
			row++;
		else if (key < arr[row][col])
			col--;
	}
	cout << "Not Found";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, key = 0;
	cin >> n >> m;
	int** arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> key;
	searchKey(arr, n, m, key);
	return 0;
}
