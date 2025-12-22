/*
Problem Name : Maximum Sum of Three Numbers Divisible by Three
LeetCode ID  : 3780
Difficulty  : Medium
Category    : Greedy / Math Optimization

---------------------------------------------------
Problem Statement:
You are given an integer array nums.

Choose exactly three integers such that their sum
is divisible by 3. Return the maximum possible sum.
If no such triplet exists, return 0.

---------------------------------------------------
Key Observation:
- We want the maximum sum → prefer larger numbers.
- Only the sum modulo 3 matters.
- Checking all O(n³) triplets is impossible for n up to 10⁵.

---------------------------------------------------
Optimization Insight:
After sorting in descending order, we only need to
check the top few elements.

Why?
- Modulo 3 has only 3 states (0, 1, 2).
- Any optimal triplet will come from the largest
  numbers.
- Checking the top 9 elements guarantees all modulo
  combinations for triplets.

---------------------------------------------------
Approach: Sort + Limited Brute Force
---------------------------------------------------
Steps:
1. Sort the array in descending order.
2. Check all triplets among the top 9 elements.
3. Keep the maximum sum divisible by 3.

---------------------------------------------------
Time Complexity:
- Sorting: O(n log n)
- Triplet check: O(1) (9³ = constant)

Space Complexity:
- O(1) (ignoring sort)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());

        int ans = 0;
        int limit = min(n, 9);

        for (int i = 0; i < limit; i++) {
            for (int j = i + 1; j < limit; j++) {
                for (int k = j + 1; k < limit; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum % 3 == 0) {
                        ans = max(ans, sum);
                    }
                }
            }
        }

        return ans;
    }
};
