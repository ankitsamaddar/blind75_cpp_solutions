// DATE: 02-Aug-2023
/* PROGRAM: 25_Linked List - Reorder List

https://leetcode.com/problems/reorder-list/

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

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
	void reorderList(ListNode *head) {
		ListNode *slow = head;
		ListNode *fast = head->next;
		while (fast and fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		// reverse second half
		ListNode *second = slow->next;
		slow->next = NULL;
		ListNode *prev = NULL;
		while (second) {
			ListNode *temp = second->next;
			second->next = prev;
			prev = second;
			second = temp;
		}
		// merge alternately
		ListNode *first = head;
		second = prev;
		while (second) {
			ListNode *tmp1 = first->next;
			ListNode *tmp2 = second->next;
			first->next = second;
			second->next = tmp1;
			first = tmp1;
			second = tmp2;
		}
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
	Solution sol;
	sol.reorderList(list1);
	printList(list1);
	return 0;
}
