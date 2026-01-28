/*
Problem Name : Smallest Subsequence of Distinct Characters
LeetCode ID  : 1081
Difficulty  : Medium
Category    : Greedy / Stack / String

---------------------------------------------------
Problem Statement:
Given a string s, return the lexicographically smallest
subsequence of s that contains all the distinct
characters of s exactly once.

---------------------------------------------------
Key Idea (Stack Based):
- Use a monotonic increasing stack.
- Each character appears only once in the stack.
- Greedily remove characters from the stack if:
  1) Current character is smaller
  2) The stack top appears again later

---------------------------------------------------
Approach:
1. Store the last occurrence of each character.
2. Traverse the string:
   - Skip character if already in stack
   - While stack top is lexicographically greater
     AND appears later → pop it
   - Push current character
3. Stack now contains the smallest valid subsequence.

---------------------------------------------------
Why Stack Works:
- Maintains order (subsequence)
- Greedy removal ensures lexicographically smallest result
- Last occurrence check ensures correctness

---------------------------------------------------
Time Complexity:
- O(n)

Space Complexity:
- O(1) (only 26 lowercase letters)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();

        // Last occurrence of each character
        vector<int> lastIndex(26);
        for (int i = 0; i < n; i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<bool> inStack(26, false);
        stack<char> st;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            // If already in stack, skip
            if (inStack[c - 'a']) continue;

            // Maintain lexicographical order
            while (!st.empty() &&
                   st.top() > c &&
                   lastIndex[st.top() - 'a'] > i) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            inStack[c - 'a'] = true;
        }

        // Build result from stack
        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
