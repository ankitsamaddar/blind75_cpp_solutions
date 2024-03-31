// DATE: 05-Aug-2023
/* PROGRAM: 30_String - Group Anagrams

https://leetcode.com/problems/group-anagrams/

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

*/
// @ankitsamaddar @Aug_2023
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
	public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> res;
		for (string s : strs) {
			vector<int> count(26, 0);

			for (char c : s) {
				count[c - 'a'] += 1;
			}
			string tmp(count.begin(), count.end());
			res[tmp].push_back(s);
		}
		vector<vector<string>> ans;
		for (auto gp : res) {
			ans.push_back(gp.second);
		}
		return ans;
	}
};

int main() {
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	Solution sol;
	vector<vector<string>> ans = sol.groupAnagrams(strs);
	for(auto str :ans){
		for(auto w:str)
			cout<<w<<" ";

	cout<<endl;
	}

		return 0;
}
