/*
Problem Name : Remove Element
LeetCode ID  : 27
Difficulty  : Easy
Link        : https://leetcode.com/problems/remove-element/

---------------------------------------------------
Problem Statement:
Given an integer array nums and an integer val, remove all
occurrences of val in-place. The order of the elements may
be changed.

Return the number of elements k in nums which are not equal
to val.

The first k elements of nums should contain the elements
that are not equal to val. The remaining elements are not
important.

---------------------------------------------------
Example 1:
Input  : nums = [3,2,2,3], val = 3
Output : k = 2, nums = [2,2,_ ,_]

Example 2:
Input  : nums = [0,1,2,2,3,0,4,2], val = 2
Output : k = 5, nums = [0,1,4,0,3,_,_,_]

---------------------------------------------------
Approach: Two Pointer / Overwrite Technique
---------------------------------------------------
Idea:
- Traverse the array.
- Use an index pointer to place elements that are NOT equal
  to the given value.
- Whenever nums[i] != val, copy it to nums[idx] and
  increment idx.

---------------------------------------------------
Time Complexity:
- O(n), where n is the size of the array

Space Complexity:
- O(1), in-place without extra space

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[idx] = nums[i];
                idx++;
            }
        }

        // idx represents the number of valid elements
        return idx;
    }
};
