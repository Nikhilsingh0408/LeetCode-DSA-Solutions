/*
Problem Name : Minimize Maximum Pair Sum in Array
LeetCode ID  : 1877
Difficulty  : Medium
Category    : Greedy / Two Pointers / Sorting

---------------------------------------------------
Problem Statement:
You are given an array nums of even length n.
Pair up all elements such that:
- Each element is used exactly once
- The maximum pair sum is minimized

Return the minimized maximum pair sum.

---------------------------------------------------
Key Observation:
To minimize the maximum pair sum:
- Pair the smallest element with the largest element.
- Pair the second smallest with the second largest, and so on.

This balances large values with small ones and prevents
any single pair from having an excessively large sum.

---------------------------------------------------
Approach: Sort + Two Pointers
---------------------------------------------------
Steps:
1. Sort the array in ascending order.
2. Use two pointers:
   - i from start (smallest)
   - j from end (largest)
3. For each pair (nums[i], nums[j]):
   - Compute pair sum
   - Track the maximum among these sums
4. Return that maximum.

---------------------------------------------------
Why This Works (Greedy Proof Intuition):
- Any alternative pairing that pairs large numbers together
  would only increase the maximum pair sum.
- This strategy minimizes the worst-case pair.

---------------------------------------------------
Time Complexity:
- O(n log n) due to sorting

Space Complexity:
- O(1) extra (ignoring sort)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i = 0, j = nums.size() - 1;
        int answer = INT_MIN;

        while (i < j) {
            answer = max(answer, nums[i] + nums[j]);
            i++;
            j--;
        }

        return answer;
    }
};
