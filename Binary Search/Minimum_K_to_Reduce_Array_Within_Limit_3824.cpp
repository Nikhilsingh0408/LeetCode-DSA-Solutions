/*
Problem Name : Minimum K to Reduce Array Within Limit
LeetCode ID  : 3824
Difficulty  : Medium
Category    : Binary Search / Math

---------------------------------------------------
Idea:
For a given k:
- Each nums[i] needs ceil(nums[i] / k) operations
- Total operations must be <= k^2

Binary search the minimum k satisfying this condition.

---------------------------------------------------
Time Complexity:
- O(n log max(nums))

Space Complexity:
- O(1)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReduce(long long k, vector<int>& nums) {
        long long ops = 0;
        for (int x : nums) {
            ops += (x + k - 1) / k;  // ceil(x / k)
            if (ops > k * k) return false; // early stop
        }
        return ops <= k * k;
    }

    int minimumK(vector<int>& nums) {
        int lo = 1, hi = 100000;
        int ans = hi;

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;

            if (canReduce(mid, nums)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
