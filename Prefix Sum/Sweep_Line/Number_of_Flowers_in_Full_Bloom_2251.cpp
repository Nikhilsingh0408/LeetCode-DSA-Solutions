/*
Problem Name : Number of Flowers in Full Bloom
LeetCode ID  : 2251
Difficulty  : Hard
Category    : Sweep Line / Prefix Sum / Sorting

---------------------------------------------------
Problem Statement:
You are given intervals representing flower bloom times
[start, end] (inclusive) and query times for people.

For each person, return how many flowers are blooming
at the time they arrive.

---------------------------------------------------
Key Insight (Sweep Line):
- Convert intervals into events:
    +1 at start time
    -1 at (end + 1) time
- Sort all events by time.
- Sort people by arrival time.
- Sweep through events while processing people.

---------------------------------------------------
Why This Works:
- Active flowers at time t = sum of all event values ≤ t
- This transforms interval overlap queries into prefix sums.

---------------------------------------------------
Approach:
1. Create events:
   - (start, +1)
   - (end + 1, -1)
2. Sort events by time.
3. Store people as (time, originalIndex) and sort.
4. Sweep through events while iterating people:
   - Update active flower count
   - Store result for each person

---------------------------------------------------
Time Complexity:
- O((n + m) log (n + m))

Space Complexity:
- O(n + m)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers,
                                 vector<int>& people) {
        vector<pair<int, int>> events;

        // Create events
        for (auto &f : flowers) {
            events.push_back({f[0], 1});        // flower starts
            events.push_back({f[1] + 1, -1});   // flower ends
        }

        sort(events.begin(), events.end());

        // Store people with original indices
        vector<pair<int, int>> queries;
        for (int i = 0; i < people.size(); i++) {
            queries.push_back({people[i], i});
        }
        sort(queries.begin(), queries.end());

        vector<int> result(people.size());
        int active = 0;
        int j = 0;

        // Sweep line
        for (auto &q : queries) {
            int time = q.first;
            int idx = q.second;

            while (j < events.size() && events[j].first <= time) {
                active += events[j].second;
                j++;
            }

            result[idx] = active;
        }

        return result;
    }
};
