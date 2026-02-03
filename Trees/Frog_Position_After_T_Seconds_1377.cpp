/*
Problem Name : Frog Position After T Seconds
LeetCode ID  : 1377
Difficulty  : Hard
Category    : Tree / DFS / Probability

---------------------------------------------------
Idea:
- The tree is undirected and acyclic.
- Frog starts from node 1.
- At each second, frog moves to any unvisited child with equal probability.
- If no unvisited child exists, frog stays on the same node forever.

We perform DFS:
- Track current node, parent, remaining time.
- Count number of unvisited children.
- Distribute probability equally among children.
- Special handling when target is reached early and no moves remain.

---------------------------------------------------
Time Complexity:
- O(n)

Space Complexity:
- O(n) (recursion stack + adjacency list)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double dfs(int u, int parent, vector<vector<int>>& adj, int t, int target) {
        if (t < 0) return 0.0;

        // Time finished
        if (t == 0) {
            return (u == target) ? 1.0 : 0.0;
        }

        int children = 0;
        for (int v : adj[u]) {
            if (v != parent) children++;
        }

        // If frog is already at target and can't move further
        if (u == target && children == 0) {
            return 1.0;
        }

        double prob = 0.0;
        for (int v : adj[u]) {
            if (v == parent) continue;
            prob += dfs(v, u, adj, t - 1, target) / children;
        }

        return prob;
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        return dfs(1, 0, adj, t, target);
    }
};
