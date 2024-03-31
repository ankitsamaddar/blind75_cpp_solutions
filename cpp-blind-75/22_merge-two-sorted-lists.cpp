// DATE: 02-August-2023
/* PROGRAM: 22_Linked List - Merge Two Sorted Lists

https://leetcode.com/problems/merge-two-sorted-lists/

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
	ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    // creating a node(-1) whose next element will be the merged List
    ListNode *ans = new ListNode(-1);
    // itr to iterate and create the list
    // ans will still store the beginning pointer to the list
    ListNode *itr = ans;

    while (list1 and list2) {
      if (list1->val < list2->val) {
        itr->next = list1;
        list1     = list1->next;  // increment list1
      } else {
        itr->next = list2;
        list2     = list2->next;  // increment list2
      }
      itr = itr->next;  // increment itr
    }
    if (list1) {  // list1 remains
      itr->next = list1;
    }
    if (list2) {  // list2 remains
      itr->next = list2;
    }
    return ans->next;
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
