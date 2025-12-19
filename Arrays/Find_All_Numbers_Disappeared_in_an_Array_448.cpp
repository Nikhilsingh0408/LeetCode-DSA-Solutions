/*
Problem Name : Find All Numbers Disappeared in an Array
LeetCode ID  : 448
Difficulty  : Easy
Link        : https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

---------------------------------------------------
Problem Statement:
Given an array nums of length n where nums[i] is in the
range [1, n], return an array of all the integers in the
range [1, n] that do not appear in nums.

---------------------------------------------------
Example 1:
Input  : nums = [4,3,2,7,8,2,3,1]
Output : [5,6]

Example 2:
Input  : nums = [1,1]
Output : [2]

---------------------------------------------------
Approach: In-Place Index Marking (Optimal)
---------------------------------------------------
Idea:
- Since values are in range [1, n], each value maps to an index.
- For each number x, mark the element at index |x| - 1 as negative.
- After marking, indices with positive values correspond to
  missing numbers.

---------------------------------------------------
Time Complexity:
- O(n)

Space Complexity:
- O(1) extra space (excluding output array)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        // Mark visited indices
        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }

        // Collect missing numbers
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};
