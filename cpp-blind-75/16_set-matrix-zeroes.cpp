// DATE: 29-July-2023
/* PROGRAM: 16_Matrix - Set Matrix Zeroes

https://leetcode.com/problems/set-matrix-zeroes/

G*/
// @ankitsamaddar @July_2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();

    bool fillFirstRow = false;
    bool fillFirstCol = false;

    // mark the matrix to add zero
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (matrix[r][c] == 0) {
          // set the flags to handle first row & column
          if (r == 0) fillFirstRow = true;
          if (c == 0) fillFirstCol = true;

          // mark first column of match to 0
          matrix[0][c] = 0;
          // mark first rows of match to 0
          matrix[r][0] = 0;
        }
      }
    }

    // add zeros to the internal matrix (except the first row & column)
    for (int r = 1; r < rows; r++) {
      for (int c = 1; c < cols; c++) {
        // using mark to add zeros
        if (matrix[r][0] == 0 || matrix[0][c] == 0) {
          matrix[r][c] = 0;
        }
      }
    }

    // add zero to the first column
    if (fillFirstCol)
      for (int r = 1; r < rows; r++) matrix[r][0] = 0;

    // add zero to the first row
    if (fillFirstRow) {
      for (int c = 0; c < cols; c++) matrix[0][c] = 0;
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
