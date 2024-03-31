// DATE: 06-Aug-2023
/* PROGRAM: 41_Interval - Meeting Rooms

https://www.lintcode.com/problem/920/

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si
< ei), determine if a person could attend all meetings.

Note: (0,8),(8,10) is not conflict at 8

Example 1:
Input: intervals = [(0,30),(5,10),(15,20)]
Output: false
Explanation: (0,30), (5,10) and (0,30),(15,20) will conflict

Example 2:
Input: intervals = [(5,8),(9,15)]
Output: true
Explanation: Two times will not conflict

*/
// @ankitsamaddar @Aug_2023
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Definition of Interval:
class Interval {
    public:
    int start, end;

    Interval(int start, int end) {
        this->start = start;
        this->end   = end;
    }
};

class Solution {
    public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](Interval a, Interval b) { return a.start <= b.start; });
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i - 1].end > intervals[i].start) {
                // overlapping intervals then false
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<Interval> nums = {{0, 30}, {5, 10}, {15, 20}};

    Solution sol;
    cout << boolalpha << sol.canAttendMeetings(nums);  // Output: false

    return 0;
}
