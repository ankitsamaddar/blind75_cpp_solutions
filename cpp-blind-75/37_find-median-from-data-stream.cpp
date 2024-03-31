// DATE: 06-Aug-2023
/* PROGRAM: 37_Heap - Find Median from Data Stream

https://leetcode.com/problems/find-median-from-data-stream/

The median is the middle value in an ordered integer list. If the size of the list is even, there is
no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual
answer will be accepted.

Example 1:
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0

*/
// @ankitsamaddar @Aug_2023
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
    private:
    // A heap triangle is divided into two parts where top is the smallest element and bottom is the
    // largest, the smaller triangle represents a top heap with the largest element at the bottom
    // (MaxHeap), and the larger quadrilateral represents a bottom heap with the smallest element at
    // the top (MinHeap).
    priority_queue<int> topHeap;                                // Top Heap -> Max at top
    priority_queue<int, vector<int>, greater<int>> bottomHeap;  // Bottom Heap -> Min at top
    public:
    MedianFinder() {}

    void addNum(int num) {
        if (bottomHeap.size() >= topHeap.size()) {
            bottomHeap.push(num);
            topHeap.push(bottomHeap.top());
            bottomHeap.pop();
        } else {
            topHeap.push(num);
            bottomHeap.push(topHeap.top());
            topHeap.pop();
        }
    }

    double findMedian() {
        if (topHeap.size() > bottomHeap.size()) {
            return topHeap.top();
        } else if (bottomHeap.size() > topHeap.size()) {
            return bottomHeap.top();
        }
        return (topHeap.top() + bottomHeap.top()) / 2.0;
    }
};

int main() {
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    cout << medianFinder.findMedian() << endl;  // expected output: 1.5
    medianFinder.addNum(3);
    cout << medianFinder.findMedian() << endl;  // expected output: 2.0
    return 0;
}
