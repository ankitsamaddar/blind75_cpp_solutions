// DATE: 27-07-2023
/* PROGRAM: 02_Array - Best Time to Buy and Sell Stock

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different
day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit,
return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

*/
// @ankitsamaddar @2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
	int maxProfit(vector<int> &prices) {
		int l = 0, r = 1, maxP = 0;
		int len = prices.size();
		while (r < len) {
			if (prices[l] < prices[r]) {
				int profit = prices[r] - prices[l];
				maxP = max(maxP, profit);
			} else
				l = r; // least possible price
			r++;
		}
		return maxP;
	}
};

int main() {

	int arr[] = {7, 6, 4, 3, 1};
	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
	Solution sol;
	int ret = sol.maxProfit(v);
	cout << ret << endl;
	return 0;
}
