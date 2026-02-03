/*
Problem Name : Trionic Array I
LeetCode ID  : 3637
Difficulty  : Easy
Category    : Array / Greedy / Pattern Detection

---------------------------------------------------
Definition:
An array is trionic if it has:
1) Strictly increasing prefix
2) Strictly decreasing middle
3) Strictly increasing suffix

Indices:
0 < p < q < n - 1

---------------------------------------------------
Approach:
- Traverse array once using a pointer
- First consume strictly increasing part
- Then strictly decreasing part
- Then strictly increasing part again
- Validate all three segments exist

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
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int i = 1;

        // 1️⃣ strictly increasing
        while (i < n && nums[i] > nums[i - 1]) i++;
        if (i == 1 || i == n) return false;

        // 2️⃣ strictly decreasing
        while (i < n && nums[i] < nums[i - 1]) i++;
        if (i == n) return false;

        // 3️⃣ strictly increasing
        while (i < n && nums[i] > nums[i - 1]) i++;

        return i == n;
    }
};
