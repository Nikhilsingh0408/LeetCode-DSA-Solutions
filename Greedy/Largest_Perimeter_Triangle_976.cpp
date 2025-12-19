/*
Problem Name : Largest Perimeter Triangle
LeetCode ID  : 976
Difficulty  : Easy
Link        : https://leetcode.com/problems/largest-perimeter-triangle/

---------------------------------------------------
Approach: Sorting + Greedy
---------------------------------------------------
Idea:
- Sort array in descending order.
- For any triplet (a, b, c):
  if b + c > a, triangle is valid.

---------------------------------------------------
Time Complexity:
- O(n log n)

Space Complexity:
- O(1)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = nums.size() - 1; i >= 2; i--) {
            if (nums[i - 1] + nums[i - 2] > nums[i]) {
                return nums[i] + nums[i - 1] + nums[i - 2];
            }
        }
        return 0;
    }
};
