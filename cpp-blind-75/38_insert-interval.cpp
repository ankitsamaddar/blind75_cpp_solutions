// DATE: 06-Aug-2023
/* PROGRAM: 38_Interval - Insert Interval

https://leetcode.com/problems/insert-interval/

Given a non-overlapping interval list which is sorted by start point.
Insert a new interval into it, make sure the list is still in order and non-overlapping (merge
intervals if necessary).

Return intervals after the insertion.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

*/
// @ankitsamaddar @Aug_2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> res;

        if (intervals.size() == 0) {  // intervals is empty
            res.push_back(newInterval);
        }

        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval[1] < intervals[i][0]) {  // newInterval.end < intervals[i].start
                res.push_back(newInterval);
                for (int j = i; j < intervals.size(); j++) {  // add rest of intervals
                    res.push_back(intervals[j]);
                }
                break;
            }

            else if (newInterval[0] > intervals[i][1]) {  // add intervals[i] to the res and
                                                          // continue
                res.push_back(intervals[i]);
            }

            else {  // overlapping intervals -> newInterval = {min(newInterval.start,
                    // intervals[i].start),max(newInterval.end, intervals[i].end)}
                newInterval = {min(newInterval[0], intervals[i][0]),
                               max(newInterval[1], intervals[i][1])};
            }

            if (i == intervals.size() - 1) {  // add at the end
                res.push_back(newInterval);
            }
        }
        return res;
    }
};

void printVector(vector<int> const &input,bool tr = true) {  // 1d print
    cout << "[";
    for (int i = 0; i < input.size(); i++) {
        cout << input[i];
        if (i != input.size() - 1) {
            cout << ",";
        }
    }
    cout << "]";
	if(tr) cout<<endl;
}

void printVector(vector<vector<int>> const &input) {  // 2d print
    cout << "[";
    for (int i = 0; i < input.size(); i++) {
        printVector(input[i],false);
        if (i != input.size() - 1) {
            cout << ",";
        }
    }
    cout << "]"<<endl;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval       = {2, 5};
    Solution sol;
    vector<vector<int>> res = sol.insert(intervals, newInterval);
	printVector(intervals);
	printVector(newInterval);
	printVector(res);

    return 0;
}
