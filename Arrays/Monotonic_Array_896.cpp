/*
Problem Name : Monotonic Array
LeetCode ID  : 896
Difficulty  : Easy
Link        : https://leetcode.com/problems/monotonic-array/

---------------------------------------------------
Approach: Single Pass Check
---------------------------------------------------
Idea:
- Track whether the array can be non-decreasing or non-increasing.
- If both fail, array is not monotonic.

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
    bool isMonotonic(vector<int>& nums) {
        bool inc = true, dec = true;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) inc = false;
            if (nums[i] > nums[i - 1]) dec = false;
        }

        return inc || dec;
    }
};
