/*
Problem Name : Delete Columns to Make Sorted III
LeetCode ID  : 960
Difficulty  : Hard
Category    : Dynamic Programming / Longest Increasing Subsequence (LIS)

---------------------------------------------------
Problem Statement:
You are given n strings of equal length.
You may delete columns such that after deletions,
EACH ROW individually becomes lexicographically sorted.

Return the minimum number of columns to delete.

---------------------------------------------------
Key Insight:
Instead of deciding which columns to delete,
decide which columns to KEEP.

We want to keep the maximum number of columns such that:
For every row r:
    strs[r][i] <= strs[r][j]   for kept columns i < j

This is equivalent to finding a LIS on columns
with a custom comparison across all rows.

---------------------------------------------------
Approach: DP (LIS on Columns)
---------------------------------------------------
Let:
dp[j] = maximum number of columns we can keep
        ending at column j.

Transition:
For every i < j:
    if for all rows r:
        strs[r][i] <= strs[r][j]
    then:
        dp[j] = max(dp[j], dp[i] + 1)

Answer:
- maxKept = max(dp[j])
- deletions = totalColumns - maxKept

---------------------------------------------------
Why This Works:
- Each row must be non-decreasing after deletions.
- LIS ensures we keep the longest valid column sequence
  satisfying all rows simultaneously.

---------------------------------------------------
Time Complexity:
- O(m² * n)
  where m = number of columns, n = number of rows

Space Complexity:
- O(m)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        vector<int> dp(m, 1);
        int maxKept = 1;

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < j; i++) {
                bool valid = true;

                // Check all rows
                for (int r = 0; r < n; r++) {
                    if (strs[r][i] > strs[r][j]) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            maxKept = max(maxKept, dp[j]);
        }

        return m - maxKept;
    }
};
