/*
Problem Name : Find All People With Secret
LeetCode ID  : 2092
Difficulty  : Hard
Link        : https://leetcode.com/problems/find-all-people-with-secret/

---------------------------------------------------
Problem Statement:
There are n people numbered from 0 to n-1. Person 0 knows
a secret and shares it with firstPerson at time 0.

You are given meetings where meetings[i] = [x, y, time]
meaning person x and y meet at that time.

If a person knows the secret at or before the meeting time,
they can share it. A person can receive and share the secret
within the same time frame.

Return all people who know the secret after all meetings.

---------------------------------------------------
Key Observation:
- Meetings are time-dependent.
- A person can only share the secret in meetings that happen
  at or after the time they learned the secret.

---------------------------------------------------
Approach: Time-Aware Graph + Dijkstra (Optimal)
---------------------------------------------------
Idea:
- Build an undirected graph where edges represent meetings
  with a specific time.
- Maintain an array `time[]` where time[i] is the earliest
  time person i learns the secret.
- Initialize:
  - time[0] = 0
  - time[firstPerson] = 0
- Use a min-heap (priority queue) to always process the
  earliest possible secret sharing.
- For each meeting (u → v at t):
  - If u knows the secret by time ≤ t,
    then v can learn it at time t.

---------------------------------------------------
Why Dijkstra Works:
- We are minimizing the earliest time a person can
  obtain the secret.
- Each meeting acts like a weighted edge (weight = time).

---------------------------------------------------
Time Complexity:
- O((n + m) log n), where m = meetings.length

Space Complexity:
- O(n + m)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        // Build graph: person -> {neighbor, meeting_time}
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto &m : meetings) {
            graph[m[0]].push_back({m[1], m[2]});
            graph[m[1]].push_back({m[0], m[2]});
        }

        // time[i] = earliest time person i knows the secret
        vector<int> time(n, INT_MAX);
        time[0] = 0;
        time[firstPerson] = 0;

        // Min-heap: {time, person}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});

        // Dijkstra-like traversal
        while (!pq.empty()) {
            auto [currTime, person] = pq.top();
            pq.pop();

            // Skip outdated states
            if (currTime > time[person]) continue;

            for (auto &nbr : graph[person]) {
                int nextPerson = nbr.first;
                int meetTime = nbr.second;

                // Can share secret only if meeting time >= known time
                if (meetTime >= currTime && meetTime < time[nextPerson]) {
                    time[nextPerson] = meetTime;
                    pq.push({meetTime, nextPerson});
                }
            }
        }

        // Collect all people who learned the secret
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (time[i] != INT_MAX) {
                result.push_back(i);
            }
        }

        return result;
    }
};
