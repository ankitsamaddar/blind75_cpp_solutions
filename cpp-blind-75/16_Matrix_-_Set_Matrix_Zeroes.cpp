// DATE: 29-July-2023
/* PROGRAM: 16_Matrix - Set Matrix Zeroes

https://leetcode.com/problems/set-matrix-zeroes/

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.



Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

*/
// @ankitsamaddar @July_2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
	void setZeroes(vector<vector<int>> &matrix) {
		int rows = matrix.size(), col = matrix[0].size();
		bool rowZero = false;

		// Determine Rows/Column to be zeroed
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < col; c++) {
				if (matrix[r][c] == 0) {
					matrix[0][c] = 0;
					if (r > 0)
						matrix[r][0] = 0;
					else
						rowZero = true;
				}
			}
		}
		// Zero the columns starting from the second row and second column
		for (int r = 1; r < rows; r++) {
			for (int c = 1; c < col; c++) {
				if (matrix[0][c] == 0 or matrix[r][0] == 0) {
					matrix[r][c] = 0;
				}
			}
		}
		// zero the first row
		if (matrix[0][0] == 0) {
			for (int r = 0; r < rows; r++) {
				matrix[r][0] = 0;
			}
		}
		// zero the first column
		if (rowZero) {
			for (int c = 0; c < col; c++) {
				matrix[0][c] = 0;
			}
		}
	}
};

int main() {
	vector<vector<int>> nums = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
	Solution sol;
	sol.setZeroes(nums);
	for(auto row:nums){
		for(int col:row){
			cout<<col<<" ";
		}
		cout<<endl;
	}
	return 0;
}
