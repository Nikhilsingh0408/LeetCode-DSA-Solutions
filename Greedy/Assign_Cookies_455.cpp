/*
Problem Name : Assign Cookies
LeetCode ID  : 455
Difficulty  : Easy
Link        : https://leetcode.com/problems/assign-cookies/

---------------------------------------------------
Problem Statement:
Each child has a greed factor, and each cookie has a size.
Assign cookies such that the maximum number of children
are content. A child is content if cookie size >= greed.

---------------------------------------------------
Approach: Greedy + Sorting
---------------------------------------------------
Idea:
- Sort both greed and cookie arrays.
- Use two pointers to assign smallest possible cookie
  to each child.

---------------------------------------------------
Time Complexity:
- O(n log n)

Space Complexity:
- O(1)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, count = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};
