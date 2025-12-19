/*
Problem Name : Longest Common Prefix
LeetCode ID  : 14
Difficulty  : Easy
Link        : https://leetcode.com/problems/longest-common-prefix/

---------------------------------------------------
Problem Statement:
Write a function to find the longest common prefix string
amongst an array of strings.

If there is no common prefix, return an empty string "".

---------------------------------------------------
Example 1:
Input  : ["flower","flow","flight"]
Output : "fl"

Example 2:
Input  : ["dog","racecar","car"]
Output : ""

---------------------------------------------------
Approach: Sorting Based Comparison
---------------------------------------------------
Idea:
- Sort the array of strings lexicographically.
- After sorting, the common prefix of the entire array
  must be the common prefix of the first and last strings.
- Compare characters of the first and last strings
  until they differ.

Why it works:
- Sorting brings similar prefixes closer.
- The maximum possible common prefix is limited
  by the first and last string after sorting.

---------------------------------------------------
Time Complexity:
- O(n log n) for sorting
- O(m) for prefix comparison
  where m = length of the shortest string

Overall: O(n log n)

Space Complexity:
- O(1) (excluding sort space)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Edge case: empty input
        if (strs.empty()) return "";

        // Sort the strings
        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last  = strs[strs.size() - 1];
        string ans   = "";

        // Compare characters of first and last string
        for (int i = 0; i < min(first.length(), last.length()); i++) {
            if (first[i] == last[i]) {
                ans += first[i];
            } else {
                break;
            }
        }

        return ans;
    }
};
