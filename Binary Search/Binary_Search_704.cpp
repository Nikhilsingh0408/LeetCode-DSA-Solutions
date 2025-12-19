/*
Problem Name : Binary Search
LeetCode ID  : 704
Difficulty  : Easy
Link        : https://leetcode.com/problems/binary-search/

---------------------------------------------------
Problem Statement:
Given a sorted array of integers and a target value,
return the index if the target is found. Otherwise, return -1.

---------------------------------------------------
Approach: Iterative Binary Search
---------------------------------------------------
Idea:
- Use two pointers (left and right).
- Repeatedly narrow down the search space.

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
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};
