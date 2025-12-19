/*
Problem Name : 1-bit and 2-bit Characters
LeetCode ID  : 717
Difficulty  : Easy
Link        : https://leetcode.com/problems/1-bit-and-2-bit-characters/

---------------------------------------------------
Approach: Greedy Traversal
---------------------------------------------------
Idea:
- Traverse bits from left to right.
- If current bit is 1, skip next bit.
- Check if last character is 1-bit.

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
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        while (i < bits.size() - 1) {
            if (bits[i] == 1) i += 2;
            else i += 1;
        }
        return i == bits.size() - 1;
    }
};
