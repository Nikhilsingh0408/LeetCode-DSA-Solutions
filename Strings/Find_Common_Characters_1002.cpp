/*
Problem Name : Find Common Characters
LeetCode ID  : 1002
Difficulty  : Easy
Link        : https://leetcode.com/problems/find-common-characters/

---------------------------------------------------
Approach: Frequency Intersection
---------------------------------------------------
Idea:
- Maintain minimum frequency of each character across all strings.
- Add characters to result based on minimum count.

---------------------------------------------------
Time Complexity:
- O(n * 26)

Space Complexity:
- O(26)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minFreq(26, INT_MAX);

        for (string &w : words) {
            vector<int> freq(26, 0);
            for (char c : w) freq[c - 'a']++;
            for (int i = 0; i < 26; i++) {
                minFreq[i] = min(minFreq[i], freq[i]);
            }
        }

        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (minFreq[i]--) {
                result.push_back(string(1, 'a' + i));
            }
        }
        return result;
    }
};
