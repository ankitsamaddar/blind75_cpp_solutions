// DATE: 28-July-2023
/* PROGRAM: 10_Array - Container With Most Water

https://leetcode.com/problems/container-with-most-water/

You are given an integer array height of length n. There are n vertical lines drawn such that the
two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the
most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.


Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case,
the max area of water (blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1

*/
// @ankitsamaddar @July_2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
	// BRUTE FORCE O(n^2)
	/*
	int maxArea(vector<int>& height) {
		int res =0;
		for (int l = 0 ;l < height.size();l++){
			for(int r=l+1;r<height.size();r++){
				// area = length(r_index - l_index) * breadth(min of )
				int area = (r - l)*min(height[l],height[r]);
				res = max(res,area);
			}
		}
		return res;
	} */
	// LINEAR O(n)
	int maxArea(vector<int> &height) {
		int res = 0, l = 0, r = height.size() - 1;
		while (l < r) {
			int area = (r - l) * min(height[l], height[r]);
			res = max(res, area);

			if (height[l] < height[r]) {
				l++;
			} else if (height[l] > height[r]) {
				r--;
			} else
				r--;
		}
		return res;
	}
};

int main() {
	int nums[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	vector<int> v(nums, nums + sizeof(nums) / sizeof(int));
	Solution sol;
	int res = sol.maxArea(v);
	cout << res <<endl;
	return 0;
}
