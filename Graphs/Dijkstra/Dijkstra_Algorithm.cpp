/*
Algorithm Name : Dijkstra Algorithm
Category       : Graph - Shortest Path
Type           : Single Source Shortest Path (Non-negative weights)

---------------------------------------------------
Description:
Dijkstra's Algorithm finds the shortest distance from a
source node to all other nodes in a weighted graph
(with non-negative edge weights).

---------------------------------------------------
Graph Representation:
- Adjacency List
- Each edge: (neighbor, weight)

---------------------------------------------------
Algorithm Steps:
1. Initialize distance array with INF.
2. Set source distance = 0.
3. Use a min-heap (priority queue) to always pick the
   node with the smallest distance.
4. Relax edges and update distances.

---------------------------------------------------
Time Complexity:
- O((V + E) log V)

Space Complexity:
- O(V + E)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Dijkstra {
public:
    const int INF = 1e9;

    vector<int> shortestPath(int n, vector<vector<pair<int,int>>>& adj, int source) {

        // Distance array
        vector<int> dist(n, INF);
        dist[source] = 0;

        // Min-heap: {distance, node}
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        pq.push({0, source});

        while (!pq.empty()) {
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip outdated state
            if (currDist > dist[node]) continue;

            for (auto &edge : adj[node]) {
                int nextNode = edge.first;
                int weight   = edge.second;

                if (dist[node] + weight < dist[nextNode]) {
                    dist[nextNode] = dist[node] + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        return dist;
    }
};

int main() {
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);

    // add edges (u -> v, weight)
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});

    Dijkstra dj;
    vector<int> dist = dj.shortestPath(n, adj, 0);

    for (int i = 0; i < n; i++) {
        cout << "Distance from 0 to " << i << " = " << dist[i] << endl;
    }
}
