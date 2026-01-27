/*
Problem Name : Largest Magic Square
LeetCode ID  : 1895
Difficulty  : Medium
Category    : Matrix / Prefix Sum / Brute Force Optimization

---------------------------------------------------
Problem Statement:
A k x k magic square is a square grid where:
- All row sums are equal
- All column sums are equal
- Both diagonal sums are equal

Given a grid, return the maximum possible k.

---------------------------------------------------
Key Observations:
1. Any 1x1 grid is always a magic square.
2. We must check row sums, column sums, and both diagonals.
3. Brute force checking every kxk square is expensive unless optimized.

---------------------------------------------------
Optimization Strategy:
- Precompute prefix sums for rows and columns.
- This allows O(1) row and column sum queries.
- Diagonals are computed directly (small cost).

---------------------------------------------------
Approach:
1. Precompute:
   - Row prefix sums
   - Column prefix sums
2. Try square sizes from largest to smallest.
3. For each square:
   - Use first row as reference sum
   - Validate all rows and columns using prefix sums
   - Validate both diagonals
4. Return first valid (largest) size.

---------------------------------------------------
Time Complexity:
- O(min(m,n)³)

Space Complexity:
- O(m × n)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Row prefix sums
        vector<vector<int>> rowSum(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            rowSum[i][0] = grid[i][0];
            for (int j = 1; j < n; j++) {
                rowSum[i][j] = rowSum[i][j - 1] + grid[i][j];
            }
        }

        // Column prefix sums
        vector<vector<int>> colSum(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            colSum[0][j] = grid[0][j];
            for (int i = 1; i < m; i++) {
                colSum[i][j] = colSum[i - 1][j] + grid[i][j];
            }
        }

        // Try all square sizes from largest to smallest
        for (int k = min(m, n); k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {

                    int target =
                        rowSum[i][j + k - 1] - (j ? rowSum[i][j - 1] : 0);
                    bool valid = true;

                    // Check rows
                    for (int r = i; r < i + k; r++) {
                        int sum =
                            rowSum[r][j + k - 1] - (j ? rowSum[r][j - 1] : 0);
                        if (sum != target) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) continue;

                    // Check columns
                    for (int c = j; c < j + k; c++) {
                        int sum =
                            colSum[i + k - 1][c] - (i ? colSum[i - 1][c] : 0);
                        if (sum != target) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) continue;

                    // Check diagonals
                    int d1 = 0, d2 = 0;
                    for (int t = 0; t < k; t++) {
                        d1 += grid[i + t][j + t];
                        d2 += grid[i + t][j + k - 1 - t];
                    }

                    if (d1 == target && d2 == target)
                        return k;
                }
            }
        }

        return 1; // at least 1x1 always works
    }
};
