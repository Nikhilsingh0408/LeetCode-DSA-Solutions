/*
Problem Name : Find the Town Judge
LeetCode ID  : 997
Difficulty  : Easy
Link        : https://leetcode.com/problems/find-the-town-judge/

---------------------------------------------------
Approach: In-degree / Out-degree Counting
---------------------------------------------------
Idea:
- Town judge trusts nobody → outDegree = 0
- Everyone else trusts the judge → inDegree = n - 1

---------------------------------------------------
Time Complexity:
- O(n + trust.size())

Space Complexity:
- O(n)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n + 1, 0), out(n + 1, 0);

        for (auto &t : trust) {
            out[t[0]]++;
            in[t[1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (in[i] == n - 1 && out[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
