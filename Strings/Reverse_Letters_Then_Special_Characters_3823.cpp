/*
Problem Name : Reverse Letters Then Special Characters in a String
LeetCode ID  : 3823
Difficulty  : Easy
Category    : String / Two Pointers

---------------------------------------------------
Idea:
1) Reverse only letters (keep special characters fixed)
2) Reverse only special characters (keep letters fixed)

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
    bool isSpecial(char c) {
        return c == '!' || c == '@' || c == '#' || c == '$' ||
               c == '%' || c == '^' || c == '&' || c == '*' ||
               c == '(' || c == ')';
    }

    string reverseByType(string s) {
        int n = s.size();
        int i = 0, j = n - 1;

        // Step 1: Reverse special characters
        while (i < j) {
            while (i < j && !isSpecial(s[i])) i++;
            while (i < j && !isSpecial(s[j])) j--;
            if (i < j) swap(s[i++], s[j--]);
        }

        i = 0, j = n - 1;

        // Step 2: Reverse letters
        while (i < j) {
            while (i < j && isSpecial(s[i])) i++;
            while (i < j && isSpecial(s[j])) j--;
            if (i < j) swap(s[i++], s[j--]);
        }

        return s;
    }
};
