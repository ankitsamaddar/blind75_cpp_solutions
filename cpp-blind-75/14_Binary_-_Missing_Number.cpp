// DATE: 28-July-2023
/* PROGRAM: 14_Binary - Missing Number

https://leetcode.com/problems/missing-number/

*/
// @ankitsamaddar @July_2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  int missingNumber(vector<int>& nums) {
    int res = nums.size();  // there should be n numbers from 0 to n

    for (int i = 0; i < nums.size(); i++) {
      // adding index and subtracting actual value at index
      // this will keep the missing number as all other numbers will cancel out
      res += (i - nums[i]);
    }
    return res;
  }
};
int main() {
	int nums[] = {3, 0, 1};
	vector<int> v(nums, nums + sizeof(nums) / sizeof(int));
	Solution sol;
	cout<<sol.missingNumber(v);
	return 0;
}
