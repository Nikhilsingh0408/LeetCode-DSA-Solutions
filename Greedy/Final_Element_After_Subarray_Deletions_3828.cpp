/*
Problem Name : Final Element After Subarray Deletions
LeetCode ID  : 3828
Difficulty  : Medium
Category    : Game Theory / Greedy

---------------------------------------------------
Key Observation:
- In each turn, a proper subarray is removed.
- All middle elements can be eliminated by optimal play.
- The only candidates for the final element are:
    - first element
    - last element

Alice wants to maximize the result.
Bob wants to minimize it.
Optimal play leads to choosing the maximum of
the first and last elements.

---------------------------------------------------
Time Complexity:
- O(1)

Space Complexity:
- O(1)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums.front(), nums.back());
    }
};
