/*
Problem Name : Longest Harmonious Subsequence
LeetCode ID  : 594
Difficulty  : Easy
Link        : https://leetcode.com/problems/longest-harmonious-subsequence/

---------------------------------------------------
Problem Statement:
A harmonious subsequence is a subsequence where the
difference between its maximum and minimum values is
exactly 1. Return the length of the longest such subsequence.

---------------------------------------------------
Approach: Hash Map (Frequency Count)
---------------------------------------------------
Idea:
- Count frequency of each number.
- For every number x, if (x + 1) exists,
  update answer with freq[x] + freq[x + 1].

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
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;

        int ans = 0;
        for (auto &it : freq) {
            if (freq.count(it.first + 1)) {
                ans = max(ans, it.second + freq[it.first + 1]);
            }
        }
        return ans;
    }
};
