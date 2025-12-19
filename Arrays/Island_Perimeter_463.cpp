/*
Problem Name : Island Perimeter
LeetCode ID  : 463
Difficulty  : Easy
Link        : https://leetcode.com/problems/island-perimeter/

---------------------------------------------------
Approach: Grid Traversal
---------------------------------------------------
Idea:
- Each land cell contributes 4 edges.
- Subtract 2 for every adjacent land cell.

---------------------------------------------------
Time Complexity:
- O(m * n)

Space Complexity:
- O(1)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int perimeter = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    perimeter += 4;
                    if (i > 0 && grid[i - 1][j] == 1) perimeter -= 2;
                    if (j > 0 && grid[i][j - 1] == 1) perimeter -= 2;
                }
            }
        }
        return perimeter;
    }
};
