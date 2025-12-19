/*
Problem Name : Squares of a Sorted Array
LeetCode ID  : 977
Difficulty  : Easy
Link        : https://leetcode.com/problems/squares-of-a-sorted-array/

---------------------------------------------------
Approach: Two Pointers
---------------------------------------------------
Idea:
- Largest square comes from either end of array.
- Fill result from back using two pointers.

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
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int l = 0, r = n - 1, idx = n - 1;
        while (l <= r) {
            if (abs(nums[l]) > abs(nums[r])) {
                result[idx--] = nums[l] * nums[l];
                l++;
            } else {
                result[idx--] = nums[r] * nums[r];
                r--;
            }
        }
        return result;
    }
};
