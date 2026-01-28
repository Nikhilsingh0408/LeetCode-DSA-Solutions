/*
Problem Name : Minimum Cost Path with Teleportations
LeetCode ID  : 3651
Difficulty  : Hard
Category    : Dynamic Programming / Grid / Optimization

---------------------------------------------------
Problem Statement:
You are given a grid and allowed to move:
1. Normally (right or down) with cost = destination cell value
2. Teleport (at most k times):
   - From (i,j) → (x,y) if grid[x][y] <= grid[i][j]
   - Teleport cost = 0

Return the minimum cost to reach (m-1, n-1).

---------------------------------------------------
Key Observations:
1. Normal moves form a classic grid DP problem.
2. Teleport allows jumping to *any cell* with value ≤ current.
3. Teleport count is small (k ≤ 10) → layered DP possible.
4. Naively checking all teleport targets is too slow.

---------------------------------------------------
Core Optimization Idea:
Instead of teleporting to every valid cell:
- Maintain `best_teleport[v]` = minimum dp-cost among all cells
  with value ≤ v.
- This allows O(1) teleport cost lookup.

---------------------------------------------------
DP Definition:
dp[r][c] = minimum cost to reach destination from (r,c)
           using ≤ current number of teleports.

---------------------------------------------------
Transition:
dp[r][c] = min(
    dp[r+1][c] + grid[r+1][c],   // move down
    dp[r][c+1] + grid[r][c+1],   // move right
    best_teleport[grid[r][c]]    // teleport
)

---------------------------------------------------
Algorithm:
1. Initialize dp with INF, dp[dest] = 0
2. For t = 0 → k:
   a. Recompute dp using current best_teleport
   b. Build new best_teleport from dp
3. Answer is dp[0][0]

---------------------------------------------------
Time Complexity:
- O(k * m * n)

Space Complexity:
- O(m * n + max(grid))

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static constexpr int INF = 1e9;
    int rows, cols, maxVal;

    void dpIteration(vector<vector<int>>& dp,
                     vector<int>& bestTeleport,
                     vector<vector<int>>& grid) {
        for (int r = rows - 1; r >= 0; --r) {
            for (int c = cols - 1; c >= 0; --c) {
                int walk = ((r == rows - 1 && c == cols - 1) ? 0 : INF);

                if (r + 1 < rows)
                    walk = min(walk, dp[r + 1][c] + grid[r + 1][c]);
                if (c + 1 < cols)
                    walk = min(walk, dp[r][c + 1] + grid[r][c + 1]);

                dp[r][c] = min(walk, bestTeleport[grid[r][c]]);
            }
        }
    }

    vector<int> buildTeleport(vector<vector<int>>& dp,
                              vector<vector<int>>& grid) {
        vector<int> teleport(maxVal + 1, INF);

        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                teleport[grid[r][c]] =
                    min(teleport[grid[r][c]], dp[r][c]);

        for (int v = 1; v <= maxVal; v++)
            teleport[v] = min(teleport[v], teleport[v - 1]);

        return teleport;
    }

    int minCost(vector<vector<int>>& grid, int k) {
        rows = grid.size();
        cols = grid[0].size();
        maxVal = 0;

        for (auto& row : grid)
            for (int x : row)
                maxVal = max(maxVal, x);

        vector<vector<int>> dp(rows, vector<int>(cols, INF));
        dp[rows - 1][cols - 1] = 0;

        vector<int> bestTeleport(maxVal + 1, INF);

        for (int t = 0; t <= k; t++) {
            dpIteration(dp, bestTeleport, grid);
            bestTeleport = buildTeleport(dp, grid);
        }

        return dp[0][0];
    }
};
