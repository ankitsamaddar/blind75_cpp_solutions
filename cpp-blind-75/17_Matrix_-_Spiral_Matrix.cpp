// DATE: 29-July-2023
/* PROGRAM: 17_Matrix - Spiral Matrix

https://leetcode.com/problems/spiral-matrix/


*/
// @ankitsamaddar @July_2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    // result vector
    vector<int> res;

    // set the pointers
    int left = 0, right = matrix[0].size() - 1;
    int top = 0, bottom = matrix.size() - 1;

    while (left <= right and top <= bottom) {
      // top row
      for (int i = left; i <= right; i++) res.push_back(matrix[top][i]);
      top++;
      // right column
      for (int i = top; i <= bottom; i++) res.push_back(matrix[i][right]);
      right--;

      // bottom row
      if (top <= bottom) {
        for (int i = right; i >= left; i--) res.push_back(matrix[bottom][i]);
        bottom--;
      }
      // left column
      if (left <= right) {
        for (int i = bottom; i >= top; i--) res.push_back(matrix[i][left]);
        left++;
      }
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
