/*
Problem Name : Two Sum
LeetCode ID  : 1
Difficulty  : Easy
Link        : https://leetcode.com/problems/two-sum/

---------------------------------------------------
Problem Statement:
Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up
to target.

You may assume that each input would have exactly one solution,
and you may not use the same element twice.

---------------------------------------------------
Approach 1: Brute Force
---------------------------------------------------
Idea:
- Try all possible pairs using two nested loops.
- If nums[i] + nums[j] == target, return their indices.

Time Complexity:
- O(n²)

Space Complexity:
- O(1)

---------------------------------------------------
Approach 2: Optimized using Hash Map
---------------------------------------------------
Idea:
- Use an unordered_map to store the value and its index.
- For each element, check if (target - current element) exists.
- If found, return indices immediately.

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

    // -------------------------------
    // Approach 1: Brute Force
    // -------------------------------
    vector<int> twoSumBruteForce(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }

    // -------------------------------
    // Approach 2: Hash Map (Optimized)
    // -------------------------------
    vector<int> twoSumOptimized(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int required = target - nums[i];

            // Check if the required number already exists
            if (mp.find(required) != mp.end()) {
                return {mp[required], i};
            }

            // Store current number with its index
            mp[nums[i]] = i;
        }

        return {};
    }
};
