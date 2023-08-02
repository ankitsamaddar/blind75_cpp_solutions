// DATE: 02-Aug-2023
/* PROGRAM: 23_Linked List - Merge k Sorted Lists

https://leetcode.com/problems/merge-k-sorted-lists/

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

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
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		if (lists.empty() or lists.size() == 0) {
			return NULL;
		}
		while (lists.size() > 1) {
			vector<ListNode *> merged;
			for (int i = 0; i < lists.size(); i += 2) {
				ListNode *l1 = lists[i];
				ListNode *l2 = ((i + 1) < lists.size()) ? lists[i + 1] : NULL; // check if i+1 is valid else NULL
				merged.push_back(mergeList(l1, l2));
			}
			lists = merged; // make the merged list the new list
		}
		return lists[0];
	}

	ListNode *mergeList(ListNode *l1, ListNode *l2) {
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
		if (l1) {
			curr->next = l1;
		} else if (l2) {
			curr->next = l2;
		}
		return dummy->next;
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
	vector<ListNode *> lists;

	ListNode *list1 = new ListNode(1);
	list1->next = new ListNode(4);
	list1->next->next = new ListNode(5);
	printList(list1);
	lists.push_back(list1);

	ListNode *list2 = new ListNode(1);
	list2->next = new ListNode(3);
	list2->next->next = new ListNode(4);
	printList(list2);
	lists.push_back(list2);

	ListNode *list3 = new ListNode(2);
	list3->next = new ListNode(6);
	printList(list3);
	lists.push_back(list3);

	Solution sol;
	ListNode *result = sol.mergeKLists(lists);
	printList(result);
	return 0;
}
