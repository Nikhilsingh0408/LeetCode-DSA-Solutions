/*
Problem Name : Delete Columns to Make Sorted II
LeetCode ID  : 955
Difficulty  : Medium
Category    : Greedy / String Processing

---------------------------------------------------
Problem Statement:
You are given an array of strings of equal length.
You may delete entire columns so that the resulting
array of strings is lexicographically sorted.

Return the minimum number of columns to delete.

---------------------------------------------------
Key Idea:
- We compare rows top to bottom.
- Once a pair of rows is confirmed sorted,
  we no longer need to compare that pair again.
- If a column causes a violation for any unresolved
  adjacent pair, that column must be deleted.

---------------------------------------------------
Approach: Greedy with State Tracking
---------------------------------------------------
Maintain:
- A boolean array `sorted[i]`:
  sorted[i] = true means strs[i] < strs[i+1]
  is already confirmed by earlier columns.

For each column:
1. Check if this column causes a violation
   for any unresolved pair.
2. If yes → delete this column.
3. Otherwise → update sorted pairs.

---------------------------------------------------
Why This Works:
- Greedy choice: delete a column immediately
  if it breaks lexicographic order.
- Once a pair is sorted, future columns
  cannot break it.

---------------------------------------------------
Time Complexity:
- O(n * m)

Space Complexity:
- O(n)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int deletions = 0;

        // sorted[i] = true means strs[i] < strs[i+1] already confirmed
        vector<bool> sorted(n - 1, false);

        for (int col = 0; col < m; col++) {
            bool bad = false;

            // Check if this column breaks lexicographic order
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][col] > strs[i + 1][col]) {
                    bad = true;
                    break;
                }
            }

            // If bad, delete this column
            if (bad) {
                deletions++;
                continue;
            }

            // Otherwise, update sorted pairs
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][col] < strs[i + 1][col]) {
                    sorted[i] = true;
                }
            }
        }

        return deletions;
    }
};
