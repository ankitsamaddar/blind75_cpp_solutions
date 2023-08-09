// DATE: 28-July-2023
/* PROGRAM: 06_Array - Maximum Product SubArray

https://leetcode.com/problems/maximum-product-subarray/

*/
// @ankitsamaddar @July_2023
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
	int maxProduct(vector<int> &nums) {
		int res = INT_MIN;
		int curMin = 1, curMax = 1, tmp = 0;
		bool zeroPresent = false;
		for (int n : nums) {
			if (n == 0) {
				curMin = 1;
				curMax = 1;
				zeroPresent = true;
				continue;
			}

			tmp = curMax * n;
			curMax = max({n * curMax, n * curMin, n});
			curMin = min({tmp, n * curMin, n});
			res = max(res, curMax);
		}
		if (zeroPresent)
			return max(res, 0);
		return res;
	}
};

/* Solution 2 - fastest - using left and right product

class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int right_p = 1, left_p = 1, maxProduct = INT_MIN;

      for(int i = 0;i<nums.size();i++){
        if(left_p==0) left_p=1;
        if(right_p==0) right_p=1;

        left_p *= nums[i];
        right_p *= nums[nums.size()-i-1];

        maxProduct = max({left_p,right_p,maxProduct});
      }
      return maxProduct;
    }
};

*/

int main() {
	int nums[] = {-2, 0, -1};
	vector<int> v(nums, nums + sizeof(nums) / sizeof(int));
	Solution sol;
	int result = sol.maxProduct(v);
	cout << result << endl;
	return 0;
}
