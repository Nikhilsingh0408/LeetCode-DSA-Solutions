/*
Problem Name : Rotate Non-Negative Elements
LeetCode ID  : 3819
Difficulty  : Medium
Category    : Arrays / Simulation

---------------------------------------------------
Problem Statement:
You are given an integer array nums and an integer k.

Rotate only the non-negative elements (>= 0) to the
LEFT by k positions in a cyclic manner.

- Negative elements must stay in their original indices.
- After rotation, non-negative elements are placed back
  only into positions that originally contained
  non-negative values.

---------------------------------------------------
Approach: Extract → Rotate → Reinsert
---------------------------------------------------
Steps:
1. Extract all non-negative elements in order.
2. Perform a left rotation on this extracted list.
3. Traverse the original array and:
   - Replace non-negative positions with rotated values
   - Keep negative values unchanged

---------------------------------------------------
Key Observations:
- Negative indices are "blocked" and cannot move.
- Only relative order of non-negative elements changes.
- k can be large, so we reduce it using modulo.

---------------------------------------------------
Edge Cases:
- No non-negative elements → return array as-is
- Only one non-negative element → rotation has no effect

---------------------------------------------------
Time Complexity:
- O(n)

Space Complexity:
- O(n)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: Collect non-negative elements
        vector<int> nonNeg;
        for (int x : nums) {
            if (x >= 0) nonNeg.push_back(x);
        }

        int m = nonNeg.size();
        if (m == 0) return nums; // nothing to rotate

        k %= m;

        // Step 2: Left rotate non-negative elements
        vector<int> rotated(m);
        for (int i = 0; i < m; i++) {
            rotated[i] = nonNeg[(i + k) % m];
        }

        // Step 3: Place them back into original array
        vector<int> result(n);
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                result[i] = rotated[idx++];
            } else {
                result[i] = nums[i];
            }
        }

        return result;
    }
};
