/*
Problem Name : Maximum Side Length of a Square with Sum ≤ Threshold
LeetCode ID  : 1292
Difficulty  : Medium
Category    : Prefix Sum / Matrix / Sliding Window

---------------------------------------------------
Problem Statement:
Given an m x n matrix mat and an integer threshold,
find the maximum side length of a square submatrix
whose sum is ≤ threshold.

Return 0 if no such square exists.

---------------------------------------------------
Key Observation:
- Square submatrix sum queries must be fast.
- Prefix Sum allows O(1) submatrix sum calculation.
- If a square of side L is valid, smaller squares
  are also valid.

---------------------------------------------------
Approach: 2D Prefix Sum + Greedy Expansion
---------------------------------------------------
1. Build a prefix sum matrix:
   pref[i][j] = sum of elements in rectangle (0,0) → (i-1,j-1)

2. Try to increase square size greedily:
   - At each cell, try to expand the square to size (currentMax + 1)
   - Compute square sum using prefix sum
   - If valid, update max side length

---------------------------------------------------
Prefix Sum Formula (Square Sum):
For square ending at (row, col) of size len:

sum =
pref[row][col]
- pref[row-len][col]
- pref[row][col-len]
+ pref[row-len][col-len]

---------------------------------------------------
Time Complexity:
- O(m × n)

Space Complexity:
- O(m × n)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));

        // Build prefix sum
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] = mat[i - 1][j - 1]
                           + pref[i - 1][j]
                           + pref[i][j - 1]
                           - pref[i - 1][j - 1];
            }
        }

        int maxLen = 0;

        // Try expanding square greedily
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int nextLen = maxLen + 1;
                if (i >= nextLen && j >= nextLen) {
                    int sum = pref[i][j]
                            - pref[i - nextLen][j]
                            - pref[i][j - nextLen]
                            + pref[i - nextLen][j - nextLen];

                    if (sum <= threshold) {
                        maxLen++;
                    }
                }
            }
        }

        return maxLen;
    }
};
