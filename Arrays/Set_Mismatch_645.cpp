/*
Problem Name : Set Mismatch
LeetCode ID  : 645
Difficulty  : Easy
Link        : https://leetcode.com/problems/set-mismatch/

---------------------------------------------------
Approach: Frequency Array
---------------------------------------------------
Idea:
- Count occurrences of numbers from 1 to n.
- Number with freq = 2 is duplicated.
- Number with freq = 0 is missing.

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
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);

        for (int num : nums) freq[num]++;

        int duplicate = -1, missing = -1;
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2) duplicate = i;
            if (freq[i] == 0) missing = i;
        }

        return {duplicate, missing};
    }
};
