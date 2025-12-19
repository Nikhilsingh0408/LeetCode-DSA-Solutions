/*
Problem Name : Binary Prefix Divisible By 5
LeetCode ID  : 1018
Difficulty  : Easy
Link        : https://leetcode.com/problems/binary-prefix-divisible-by-5/

---------------------------------------------------
Approach: Modulo Simulation
---------------------------------------------------
Idea:
- Keep current value modulo 5.
- Append bit: curr = (curr * 2 + bit) % 5
- Check if curr == 0.

---------------------------------------------------
Time Complexity:
- O(n)

Space Complexity:
- O(1)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int curr = 0;

        for (int bit : nums) {
            curr = (curr * 2 + bit) % 5;
            result.push_back(curr == 0);
        }
        return result;
    }
};
