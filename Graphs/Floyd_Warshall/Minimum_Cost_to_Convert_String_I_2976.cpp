/*
Problem Name : Minimum Cost to Convert String I
LeetCode ID  : 2976
Difficulty  : Medium
Category    : Graph / Floyd-Warshall / Shortest Path

---------------------------------------------------
Problem Statement:
You are given two strings source and target of equal length.
You can transform characters using given conversion rules
(original -> changed) with an associated cost.

Return the minimum total cost to convert source into target.
If impossible, return -1.

---------------------------------------------------
Key Insight:
- Each character ('a' to 'z') is a node.
- Each conversion rule is a directed weighted edge.
- We need the minimum cost to convert one character to another.
- Since there are only 26 characters, we can run
  Floyd–Warshall to compute all-pairs shortest paths.

---------------------------------------------------
Approach:
1. Build a 26 x 26 adjacency matrix:
   adj[u][v] = minimum cost to convert u → v
2. Initialize adj[i][i] = 0
3. Run Floyd–Warshall to compute minimum costs between all pairs.
4. For each position i:
   - If source[i] == target[i], cost = 0
   - Else add adj[source[i]][target[i]]
   - If conversion is impossible, return -1

---------------------------------------------------
Why Floyd–Warshall Works Here:
- Graph size is fixed (26 nodes)
- Time complexity: O(26³) ≈ constant
- Allows multi-step conversions (e.g., a → c → b)

---------------------------------------------------
Time Complexity:
- Floyd–Warshall: O(26³) ≈ O(1)
- Final traversal: O(n)

Space Complexity:
- O(26²)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumCost(string source,
                          string target,
                          vector<char> &original,
                          vector<char> &changed,
                          vector<int> &cost)
    {
        const long long INF = 1e18;

        // Adjacency matrix
        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        // Distance to self is 0
        for (int i = 0; i < 26; i++)
        {
            dist[i][i] = 0;
        }

        // Fill direct conversion costs
        for (int i = 0; i < original.size(); i++)
        {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd–Warshall
        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        long long ans = 0;

        // Compute total conversion cost
        for (int i = 0; i < source.size(); i++)
        {
            if (source[i] == target[i])
                continue;

            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if (dist[s][t] == INF)
            {
                return -1; // impossible conversion
            }

            ans += dist[s][t];
        }

        return ans;
    }
};
