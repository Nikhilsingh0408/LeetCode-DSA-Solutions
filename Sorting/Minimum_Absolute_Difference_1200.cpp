/*
Problem Name : Minimum Absolute Difference
LeetCode ID  : 1200
Difficulty  : Easy
Category    : Arrays / Sorting

---------------------------------------------------
Problem Statement:
You are given an array of DISTINCT integers.

Find all pairs [a, b] such that:
- a < b
- b - a is the minimum absolute difference
  among all possible pairs

Return the list of such pairs in ascending order.

---------------------------------------------------
Key Observation:
- After sorting the array, the minimum absolute
  difference must occur between adjacent elements.
- No need to check all O(n²) pairs.

---------------------------------------------------
Approach: Sort + Linear Scan
---------------------------------------------------
Steps:
1. Sort the array.
2. Traverse once to find the minimum difference
   between consecutive elements.
3. Traverse again and collect all pairs having
   that minimum difference.

---------------------------------------------------
Time Complexity:
- O(n log n) due to sorting

Space Complexity:
- O(1) extra (ignoring output)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        int minDiff = INT_MAX;
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }

        vector<vector<int>> result;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == minDiff) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }

        return result;
    }
};
