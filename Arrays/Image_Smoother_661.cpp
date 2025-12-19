/*
Problem Name : Image Smoother
LeetCode ID  : 661
Difficulty  : Easy
Link        : https://leetcode.com/problems/image-smoother/

---------------------------------------------------
Approach: Matrix Traversal
---------------------------------------------------
Idea:
- For each cell, compute average of itself and all
  valid neighboring cells.

---------------------------------------------------
Time Complexity:
- O(m * n)

Space Complexity:
- O(1) (excluding output matrix)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> result(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0, cnt = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        int ni = i + x, nj = j + y;
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                            sum += img[ni][nj];
                            cnt++;
                        }
                    }
                }
                result[i][j] = sum / cnt;
            }
        }
        return result;
    }
};
