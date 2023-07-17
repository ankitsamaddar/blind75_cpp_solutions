// DATE: 17-07-2023
/* PROGRAM: 43_Sub matrices Sum All Approaches_std

ALL 3 POSSIBLE SOLUTIONS SOLVED BELOW
Problem Statement:
Write a C++ program to find the sum of all sub-matrices of a given matrix. The
program should take the dimensions of the matrix and the matrix elements as
input and print the maximum sum.

Input Format:
The first line of input contains two integers n and m, representing the number
of rows and columns of the matrix, respectively. The next n lines contain m
integers each, representing the elements of the matrix.

Output Format:
The program should print the sum of all sub-matrices of the given matrix.

Sample Input:
3 3
1 2 3
4 5 6
7 8 9

Sample Output:
500

INPUT
2 2
1 1
1 1

OUTPUT
16

EXPLANATION

*/
// @ankitsamaddar @2023
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int submatrixSumI(int** arr, int n, int m) {
	// BRUTE FORCE SOLUTION : time: O(n^6) ; space: O(1) ;
	int SubSum = 0;

	for (int u_row = 0; u_row < n; u_row++) {	   // upper row index
		for (int u_col = 0; u_col < m; u_col++) {  // upper col index

			for (int l_row = u_row; l_row < n; l_row++) {	   // lower row index
				for (int l_col = u_col; l_col < m; l_col++) {  // lower column index

					// Iterate sub matrix row wise and column wise
					for (int i = u_row; i <= l_row; i++) {
						for (int j = u_col; j <= l_col; j++) {
							SubSum += arr[i][j];
						}
					}
				}
			}
		}
	}
	return SubSum;
}

void calculatePrefixSum(int** arr, int n, int m) {
	// Calculating prefix sum for every row
	for (int row = 0; row < n; row++) {
		for (int col = 1; col < m; col++) {
			arr[row][col] += arr[row][col - 1];
		}
	}
	// Calculating prefix sum for every column
	for (int col = 0; col < m; col++) {
		for (int row = 1; row < n; row++) {
			arr[row][col] += arr[row - 1][col];
		}
	}
}

int submatrixSumII(int** arr, int n, int m) {
	// USING PREFIX SUM ARRAY SOLUTION : time: O(n^4) ; space: O(1) ;
	int SubSum = 0;
	calculatePrefixSum(arr, n, m);
	// if (i,j) is the starting index and (x,y) is the ending index of each sub
	// matrix
	for (int i = 0; i < n; i++) {	   // upper row index
		for (int j = 0; j < m; j++) {  // upper col index
			// cout<<SubSum<<endl;
			for (int x = i; x < n; x++) {	   // lower row index
				for (int y = j; y < m; y++) {  // lower column index
					SubSum += arr[x][y];
					// conditionals to check for if i and j are not less than 0
					if (i > 0)
						SubSum -= arr[i - 1][y];
					if (j > 0)
						SubSum -= arr[x][j - 1];
					if (i > 0 && j > 0)
						SubSum += arr[i - 1][j - 1];
				}
			}
		}
	}
	return SubSum;
}

int submatrixSumIII(int** arr, int n, int m) {
	// USING ELEMENT CONTRIBUTION SUM SOLUTION : time: O(n^2) ; space: O(1) ;

	/* Contribution(Sum) of EACH ELEMENT = arr[i][j] * No. of Sub-matrices it will be a part of.

	To define a sub-matrix we need a pair of Top-Left(TL) and
	Bottom-Right(BR) No. of Pairs of TL and BR which has arr[i][j] is equal to no sub-matrix arr[i][j] will be a part of.


	|(0,0)|     |     |     |     |         |
	+ --- + --- + --- + --- + --- + ------- +
	|     |     |     |     |     |         |
	+ --- + --- + --- + --- + --- + ------- +
	|     |     |     |(i,j)|     |         |
	+ --- + --- + --- + --- + --- + ------- +
	|     |     |     |     |     |(n-1,m-1)|

	If number of TL cells which can have arr[i][j] as a element be A[(0,0) to (i,j)] and number of BR cells which can have arr[i][j] as a element be B[(i,j) to (n-1,m-1)], then

	Total no of sub-matrix arr[i][j] will be a part of = A * B
	A = (i+1)*(j+1) -> for a rectangle from (0,0) to (i,j) -> area is Length*Breadth
	B = (n-i)*(m-j) -> for a rectangle from (i,j) to (n-i,m-j) -> area is Length*Breadth
	*/

	int SubSum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int A = (i + 1) * (j + 1);
			int B = (n - i) * (m - j);
			SubSum += arr[i][j] * (A * B);
		}
	}
	return SubSum;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m = 0;
	cin >> n >> m;
	int** arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	// cout << submatrixSumI(arr, n, m) << endl;	 // BRUTE FORCE
	// cout << submatrixSumII(arr, n, m) << endl;	 // PARTIAL SUM ARRAY
	cout << submatrixSumIII(arr, n, m) << endl;	 // ELEMENT CONTRIBUTION SUM
	return 0;
}
