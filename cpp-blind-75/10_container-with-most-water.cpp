// DATE: 28-July-2023
/* PROGRAM: 10_Array - Container With Most Water

https://leetcode.com/problems/container-with-most-water/

*/
// @ankitsamaddar @July_2023
#include <iostream>
#include <vector>
using namespace std;

// BRUTE FORCE O(n^2)
/*
class Solution {
  public:
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
  }
};
*/
// LINEAR O(n)
class Solution {
  public:
  int maxArea(vector<int>& height) {
    long long maxArea = 0;
    int left = 0, right = height.size() - 1;

    while (left < right) {
      int length  = right - left;
      int breadth = min(height[left], height[right]);

      // calculate area and store the max area
      long long area = length * breadth;
      maxArea        = max(area, maxArea);

      // move left towards right if left is smaller than right
      if (height[left] < height[right])
        left++;
      else
        right--;  // move right toward left
    }
    return maxArea;
  }
};

int main() {
  int nums[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  vector<int> v(nums, nums + sizeof(nums) / sizeof(int));
  Solution sol;
  int res = sol.maxArea(v);
  cout << res << endl;
  return 0;
}
