// DATE: 02-August-2023
/* PROGRAM: 21_Linked List - Linked List Cycle

https://leetcode.com/problems/linked-list-cycle/

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
    // Fast and Slow pointers

    // initialize both fast and slow pointers at head
    ListNode *fast = head, *slow = head;

    // iterate till fast and fast->next is valid
    while (fast and fast->next) {
      slow = slow->next;
      // skip fast two pointers ahead
      fast = fast->next->next;

      if (slow == fast) return true;  // cycle found
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
