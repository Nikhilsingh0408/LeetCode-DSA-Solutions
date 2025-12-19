/*
Problem Name : Min Cost Climbing Stairs
LeetCode ID  : 746
Difficulty  : Easy
Link        : https://leetcode.com/problems/min-cost-climbing-stairs/

---------------------------------------------------
Approach: Dynamic Programming
---------------------------------------------------
Idea:
- dp[i] = cost[i] + min(dp[i-1], dp[i-2])
- Answer is min(dp[n-1], dp[n-2])

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
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = cost[0], prev1 = cost[1];

        for (int i = 2; i < cost.size(); i++) {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
};
