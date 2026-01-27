/*
Problem Name : Minimum Difference Between Highest and Lowest of K Scores
LeetCode ID  : 1984
Difficulty  : Easy
Category    : Arrays / Sorting / Sliding Window

---------------------------------------------------
Problem Statement:
You are given an integer array nums representing scores
and an integer k.

Pick scores of any k students such that the difference
between the highest and lowest score is minimized.

Return the minimum possible difference.

---------------------------------------------------
Key Observation:
- After sorting the array, the best group of k scores
  will always be a contiguous window of size k.
- Any non-contiguous selection would have a larger
  or equal range.

---------------------------------------------------
Approach: Sort + Sliding Window
---------------------------------------------------
Steps:
1. Sort the array in ascending order.
2. Slide a window of size k.
3. For each window [i ... i+k-1], compute:
       nums[i+k-1] - nums[i]
4. Take the minimum over all windows.

---------------------------------------------------
Edge Case:
- If k == 1, the difference is always 0.

---------------------------------------------------
Time Complexity:
- O(n log n) due to sorting

Space Complexity:
- O(1) extra (ignoring sort)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minDiff = INT_MAX;

        for (int i = 0; i + k - 1 < n; i++) {
            minDiff = min(minDiff, nums[i + k - 1] - nums[i]);
        }

        return minDiff;
    }
};
