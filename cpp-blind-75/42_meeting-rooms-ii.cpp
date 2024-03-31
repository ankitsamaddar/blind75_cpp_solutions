// DATE: 06-Aug-2023
/* PROGRAM: 42_Interval - Meeting Rooms II

https://www.lintcode.com/problem/919/

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si
< ei), find the minimum number of conference rooms required.)

Note: (0,8),(8,10) is not conflict at 8

Example 1:
Input: intervals = [(0,30),(5,10),(15,20)]
Output: 2
Explanation: We need two meeting rooms
room1: (0,30)
room2: (5,10),(15,20)

Example 2:
Input: intervals = [(2,7)]
Output: 1
Explanation: Only need one meeting room

*/
// @ankitsamaddar @Aug_2023
#include <algorithm>
#include <iostream>
#include <queue>
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
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
            if (a.start != b.start) {
                return a.start < b.start;
            } else
                return a.start < b.start;
        });
        // total rooms
        priority_queue<int, vector<int>, greater<int>> pq;

        // 1st meeting
        pq.push(intervals[0].end);
        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i].start;
            if (start >= pq.top()) {
                pq.pop();  // previous meeting ends before current so room not required
            }
            // reallocate old room
            // add new room
            pq.push(intervals[i].end);
        }
        // size of the queue is the total rooms required
        return pq.size();
    }
};

int main() {
    vector<Interval> nums = {{65, 424}, {351, 507}, {314, 807}, {387, 722},
                             {19, 797}, {259, 722}, {165, 221}, {136, 897}};
    Solution sol;
    cout << sol.minMeetingRooms(nums);  // Output: 7

    return 0;
}
