// DATE: 27-07-2023
/* PROGRAM: 01_Array - Two Sum

https://leetcode.com/problems/two-sum/

*/
// @ankitsamaddar @2023
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;

        for (int i = 0; i < nums.size(); i++) {

            // dif is the required number to sum to target
            int dif = target - nums[i];

            // check if dif is hashed
            if (hash.count(dif) > 0) {
                return {hash[dif], i};
            }

            // store num index
            hash[nums[i]] = i;
        }

        // not found
        return {};
    }
};

int main() {
    int nums[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int target = 9;
    vector<int> v(nums, nums + sizeof(nums) / sizeof(int));
    Solution sol;
    vector<int> rem = sol.twoSum(v, target);

    for (int val : rem) {
        cout << val << " ";
    }
    return 0;
}
