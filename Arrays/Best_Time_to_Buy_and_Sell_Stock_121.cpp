/*
Problem Name : Best Time to Buy and Sell Stock
LeetCode ID  : 121
Difficulty  : Easy
Link        : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

---------------------------------------------------
Problem Statement:
You are given an array prices where prices[i] represents
the stock price on the ith day.

You want to maximize your profit by choosing a single day
to buy one stock and a different day in the future to sell
that stock.

If no profit can be achieved, return 0.

---------------------------------------------------
Example 1:
Input  : prices = [7,1,5,3,6,4]
Output : 5

Example 2:
Input  : prices = [7,6,4,3,1]
Output : 0

---------------------------------------------------
Approach 1: Prefix Minimum Array
---------------------------------------------------
Idea:
- Maintain an array where prefix_min[i] stores the minimum
  price from day 0 to day i.
- For each day, calculate profit as:
    prices[i] - prefix_min[i]
- Track the maximum profit.

---------------------------------------------------
Time Complexity:
- O(n)

Space Complexity:
- O(n)

---------------------------------------------------
Approach 2: Single Pass (Optimal)
---------------------------------------------------
Idea:
- Keep track of the minimum price seen so far.
- For each day:
  - Update the minimum price.
  - Calculate the profit if sold today.
- This avoids using extra space.

---------------------------------------------------
Time Complexity:
- O(n)

Space Complexity:
- O(1)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // -------------------------------
    // Approach 1: Prefix Minimum Array
    // -------------------------------
    int maxProfitPrefix(vector<int>& prices) {
        int n = prices.size();
        vector<int> prefix_min(n);

        prefix_min[0] = prices[0];
        for (int i = 1; i < n; i++) {
            prefix_min[i] = min(prefix_min[i - 1], prices[i]);
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            result = max(result, prices[i] - prefix_min[i]);
        }

        return result;
    }

    // -------------------------------
    // Approach 2: Single Pass (Optimal)
    // -------------------------------
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};
