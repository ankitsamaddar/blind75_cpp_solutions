// DATE: 06-Aug-2023
/* PROGRAM: 36_Heap - Top K Frequent Elements_Bucket Sort

https://leetcode.com/problems/top-k-frequent-elements/

Given an integer array nums and an integer k, return the k most frequent elements. You may return
the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

*/
// @ankitsamaddar @Aug_2023
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        map<int, int> map = {};
        vector<vector<int>> freq(nums.size() + 1);
        vector<int> res;
        for (int i : nums) {
            map[i] += 1;
        }

        for (auto &it : map) {
            freq[it.second].push_back(it.first);
        }

        // STORE MOST FREQUENCY UPTO K
        for (int i = freq.size() - 1; i > 0; i--) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};

// PRINTER FUNCTION
void printArr(vector<int> &v) {
    std::cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    vector<int> nums = {1, 2};
    int k            = 2;
    Solution sol;
    vector<int> res = sol.topKFrequent(nums, k);
    printArr(res);
    return 0;
}
