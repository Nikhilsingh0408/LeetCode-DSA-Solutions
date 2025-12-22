/*
Problem Name : Minimum Deletion Cost to Make All Characters Equal
LeetCode ID  : 3784
Difficulty  : Medium
Category    : Greedy / Hashing

---------------------------------------------------
Problem Statement:
You are given a string s and an array cost, where cost[i]
is the cost to delete the i-th character.

You may delete characters so that the final string:
- Is non-empty
- Consists of only one unique character

Return the minimum total deletion cost.

---------------------------------------------------
Key Observation:
- In the final string, only ONE character type remains.
- All other characters must be deleted.
- To minimize deletion cost, we should KEEP the character
  whose total deletion cost is MAXIMUM.

---------------------------------------------------
Approach: Hashing + Greedy
---------------------------------------------------
Idea:
1. Compute total deletion cost of all characters.
2. Compute total cost per character using a hash map.
3. If we keep character 'c':
      deletion cost = totalCost - costSum[c]
4. Choose the character that minimizes deletion cost.

---------------------------------------------------
Why This Works:
- Final string must contain exactly one unique character.
- Keeping the most expensive-to-delete character minimizes
  total deletions.

---------------------------------------------------
Time Complexity:
- O(n)

Space Complexity:
- O(1) (at most 26 characters)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n = s.length();
        unordered_map<char, long long> freqCost;
        long long totalCost = 0;

        for (int i = 0; i < n; i++) {
            freqCost[s[i]] += cost[i];
            totalCost += cost[i];
        }

        long long result = LLONG_MAX;
        for (auto &it : freqCost) {
            result = min(result, totalCost - it.second);
        }

        return result;
    }
};
