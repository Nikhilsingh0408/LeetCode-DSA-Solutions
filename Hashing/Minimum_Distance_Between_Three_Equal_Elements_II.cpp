/*
Problem Name : Minimum Distance Between Three Equal Elements II
Difficulty  : Medium
Category    : Hashing / Sliding Window on Indices

---------------------------------------------------
Problem Statement:
You are given an integer array nums.

A tuple (i, j, k) of 3 distinct indices is good if:
    nums[i] == nums[j] == nums[k]

The distance of a good tuple is:
    |i - j| + |j - k| + |k - i|

Return the minimum possible distance among all good tuples.
If no such tuple exists, return -1.

---------------------------------------------------
Key Observation:
For indices x < y < z:
    |x - y| + |y - z| + |z - x|
  = (y - x) + (z - y) + (z - x)
  = 2 * (z - x)

So to minimize distance, we should minimize (z - x),
i.e., choose three **closest occurrences** of the same value.

---------------------------------------------------
Approach: Hash Map + Sliding Window of Size 3
---------------------------------------------------
Idea:
- Store indices for each value as we iterate.
- Whenever a value appears at least 3 times,
  compute distance using the last 3 indices only.
- Keep updating the minimum answer.

---------------------------------------------------
Why Only Last 3 Indices?
- Using older indices only increases (z - x),
  hence increases the distance.
- So checking consecutive triples is optimal.

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
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int result = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);

            int m = mp[nums[i]].size();
            if (m >= 3) {
                int x = mp[nums[i]][m - 3];
                int y = mp[nums[i]][m - 2];
                int z = mp[nums[i]][m - 1];

                int dist = abs(x - y) + abs(y - z) + abs(z - x);
                result = min(result, dist);
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};
