/*
Problem Name : Describe the Painting
LeetCode ID  : 1943
Difficulty  : Medium
Category    : Line Sweep / Prefix Sum / Events

---------------------------------------------------
Problem Summary:
Each painting segment contributes a color value
over a half-closed interval [start, end).

Overlapping colors are mixed, and we only care
about the SUM of mixed colors.

Goal:
- Produce minimum non-overlapping segments
- Each segment must have a constant mixed color sum

---------------------------------------------------
Key Idea (Line Sweep):
- Convert each segment into two events:
    +color at start
    -color at end
- Sort events by position
- Sweep from left to right while maintaining
  current active color sum
- Whenever sum != 0, record the segment

---------------------------------------------------
Why Line Sweep?
- Coordinates up to 1e5
- Overlaps are frequent
- Efficiently tracks active colors

---------------------------------------------------
Time Complexity:
- O(N log N)

Space Complexity:
- O(N)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<pair<int, long long>> events;

        // Create events
        for (auto &seg : segments) {
            int l = seg[0];
            int r = seg[1];
            long long color = seg[2];

            events.push_back({l, color});    // add color
            events.push_back({r, -color});   // remove color
        }

        // Sort events by position
        sort(events.begin(), events.end());

        vector<vector<long long>> ans;
        long long currSum = 0;
        int prevPos = -1;

        for (int i = 0; i < events.size(); ) {
            int pos = events[i].first;

            // If there is a valid painted segment
            if (prevPos != -1 && currSum != 0 && prevPos < pos) {
                ans.push_back({prevPos, pos, currSum});
            }

            // Process all events at same position
            while (i < events.size() && events[i].first == pos) {
                currSum += events[i].second;
                i++;
            }

            prevPos = pos;
        }

        return ans;
    }
};
