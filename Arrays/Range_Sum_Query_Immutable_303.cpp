/*
Problem Name : Range Sum Query - Immutable
LeetCode ID  : 303
Difficulty  : Easy
Link        : https://leetcode.com/problems/range-sum-query-immutable/

---------------------------------------------------
Problem Statement:
Given an integer array nums, handle multiple queries
of the following type:
- Calculate the sum of the elements of nums between
  indices left and right inclusive.

---------------------------------------------------
Example:
Input:
nums = [-2,0,3,-5,2,-1]
sumRange(0,2) -> 1
sumRange(2,5) -> -1
sumRange(0,5) -> -3

---------------------------------------------------
Approach: Prefix Sum
---------------------------------------------------
Idea:
- Precompute prefix sum array.
- prefix[i] stores sum of elements from index 0 to i.
- Range sum can be calculated in O(1) using:
    prefix[right] - prefix[left - 1]

---------------------------------------------------
Time Complexity:
- Preprocessing: O(n)
- Each query: O(1)

Space Complexity:
- O(n)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class NumArray {
private:
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) return prefix[right];
        return prefix[right] - prefix[left - 1];
    }
};
