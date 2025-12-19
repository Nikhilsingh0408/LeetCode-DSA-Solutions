/*
Problem Name : Missing Number
LeetCode ID  : 268
Difficulty  : Easy
Link        : https://leetcode.com/problems/missing-number/

---------------------------------------------------
Problem Statement:
Given an array nums containing n distinct numbers in the
range [0, n], return the only number in the range that is
missing from the array.

---------------------------------------------------
Example 1:
Input  : nums = [3,0,1]
Output : 2

Example 2:
Input  : nums = [0,1]
Output : 2

Example 3:
Input  : nums = [9,6,4,2,3,5,7,0,1]
Output : 8

---------------------------------------------------
Approach 1: Sorting
---------------------------------------------------
Idea:
- Sort the array.
- Traverse and check if nums[i] != i.
- The first mismatch index is the missing number.
- If no mismatch found, missing number is n.

---------------------------------------------------
Time Complexity:
- O(n log n)

Space Complexity:
- O(1)

---------------------------------------------------
Approach 2: XOR (Optimal – Follow-up)
---------------------------------------------------
Idea:
- XOR all numbers from 0 to n.
- XOR all elements of the array.
- XOR of both results gives the missing number.

Why XOR works:
- a ^ a = 0
- a ^ 0 = a

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

    // -------------------------------
    // Approach 1: Sorting
    // -------------------------------
    int missingNumberSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return nums.size();
    }

    // -------------------------------
    // Approach 2: XOR (Optimal)
    // -------------------------------
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorAll = 0;

        // XOR all numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            xorAll ^= i;
        }

        // XOR all elements of nums
        for (int num : nums) {
            xorAll ^= num;
        }

        return xorAll;
    }
};
