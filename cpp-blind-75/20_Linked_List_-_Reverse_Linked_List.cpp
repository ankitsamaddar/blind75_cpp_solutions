// DATE: 02-August-2023
/* PROGRAM: 20_Linked List - Reverse Linked List

https://leetcode.com/problems/reverse-linked-list/

Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []

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
	ListNode *reverseList(ListNode *head) {

		ListNode *prev = nullptr;
		ListNode *next;
		while (head) {
			next = head->next;
			head->next = prev;
			prev = head;
			head = next;
		}
		return prev;
		/* RECURSIVE -> slower
		if(!head){
			return nullptr;
		} // 1 -> 2 -> 3 -> NULL
		ListNode* newHead = head;
		if (head->next){
			newHead = reverseList(head->next);
			head->next->next = head;
		}
		head->next = nullptr;

		return newHead;
		*/
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
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(5);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	printList(node1);
	Solution sol;
	ListNode *newHead = sol.reverseList(node1);
	printList(newHead); // after reversing
	return 0;
}
