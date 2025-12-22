/*
Problem Name : Minimum Number of Operations to Have Distinct Elements
LeetCode ID  : 3779
Difficulty  : Medium
Category    : Greedy / Hashing

---------------------------------------------------
Problem Statement:
You are given an integer array nums.

In one operation:
- Remove the first three elements of the array.
- If fewer than three elements remain, remove all.

Repeat until:
- The array becomes empty, OR
- The remaining elements are all distinct.

Return the number of operations required.

---------------------------------------------------
Key Observation:
- Only duplicates matter.
- Removing elements from the front gradually reduces
  frequencies.
- Once all duplicates are resolved, we stop immediately.

---------------------------------------------------
Approach: Frequency Count + Greedy Simulation
---------------------------------------------------
Steps:
1. Count frequency of all elements.
2. Track how many values currently have frequency > 1
   (called `dupli`).
3. If `dupli == 0`, no operation is needed.
4. Otherwise:
   - Repeatedly remove up to 3 elements from the front.
   - Update frequencies and reduce `dupli` when a value
     becomes unique.
   - Stop as soon as `dupli == 0`.

---------------------------------------------------
Why This Works:
- The operation order is fixed (always first 3 elements).
- We simulate exactly what the problem describes.
- Early stopping ensures efficiency.

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
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for (int x : nums) freq[x]++;

        int dupli = 0;
        for (auto &p : freq) {
            if (p.second > 1) dupli++;
        }

        // Already distinct
        if (dupli == 0) return 0;

        int ops = 0;
        int i = 0;

        while (i < n) {
            ops++;

            // Remove up to 3 elements
            for (int k = 0; k < 3 && i < n; k++, i++) {
                freq[nums[i]]--;
                if (freq[nums[i]] == 1) {
                    dupli--; // duplicate resolved
                }
            }

            if (dupli == 0) return ops;
        }

        return ops;
    }
};
