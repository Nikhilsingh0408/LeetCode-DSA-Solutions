/*
Problem Name : Contains Duplicate II
LeetCode ID  : 219
Difficulty  : Easy
Link        : https://leetcode.com/problems/contains-duplicate-ii/

---------------------------------------------------
Problem Statement:
Given an integer array nums and an integer k, return true
if there exist two distinct indices i and j such that:
- nums[i] == nums[j]
- abs(i - j) <= k

---------------------------------------------------
Example 1:
Input  : nums = [1,2,3,1], k = 3
Output : true

Example 2:
Input  : nums = [1,0,1,1], k = 1
Output : true

Example 3:
Input  : nums = [1,2,3,1,2,3], k = 2
Output : false

---------------------------------------------------
Approach: Sliding Window + Hash Set (Optimal)
---------------------------------------------------
Idea:
- Maintain a sliding window of size at most k.
- Use a hash set to store elements within the window.
- If the current element already exists in the set,
  a valid duplicate is found.
- Remove elements that fall outside the window.

---------------------------------------------------
Time Complexity:
- O(n)

Space Complexity:
- O(k)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) return false;

        unordered_set<int> st;
        int n = nums.size();
        int i = 0;

        for (int j = 0; j < n; j++) {

            // Ensure window size does not exceed k
            while (j - i > k) {
                st.erase(nums[i]);
                i++;
            }

            // Check for duplicate in window
            if (st.count(nums[j])) {
                return true;
            }

            st.insert(nums[j]);
        }

        return false;
    }
};
