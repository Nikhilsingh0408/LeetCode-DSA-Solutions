/*
Problem Name : Mirror Distance of an Integer
LeetCode ID  : 3783
Difficulty  : Easy
Category    : Math / Number Manipulation

---------------------------------------------------
Problem Statement:
You are given an integer n.

Define mirror distance as:
    |n - reverse(n)|

Where reverse(n) is the integer formed by reversing
the digits of n.

Return the mirror distance.

---------------------------------------------------
Approach: Digit Reversal
---------------------------------------------------
Idea:
- Reverse the digits of the number using modulo and division.
- Compute absolute difference between original and reversed number.

---------------------------------------------------
Edge Cases:
- Single-digit numbers → distance = 0
- Leading zeros in reverse are automatically ignored

---------------------------------------------------
Time Complexity:
- O(d), where d is number of digits in n

Space Complexity:
- O(1)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        int x = n;
        int rev = 0;

        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }

        return abs(n - rev);
    }
};
