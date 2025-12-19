/*
Problem Name : Find Pivot Index
LeetCode ID  : 724
Difficulty  : Easy
Link        : https://leetcode.com/problems/find-pivot-index/

---------------------------------------------------
Approach: Prefix Sum
---------------------------------------------------
Idea:
- Calculate total sum.
- Maintain left sum while traversing.
- Pivot index satisfies:
  leftSum == totalSum - leftSum - nums[i]

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
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == total - leftSum - nums[i]) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};
