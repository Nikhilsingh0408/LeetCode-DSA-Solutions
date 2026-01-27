/*
Problem Name : Minimum Cost Path with Edge Reversals
LeetCode ID  : 3650
Difficulty  : Medium
Category    : Graph / Dijkstra (State Transformation)

---------------------------------------------------
Problem Statement:
You are given a directed, weighted graph.

Each node has a special switch that can be used at most once:
- When you arrive at node u, you may reverse ONE incoming edge
  (v -> u) into (u -> v) and traverse it immediately.
- The cost of using the reversed edge is 2 * w.
- The reversal is valid for only that single move.

Find the minimum cost to go from node 0 to node n-1.

---------------------------------------------------
Key Insight:
Instead of explicitly tracking "switch used or not" states,
we can MODEL the graph differently.

---------------------------------------------------
Graph Transformation Trick:
For each directed edge:
    u -> v with cost w

We add:
1) u -> v with cost w        (normal move)
2) v -> u with cost 2 * w    (using the switch at v)

Why this works:
- Reversed traversal is allowed only when you are at v.
- Cost is doubled, exactly as required.
- Using Dijkstra naturally ensures minimal usage.

---------------------------------------------------
Approach: Dijkstra on Transformed Graph
---------------------------------------------------
Steps:
1. Build adjacency list:
   - original edge: u -> v (w)
   - reverse option: v -> u (2*w)
2. Run Dijkstra from node 0.
3. Return shortest distance to node n-1.

---------------------------------------------------
Time Complexity:
- O((n + m) log n)

Space Complexity:
- O(n + m)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n);

        // Build transformed graph
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});       // normal edge
            graph[v].push_back({u, 2 * w});   // reversed edge via switch
        }

        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto &edge : graph[node]) {
                int next = edge.first;
                int wt   = edge.second;

                if (d + wt < dist[next]) {
                    dist[next] = d + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
};
