/*
Problem Name : Maximum Path Score in a Grid
Difficulty  : Medium
Category    : Dynamic Programming (Grid DP with Cost Constraint)

---------------------------------------------------
Problem Statement:
You are given an m x n grid with values {0, 1, 2} and
an integer k (maximum allowed cost).

You start from (0,0) and move only right or down to reach
(m-1, n-1).

Each cell:
- 0 → score +0, cost +0
- 1 → score +1, cost +1
- 2 → score +2, cost +1

Return the maximum score achievable without exceeding
total cost k. Return -1 if no valid path exists.

---------------------------------------------------
Approach: 3D Dynamic Programming (Memoization)
---------------------------------------------------
State Definition:
dp[i][j][c] =
    Maximum score achievable starting from cell (i, j)
    with remaining cost = c.

---------------------------------------------------
Transitions:
From cell (i, j):
- Move RIGHT → (i, j+1)
- Move DOWN  → (i+1, j)

Score and cost depend on grid[i][j].

---------------------------------------------------
Base Cases:
1. Out of bounds or cost < 0 → invalid path
2. Reached destination:
   - Check if remaining cost allows taking last cell

---------------------------------------------------
Time Complexity:
- O(m * n * k)

Space Complexity:
- O(m * n * k)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, vector<vector<int>>& grid, int k) {
        // Invalid cases
        if (i >= n || j >= m || k < 0)
            return INT_MIN;

        // Memoization
        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        // Destination cell
        if (i == n - 1 && j == m - 1) {
            if (grid[i][j] == 0 && k >= 0) return 0;
            if (grid[i][j] == 1 && k >= 1) return 1;
            if (grid[i][j] == 2 && k >= 1) return 2;
            return INT_MIN;
        }

        int right = INT_MIN, down = INT_MIN;

        if (grid[i][j] == 0) {
            right = solve(i, j + 1, grid, k);
            down  = solve(i + 1, j, grid, k);
        }
        else if (grid[i][j] == 1) {
            right = 1 + solve(i, j + 1, grid, k - 1);
            down  = 1 + solve(i + 1, j, grid, k - 1);
        }
        else { // grid[i][j] == 2
            right = 2 + solve(i, j + 1, grid, k - 1);
            down  = 2 + solve(i + 1, j, grid, k - 1);
        }

        return dp[i][j][k] = max(right, down);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));

        int ans = solve(0, 0, grid, k);
        return ans < 0 ? -1 : ans;
    }
};
