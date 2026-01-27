/*
Problem Name : Construct the Minimum Bitwise Array II
LeetCode ID  : 3315
Difficulty  : Medium
Category    : Bit Manipulation / Greedy

---------------------------------------------------
Problem Statement:
You are given an array nums consisting of prime integers.

For each index i, find the minimum integer ans[i] such that:
    ans[i] OR (ans[i] + 1) == nums[i]

If no such value exists, set ans[i] = -1.

---------------------------------------------------
Key Observations:
1. For any integer x:
      x OR (x + 1)
   turns all bits from the least significant 0-bit onward to 1.

2. Therefore:
   nums[i] must be representable as:
      some number with exactly one 0-bit flipped to 1
      when adding 1.

3. To minimize ans[i]:
   - Try unsetting one set bit (1 → 0)
   - Check if OR with next number restores nums[i]

---------------------------------------------------
Approach:
For each nums[i]:
1. Iterate over all set bits in nums[i]
2. Try candidate:
      candidate = nums[i] with one set bit cleared
3. Check:
      candidate OR (candidate + 1) == nums[i]
4. Track the minimum valid candidate
5. If none valid → return -1

---------------------------------------------------
Why Prime Constraint Helps:
- Prime numbers have limited bit patterns
- This guarantees small search space (≤ 31 bits)

---------------------------------------------------
Time Complexity:
- O(n * 31) ≈ O(n)

Space Complexity:
- O(1) extra

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int best = INT_MAX;
            bool found = false;

            for (int bit = 0; bit <= 30; bit++) {
                if ((num >> bit) & 1) {
                    int candidate = num & ~(1 << bit);
                    if ((candidate | (candidate + 1)) == num) {
                        best = min(best, candidate);
                        found = true;
                    }
                }
            }

            ans[i] = found ? best : -1;
        }

        return ans;
    }
};
