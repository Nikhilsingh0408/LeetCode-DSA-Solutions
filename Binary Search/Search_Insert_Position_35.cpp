/*
Problem Name : Search Insert Position
LeetCode ID  : 35
Difficulty  : Easy
Link        : https://leetcode.com/problems/search-insert-position/

---------------------------------------------------
Problem Statement:
Given a sorted array of distinct integers and a target value,
return the index if the target is found.

If not found, return the index where it would be inserted
to maintain the sorted order.

You must write an algorithm with O(log n) runtime complexity.

---------------------------------------------------
Example 1:
Input  : nums = [1,3,5,6], target = 5
Output : 2

Example 2:
Input  : nums = [1,3,5,6], target = 2
Output : 1

Example 3:
Input  : nums = [1,3,5,6], target = 7
Output : 4

---------------------------------------------------
Approach: Binary Search
---------------------------------------------------
Idea:
- Since the array is sorted, binary search can be applied.
- If the target is found, return its index.
- If not found, the left pointer will indicate the correct
  insertion position after the loop ends.

---------------------------------------------------
Time Complexity:
- O(log n)

Space Complexity:
- O(1)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } 
            else if (nums[mid] < target) {
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }

        // left is the correct insertion position
        return left;
    }
};
