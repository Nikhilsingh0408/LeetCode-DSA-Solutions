/*
Problem Name : Remove Duplicates from Sorted Array
LeetCode ID  : 26
Difficulty  : Easy
Link        : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

---------------------------------------------------
Problem Statement:
Given an integer array nums sorted in non-decreasing order,
remove the duplicates in-place such that each unique element
appears only once.

The relative order of the elements should be kept the same.
Return the number of unique elements k.

The first k elements of nums should contain the unique
elements in sorted order.

---------------------------------------------------
Example 1:
Input  : nums = [1,1,2]
Output : k = 2, nums = [1,2,_]

Example 2:
Input  : nums = [0,0,1,1,1,2,2,3,3,4]
Output : k = 5, nums = [0,1,2,3,4,_,_,_,_,_]

---------------------------------------------------
Approach: Two Pointer Technique
---------------------------------------------------
Idea:
- Since the array is already sorted, duplicates will be adjacent.
- Use two pointers:
  - i → scans the array
  - j → tracks the position of the next unique element
- When nums[i] is different from nums[i-1], it is a new unique
  element, so place it at nums[j] and increment j.

---------------------------------------------------
Time Complexity:
- O(n), where n is the size of the array

Space Complexity:
- O(1), in-place modification without extra space

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Pointer for placing unique elements
        int j = 1;

        // Traverse from the second element
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[j] = nums[i];
                j++;
            }
        }

        // j represents the count of unique elements
        return j;
    }
};
