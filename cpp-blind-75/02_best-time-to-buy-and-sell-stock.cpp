// DATE: 27-07-2023
/* PROGRAM: 02_Array - Best Time to Buy and Sell Stock

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

*/
// @ankitsamaddar @2023
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
	int maxProfit(vector<int> &prices) {
		int left = 0, right = 1, maxProfit = 0;
		int len = prices.size();
		while (right < len) {
			if (prices[left] < prices[right]) {
				int profit = prices[right] - prices[left];
				maxProfit = max(maxProfit, profit);
			} else
				left = right; // least possible price
			right++;
		}
		return maxProfit;
	}
};

/* Solution 2 - using for loop
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int i = 0;i<prices.size();i++){
            // Calculate minPrice
            if(prices[i]<minPrice){
                minPrice = prices[i];
            }
            // Calculate maxProfit
            else if(prices[i] - minPrice > maxProfit){
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};
*/

int main() {

	int arr[] = {7, 6, 4, 3, 1};
	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
	Solution sol;
	int ret = sol.maxProfit(v);
	cout << ret << endl;
	return 0;
}
