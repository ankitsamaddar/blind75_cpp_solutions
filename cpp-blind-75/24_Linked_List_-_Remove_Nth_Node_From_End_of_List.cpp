// DATE: 02-Aug-2023
/* PROGRAM: 24_Linked List - Remove Nth Node From End of List

https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

*/
// @ankitsamaddar @Aug_2023
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
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode *res = new ListNode(0, head);
		ListNode *left = res;
		ListNode *right = head;

		while (n > 0 and right) {
			right = right->next;
			n--;
		}

		while (right) {
			left = left->next;
			right = right->next;
		}

		left->next = left->next->next;
		return res->next;
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
	list1->next->next = new ListNode(3);
	list1->next->next->next = new ListNode(4);
	list1->next->next->next->next = new ListNode(5);
	printList(list1);
	int n = 2;
	Solution sol;
	ListNode *result = sol.removeNthFromEnd(list1, n);
	printList(result);
	return 0;
}
