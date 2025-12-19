/*
Problem Name : Contains Duplicate
LeetCode ID  : 217
Difficulty  : Easy
Link        : https://leetcode.com/problems/contains-duplicate/

---------------------------------------------------
Problem Statement:
Given an integer array nums, return true if any value
appears at least twice in the array, and return false
if every element is distinct.

---------------------------------------------------
Example 1:
Input  : nums = [1,2,3,1]
Output : true

Example 2:
Input  : nums = [1,2,3,4]
Output : false

Example 3:
Input  : nums = [1,1,1,3,3,4,3,2,4,2]
Output : true

---------------------------------------------------
Approach 1: Sorting
---------------------------------------------------
Idea:
- Sort the array.
- If any two adjacent elements are equal,
  a duplicate exists.

---------------------------------------------------
Time Complexity:
- O(n log n)

Space Complexity:
- O(1) (ignoring sort's internal stack)

---------------------------------------------------
Approach 2: Hash Set (Optimal Time)
---------------------------------------------------
Idea:
- Use an unordered_set to track seen elements.
- If an element is already present, return true.

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

    // -------------------------------
    // Approach 1: Sorting
    // -------------------------------
    bool containsDuplicateSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }

    // -------------------------------
    // Approach 2: Hash Set (Optimal)
    // -------------------------------
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for (int num : nums) {
            if (st.count(num)) {
                return true;
            }
            st.insert(num);
        }

        return false;
    }
};
