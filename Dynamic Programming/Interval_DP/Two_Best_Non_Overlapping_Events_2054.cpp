/*
Problem Name : Two Best Non-Overlapping Events
LeetCode ID  : 2054
Difficulty  : Medium
Category    : Dynamic Programming + Binary Search

---------------------------------------------------
Problem Statement:
You are given a list of events, where each event has:
- start time
- end time
- value

You may attend at most TWO non-overlapping events.
Two events overlap if one starts at or before the other ends.

Return the maximum sum of values.

---------------------------------------------------
Key Constraints:
- At most 2 events can be selected
- Events are inclusive: if one ends at time t,
  the next must start at t + 1 or later
- n can be up to 1e5

---------------------------------------------------
Approach: DP + Binary Search
---------------------------------------------------
Idea:
- Sort events by start time
- Use DP to decide at each index:
    - Take the current event
    - Skip the current event

DP State:
dp[idx][count] =
    Maximum value achievable starting from event `idx`
    when `count` events have already been taken.

---------------------------------------------------
Transition:
1. Skip current event:
   solve(idx + 1, count)

2. Take current event:
   - Use binary search to find the next event whose
     start time > current event's end time
   - Add current value + solve(nextIndex, count + 1)

---------------------------------------------------
Base Case:
- If count == 2 → cannot take more events
- If idx == n → no more events

---------------------------------------------------
Time Complexity:
- O(n log n)
  - Sorting: O(n log n)
  - DP states: O(n * 2)
  - Each DP uses binary search

Space Complexity:
- O(n)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[100005][3];
    int n;

    // Find the first event with start time > given endTime
    int binarySearch(vector<vector<int>>& events, int endTime) {
        int l = 0, r = n - 1, ans = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (events[mid][0] > endTime) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int solve(int idx, vector<vector<int>>& events, int count) {
        if (count == 2 || idx >= n) return 0;

        if (dp[idx][count] != -1)
            return dp[idx][count];

        // Skip current event
        int notTake = solve(idx + 1, events, count);

        // Take current event
        int nextIdx = binarySearch(events, events[idx][1]);
        int take = events[idx][2] + solve(nextIdx, events, count + 1);

        return dp[idx][count] = max(take, notTake);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(), events.end()); // sort by start time
        memset(dp, -1, sizeof(dp));
        return solve(0, events, 0);
    }
};
