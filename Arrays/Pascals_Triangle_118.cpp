/*
Problem Name : Pascal's Triangle
LeetCode ID  : 118
Difficulty  : Easy
Link        : https://leetcode.com/problems/pascals-triangle/

---------------------------------------------------
Problem Statement:
Given an integer numRows, return the first numRows of
Pascal's Triangle.

In Pascal's Triangle:
- The first and last element of every row is 1
- Every other element is the sum of the two elements
  directly above it

---------------------------------------------------
Example 1:
Input  : numRows = 5
Output : [[1],
          [1,1],
          [1,2,1],
          [1,3,3,1],
          [1,4,6,4,1]]

Example 2:
Input  : numRows = 1
Output : [[1]]

---------------------------------------------------
Approach: Recursion (Top-Down Construction)
---------------------------------------------------
Idea:
- Start with the first row [1].
- For each next row:
  - First and last elements are always 1.
  - Middle elements are computed as:
    curr[i] = prev[i-1] + prev[i]
- Recursively build rows until numRows is reached.

---------------------------------------------------
Time Complexity:
- O(numRows²)

Space Complexity:
- O(numRows²) for storing the triangle
- O(numRows) recursion stack

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    // Recursive helper function
    void solve(int numRows, int currRow, vector<int> curr) {
        if (currRow == numRows) {
            return;
        }

        // Store current row
        result.push_back(curr);

        // Build next row
        vector<int> next(currRow + 2, 1);
        for (int i = 1; i <= currRow; i++) {
            next[i] = curr[i - 1] + curr[i];
        }

        // Recurse for next row
        solve(numRows, currRow + 1, next);
    }

    vector<vector<int>> generate(int numRows) {
        vector<int> firstRow = {1};
        solve(numRows, 0, firstRow);
        return result;
    }
};
