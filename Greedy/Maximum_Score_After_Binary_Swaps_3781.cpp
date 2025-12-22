/*
Problem Name : Maximum Score After Binary Swaps
LeetCode ID  : 3781
Difficulty  : Medium
Category    : Greedy + Priority Queue

---------------------------------------------------
Problem Statement:
You are given an integer array nums and a binary string s.
Each index i where s[i] = '1' contributes nums[i] to the score.

You may swap adjacent characters "01" -> "10" any number
of times.

Return the maximum possible score achievable.

---------------------------------------------------
Key Insight:
- A '1' can move LEFT across any number of '0's.
- So each '1' can choose the best possible position among
  all indices ≤ its original index.
- We want to assign the largest available nums value
  to each '1' as early as possible.

---------------------------------------------------
Approach: Greedy + Max Heap
---------------------------------------------------
Idea:
- Traverse left to right.
- Keep a max heap of all nums[i] seen so far.
- Whenever we encounter s[i] == '1':
  - Assign the largest available nums value from the heap.
  - Add it to the score and remove it from the heap.

Why it works:
- Swaps allow reordering where '1's pick the best possible
  values before them.
- Greedy assignment is optimal.

---------------------------------------------------
Time Complexity:
- O(n log n)

Space Complexity:
- O(n)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n = nums.size();
        priority_queue<long long> pq;
        long long score = 0;

        for (int i = 0; i < n; i++) {
            pq.push(nums[i]);

            if (s[i] == '1') {
                score += pq.top();
                pq.pop();
            }
        }

        return score;
    }
};
