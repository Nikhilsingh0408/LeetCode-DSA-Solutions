/*
Problem Name : Maximize Sum Of Array After K Negations
LeetCode ID  : 1005
Difficulty  : Easy
Link        : https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

---------------------------------------------------
Approach: Greedy + Sorting
---------------------------------------------------
Idea:
- Sort array.
- Flip negative numbers first.
- If k remains odd, flip smallest element.

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
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() && k > 0 && nums[i] < 0; i++, k--) {
            nums[i] = -nums[i];
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (k % 2 == 1) {
            int mn = *min_element(nums.begin(), nums.end());
            sum -= 2 * mn;
        }

        return sum;
    }
};
