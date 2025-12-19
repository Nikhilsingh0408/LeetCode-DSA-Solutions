/*
Problem Name : Relative Ranks
LeetCode ID  : 506
Difficulty  : Easy
Link        : https://leetcode.com/problems/relative-ranks/

---------------------------------------------------
Approach: Sorting + Index Mapping
---------------------------------------------------
Idea:
- Sort scores with indices.
- Assign medals to top 3, ranks to rest.

---------------------------------------------------
Time Complexity:
- O(n log n)

Space Complexity:
- O(n)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({score[i], i});
        }

        sort(arr.rbegin(), arr.rend());
        vector<string> result(n);

        for (int i = 0; i < n; i++) {
            if (i == 0) result[arr[i].second] = "Gold Medal";
            else if (i == 1) result[arr[i].second] = "Silver Medal";
            else if (i == 2) result[arr[i].second] = "Bronze Medal";
            else result[arr[i].second] = to_string(i + 1);
        }

        return result;
    }
};
