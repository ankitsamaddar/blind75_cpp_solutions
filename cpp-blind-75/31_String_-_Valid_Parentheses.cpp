// DATE: 05-Aug-2023
/* PROGRAM: 31_String - Valid Parentheses

https://leetcode.com/problems/valid-parentheses/

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the
input string is valid.

An input string is valid if:

1.Open brackets must be closed by the same type of brackets.
2.Open brackets must be closed in the correct order.
3.Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

*/
// @ankitsamaddar @Aug_2023
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
	public:
	bool isValid(string s) {
		stack<char> st;
		for (char c : s) {
			if (c == '{' || c == '(' || c == '[') {
				st.push(c);
			} else {
				if (!st.empty() and topC(c) == st.top()) {
					st.pop();
				} else
					return false;
			}
		}
		return st.empty();
	}

	char topC(char c) {
		if (c == ')') return '(';
		if (c == '}') return '{';
		return '[';
	}
};

int main() {
	string s = "([])[]{}";
	Solution sol;
	cout<<boolalpha<<sol.isValid(s);
	return 0;
}
