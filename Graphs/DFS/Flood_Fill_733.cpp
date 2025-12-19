/*
Problem Name : Flood Fill
LeetCode ID  : 733
Difficulty  : Easy
Link        : https://leetcode.com/problems/flood-fill/

---------------------------------------------------
Approach: DFS
---------------------------------------------------
Idea:
- Start from (sr, sc) and replace connected pixels
  having the same original color.
- Use DFS in 4 directions.

---------------------------------------------------
Time Complexity:
- O(m * n)

Space Complexity:
- O(m * n) (recursion stack)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int color, int newColor) {
        int m = image.size(), n = image[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n || image[r][c] != color)
            return;

        image[r][c] = newColor;
        dfs(image, r + 1, c, color, newColor);
        dfs(image, r - 1, c, color, newColor);
        dfs(image, r, c + 1, color, newColor);
        dfs(image, r, c - 1, color, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};
