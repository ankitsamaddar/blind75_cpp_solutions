// DATE: 29-July-2023
/* PROGRAM: 17_Matrix - Spiral Matrix

https://leetcode.com/problems/spiral-matrix/

Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*/
// @ankitsamaddar @July_2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
	vector<int> spiralOrder(vector<vector<int>> &matrix) {
		vector<int> res;
		int left = 0, right = matrix[0].size(), top = 0, bottom = matrix.size();
		while (left < right and top < bottom) {
			// Insert top row
			for (int i = left; i < right; i++) {
				res.push_back(matrix[top][i]);
			}
			top++;
			// Insert right column
			for (int i = top; i < bottom; i++) {
				res.push_back(matrix[i][right - 1]);
			}
			right--;

			if (!(left < right and top < bottom)) {
				break;
			}
			// Insert Bottom row
			for (int i = right - 1; i >= left; i--) {
				res.push_back(matrix[bottom - 1][i]);
			}
			bottom--;
			// Insert Left row
			for (int i = bottom - 1; i >= top; i--) {
				res.push_back(matrix[i][left]);
			}
			left++;
		}
		return res;
	}
};

int main() {
	vector<vector<int>> nums = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	Solution sol;
	vector<int> res = sol.spiralOrder(nums);
	for(int val:res){
		cout<<val<<" ";
	}
	cout<<endl;

	return 0;
}
