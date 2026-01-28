/*
Problem Name : Remove Duplicate Letters
LeetCode ID  : 316
Difficulty  : Medium
Category    : Greedy / Stack / String

---------------------------------------------------
Problem Statement:
Given a string s, remove duplicate letters so that:
- Every letter appears exactly once
- The result is the smallest possible lexicographically

---------------------------------------------------
Key Observations:
1. Each character should appear once → need to track used characters.
2. We want lexicographically smallest order → greedy decisions.
3. If a character appears later again, we may remove its earlier
   occurrence to place a smaller character first.

---------------------------------------------------
Approach: Greedy + Monotonic Stack
---------------------------------------------------
Idea:
- Maintain a stack (implemented using string).
- For each character:
  - Skip if already used.
  - While stack top is:
      - lexicographically larger than current character
      - AND appears later again
    → pop it from stack.
  - Push current character.

---------------------------------------------------
Why This Works:
- Guarantees each character appears once.
- Always keeps the smallest possible lexicographical order.
- Safe to remove a character only if it appears again later.

---------------------------------------------------
Time Complexity:
- O(n)

Space Complexity:
- O(1) (26 letters only)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> lastIndex(26, 0);
        vector<bool> used(26, false);

        // Store last occurrence index of each character
        for (int i = 0; i < n; i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        string stack;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (used[c - 'a'])
                continue;

            while (!stack.empty() &&
                   stack.back() > c &&
                   lastIndex[stack.back() - 'a'] > i) {
                used[stack.back() - 'a'] = false;
                stack.pop_back();
            }

            stack.push_back(c);
            used[c - 'a'] = true;
        }

        return stack;
    }
};
