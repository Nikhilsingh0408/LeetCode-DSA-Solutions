/*
Problem Name : Minimum Distance Between Three Equal Elements I
Difficulty  : Easy
Category    : Brute Force

---------------------------------------------------
Problem Statement:
You are given an integer array nums.

A tuple (i, j, k) of 3 distinct indices is good if:
    nums[i] == nums[j] == nums[k]

The distance of a good tuple is:
    |i - j| + |j - k| + |k - i|

Return the minimum possible distance of a good tuple.
If no such tuple exists, return -1.

---------------------------------------------------
Approach: Brute Force (Three Nested Loops)
---------------------------------------------------
Idea:
- Try all possible triplets (i, j, k) such that:
    0 ≤ i < j < k < n
- Check if nums[i] == nums[j] == nums[k].
- Compute distance and keep track of minimum.

---------------------------------------------------
Why Brute Force Works Here:
- Constraint n ≤ 100
- Total triplets ≈ O(n³) = 10⁶ (acceptable)

---------------------------------------------------
Time Complexity:
- O(n³)

Space Complexity:
- O(1)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MAX;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] == nums[j] && nums[j] == nums[k]) {
                        int dist = abs(i - j) + abs(j - k) + abs(k - i);
                        result = min(result, dist);
                    }
                }
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};
