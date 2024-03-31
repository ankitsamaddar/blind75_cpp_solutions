// DATE: 06-Aug-2023
/* PROGRAM: 40_Interval - Non-overlapping Intervals

https://leetcode.com/problems/non-overlapping-intervals/

Given an array of intervals intervals where intervals[i] = [start_i, end_i], return the minimum
number of intervals you need to remove to make the rest of the intervals non-overlapping.

Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

*/
// @ankitsamaddar @Aug_2023
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        int res     = 0;
        int prevEnd = 0;

        for (vector<int> cur : intervals) {
            int start = cur[0];
            if (start >= prevEnd) {
                prevEnd = cur[1];
            } else {
                res++;
                prevEnd = min(cur[1], prevEnd);
            }
        }
        return res;  // res = total discarded intervals
    }
};

int main() {
    vector<vector<int>> nums = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    Solution sol;
    cout << sol.eraseOverlapIntervals(nums) << endl;
    return 0;
}
