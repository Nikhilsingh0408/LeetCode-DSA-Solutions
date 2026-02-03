/*
Problem Name : N-ary Tree Level Order Traversal
LeetCode ID  : 429
Difficulty  : Medium
Category    : Tree / BFS

---------------------------------------------------
Idea:
- Use BFS (queue)
- Process nodes level by level
- Push all children of current level nodes

---------------------------------------------------
Time Complexity:
- O(n) where n = number of nodes

Space Complexity:
- O(n) for queue + result storage

---------------------------------------------------
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _children) : val(_val), children(_children) {}
};
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};

        queue<Node*> q;
        q.push(root);

        vector<vector<int>> ans;

        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;

            while (sz--) {
                Node* node = q.front();
                q.pop();

                level.push_back(node->val);

                for (Node* child : node->children) {
                    q.push(child);
                }
            }

            ans.push_back(level);
        }

        return ans;
    }
};
