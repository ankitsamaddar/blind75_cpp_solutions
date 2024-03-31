// DATE: 06-Aug-2023
/* PROGRAM: 39_Interval - Merge Intervals

https://leetcode.com/problems/merge-intervals/

Given an array of intervals where intervals[i] = [start_i, end_i], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/
// @ankitsamaddar @Aug_2023
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
		// SORT IS ASCENDING ORDER BY THE START OF INTERVAL USING A FUNCTOR
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) { return a[0] < b[0]; });
        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (vector<int> &cur : intervals) {
            auto &lastEnd = res.back();
            if (cur[0] <= lastEnd[1]) {
                lastEnd[1] = max(lastEnd[1], cur[1]);
            } else {
				// add the next interval
                res.push_back(cur);
            }
        }
        return res;
    }
};

void printVector(vector<int> const &input, bool tr = true) {  // 1d print
    cout << "[";
    for (int i = 0; i < input.size(); i++) {
        cout << input[i];
        if (i != input.size() - 1) {
            cout << ",";
        }
    }
    cout << "]";
    if (tr) cout << endl;
}

void printVector(vector<vector<int>> const &input) {  // 2d print
    cout << "[";
    for (int i = 0; i < input.size(); i++) {
        printVector(input[i], false);
        if (i != input.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

int main() {
	vector<vector<int>> intervals = {{ 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } };
	Solution sol;
    vector<vector<int>> res = sol.merge(intervals);
	printVector(intervals);
	printVector(res);
	return 0;
    }
