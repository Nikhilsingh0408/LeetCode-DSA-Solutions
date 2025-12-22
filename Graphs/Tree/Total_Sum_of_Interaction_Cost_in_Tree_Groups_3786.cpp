/*
Problem Name : Total Sum of Interaction Cost in Tree Groups
LeetCode ID  : 3786
Difficulty  : Hard
Category    : Tree / DFS / Contribution Technique

---------------------------------------------------
Problem Statement:
You are given a tree with n nodes and a group label for
each node.

For every unordered pair (u, v) such that:
    - u != v
    - group[u] == group[v]

The interaction cost is the number of edges on the
unique path between u and v.

Return the total interaction cost over all such pairs.

---------------------------------------------------
Key Observation:
For a fixed group:
- Consider only nodes belonging to that group.
- The tree structure remains the same.
- For every edge, count how many valid pairs use that edge.

---------------------------------------------------
Core Insight (Edge Contribution):
If an edge splits the group nodes into:
    - left side: x nodes
    - right side: (total - x) nodes

Then this edge contributes:
    x * (total - x)
to the total interaction cost.

---------------------------------------------------
Approach: DFS + Contribution Counting
---------------------------------------------------
Steps:
1. Build adjacency list for the tree.
2. Group nodes by their group label.
3. For each group independently:
   - Mark nodes belonging to this group.
   - Run DFS to count how many group-nodes exist in
     each subtree.
   - For every edge (via DFS return values), add:
         subtreeCount * (totalGroupNodes - subtreeCount)
4. Sum contributions for all groups.

---------------------------------------------------
Why This Works:
- Each edge contributes +1 distance for every pair
  whose path crosses that edge.
- DFS efficiently computes subtree sizes.

---------------------------------------------------
Time Complexity:
- O(n * G), where G ≤ 20 (number of groups)

Space Complexity:
- O(n)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> isGrp;
    long long totalNodesGrp;
    long long ans;

    // DFS returns number of nodes in this subtree belonging to current group
    long long dfs(int u, int parent) {
        long long cnt = isGrp[u];

        for (int v : adj[u]) {
            if (v == parent) continue;

            long long childCnt = dfs(v, u);

            // Edge contribution
            ans += childCnt * (totalNodesGrp - childCnt);

            cnt += childCnt;
        }

        return cnt;
    }

    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Group nodes by label
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[group[i]].push_back(i);
        }

        long long result = 0;

        for (auto &it : mp) {
            auto &nodes = it.second;
            if (nodes.size() <= 1) continue;

            // Mark nodes in this group
            isGrp.assign(n, 0);
            for (int x : nodes) isGrp[x] = 1;

            totalNodesGrp = nodes.size();
            ans = 0;

            // DFS from any node in the group
            dfs(nodes[0], -1);

            result += ans;
        }

        return result;
    }
};
