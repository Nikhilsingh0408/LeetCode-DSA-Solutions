/*
Problem Name : Pascal's Triangle II
LeetCode ID  : 119
Difficulty  : Easy
Link        : https://leetcode.com/problems/pascals-triangle-ii/

---------------------------------------------------
Problem Statement:
Given an integer rowIndex, return the rowIndex-th (0-indexed)
row of Pascal's Triangle.

In Pascal's Triangle, each number is the sum of the two
numbers directly above it.

---------------------------------------------------
Example 1:
Input  : rowIndex = 3
Output : [1,3,3,1]

Example 2:
Input  : rowIndex = 0
Output : [1]

Example 3:
Input  : rowIndex = 1
Output : [1,1]

---------------------------------------------------
Approach: Mathematical Combination Formula (Optimal)
---------------------------------------------------
Idea:
- Each element in Pascal's Triangle row can be calculated
  using the binomial coefficient:
    C(n, k) = C(n, k-1) * (n - k + 1) / k
- Start with value = 1 (C(n, 0)).
- Iteratively compute the next values using the formula.
- This avoids building the entire triangle.

---------------------------------------------------
Time Complexity:
- O(rowIndex)

Space Complexity:
- O(rowIndex)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        long long value = 1;

        for (int k = 0; k <= rowIndex; k++) {
            row.push_back(value);
            value = value * (rowIndex - k) / (k + 1);
        }

        return row;
    }
};
