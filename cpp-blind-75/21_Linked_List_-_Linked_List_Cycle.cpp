// DATE: 02-August-2023
/* PROGRAM: 21_Linked List - Linked List Cycle

https://leetcode.com/problems/linked-list-cycle/

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by
continuously following the next pointer. Internally, pos is used to denote the index of the node
that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node
(0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

*/
// @ankitsamaddar @August_2023
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
	bool hasCycle(ListNode *head) {
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast and fast->next) {
			slow = slow->next;
			fast = fast->next->next; // fast is 2 ahead
			if (slow == fast)
				return true;
		}
		return false;
	}
};

void printList(ListNode *head) {
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {
	ListNode *node1 = new ListNode(3);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(0);
	ListNode *node4 = new ListNode(-4);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node1;
	// printList(node1);
	Solution sol;
	cout<<boolalpha<<sol.hasCycle(node2)<<endl;
	return 0;
}
