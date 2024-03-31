// DATE: 02-August-2023
/* PROGRAM: 20_Linked List - Reverse Linked List

https://leetcode.com/problems/reverse-linked-list/

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
    // last element of a Linkedlist  points to null

    ListNode *ans = nullptr;  // initialize the answer
    ListNode *temp;           // to temporarily store next pointer of head

    while (head) {
      temp = head->next;

      // set head->next to point to ans
      // initially this will set to null
      // as it will be last element when reversed
      head->next = ans;

      // set ans as head
      ans = head;

      // restore next head pointer
      head = temp;
    }
    return ans;
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
