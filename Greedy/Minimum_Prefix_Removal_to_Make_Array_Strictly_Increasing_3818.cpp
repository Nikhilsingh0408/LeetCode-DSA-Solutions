/*
Problem Name : Minimum Prefix Removal to Make Array Strictly Increasing
LeetCode ID  : 3818
Difficulty  : Medium
Category    : Arrays / Greedy

---------------------------------------------------
Problem Statement:
You are given an integer array nums.

You must remove exactly one prefix (possibly empty)
such that the remaining array is strictly increasing.

Return the minimum length of the removed prefix.

---------------------------------------------------
Key Observation:
- We only remove a PREFIX.
- So the remaining array must be a SUFFIX that is
  strictly increasing.

---------------------------------------------------
Approach: Scan from Right
---------------------------------------------------
Idea:
- Find the longest suffix that is already strictly increasing.
- The prefix before this suffix is the minimum prefix to remove.

Steps:
1. Traverse from right to left.
2. Count how long the suffix remains strictly increasing.
3. The answer is:
      prefixLength = n - suffixLength

---------------------------------------------------
Edge Cases:
- Single element → already strictly increasing → 0
- Entire array strictly increasing → 0

---------------------------------------------------
Time Complexity:
- O(n)

Space Complexity:
- O(1)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int suffixLen = 1;

        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                suffixLen++;
            } else {
                break;
            }
        }

        return n - suffixLen;
    }
};
