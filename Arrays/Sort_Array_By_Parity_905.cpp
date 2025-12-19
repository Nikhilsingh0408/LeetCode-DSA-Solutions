/*
Problem Name : Sort Array By Parity
LeetCode ID  : 905
Difficulty  : Easy
Link        : https://leetcode.com/problems/sort-array-by-parity/

---------------------------------------------------
Approach: Two Pointers
---------------------------------------------------
Idea:
- Place even elements at the beginning and odd elements at the end.
- Swap when needed.

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
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            if (nums[l] % 2 > nums[r] % 2) {
                swap(nums[l], nums[r]);
            }
            if (nums[l] % 2 == 0) l++;
            if (nums[r] % 2 == 1) r--;
        }
        return nums;
    }
};
