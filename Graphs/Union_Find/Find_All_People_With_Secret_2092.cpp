/*
Problem Name : Find All People With Secret
LeetCode ID  : 2092
Difficulty  : Hard
Link        : https://leetcode.com/problems/find-all-people-with-secret/

---------------------------------------------------
Problem Statement:
There are n people numbered from 0 to n-1. Person 0 knows
a secret and shares it with firstPerson at time 0.

Meetings happen at specific times. A person can share the
secret in a meeting only if they know it at or before the
meeting time. Sharing within the same time is allowed.

Return all people who know the secret after all meetings.

---------------------------------------------------
Approach: Union-Find with Time Grouping
---------------------------------------------------
Key Idea:
- Meetings that happen at the SAME time can freely share
  the secret among themselves.
- Meetings at DIFFERENT times must be processed separately.
- Use Union-Find to temporarily connect people meeting at
  the same time.
- After processing each time group, disconnect people who
  are not connected to person 0.

---------------------------------------------------
Algorithm Steps:
1. Sort all meetings by time.
2. Process meetings with the same time together:
   - Union all participants of meetings at that time.
3. After unions:
   - If a person is NOT connected to person 0,
     reset their parent (disconnect them).
4. Move to the next time group.
5. At the end, all nodes connected to 0 know the secret.

---------------------------------------------------
Why This Works:
- Ensures instant sharing within the same time.
- Prevents sharing across different times incorrectly.
- Efficient for large constraints.

---------------------------------------------------
Time Complexity:
- O(m log m + m α(n))
  where m = meetings.length

Space Complexity:
- O(n)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent, rankVec;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (rankVec[px] < rankVec[py]) {
            parent[px] = py;
        } else if (rankVec[px] > rankVec[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rankVec[px]++;
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        // Initialize DSU
        parent.resize(n);
        rankVec.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        // Person 0 and firstPerson share secret at time 0
        unite(0, firstPerson);

        // Sort meetings by time
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) {
                 return a[2] < b[2];
             });

        int i = 0;
        while (i < meetings.size()) {
            int currTime = meetings[i][2];
            vector<int> participants;

            // Process all meetings at the same time
            while (i < meetings.size() && meetings[i][2] == currTime) {
                int x = meetings[i][0];
                int y = meetings[i][1];
                unite(x, y);
                participants.push_back(x);
                participants.push_back(y);
                i++;
            }

            // Disconnect people who are not connected to person 0
            for (int p : participants) {
                if (find(p) != find(0)) {
                    parent[p] = p;
                }
            }
        }

        // Collect all people connected to person 0
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (find(i) == find(0)) {
                result.push_back(i);
            }
        }

        return result;
    }
};
