// DATE: 02-August-2023
/* PROGRAM: 22_Linked List - Merge Two Sorted Lists

https://leetcode.com/problems/merge-two-sorted-lists/

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of
the first two lists.

Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]

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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *dummy = new ListNode(-1);
		ListNode *curr = dummy;

		while (l1 and l2) {
			if (l1->val < l2->val) {
				curr->next = l1;
				l1 = l1->next;
			} else {
				curr->next = l2;
				l2 = l2->next;
			}
			curr = curr->next;
		}
		if (l1) { // if l1 is remains
			curr->next = l1;
		} else if (l2) { // if l2 is remains
			curr->next = l2;
		}
		return dummy->next; // pointer to start of current
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
	ListNode *list1 = new ListNode(1);
	list1->next = new ListNode(2);
	list1->next->next = new ListNode(4);
	printList(list1);
	ListNode *list2 = new ListNode(1);
	list2->next = new ListNode(3);
	list2->next->next = new ListNode(4);
	list2->next->next->next = new ListNode(5);
	list2->next->next->next->next = new ListNode(6);
	printList(list2);
	Solution sol;
	ListNode *result = sol.mergeTwoLists(list1, list2);
	printList(result);
	return 0;
}
