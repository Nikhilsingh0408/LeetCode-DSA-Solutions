/*
Problem Name : Most Frequent Subtree Sum
LeetCode ID  : 508
Difficulty  : Medium
Category    : Tree / DFS / Hashing

---------------------------------------------------
Idea:
- Perform postorder DFS
- For each node, compute subtree sum:
    sum = node->val + leftSum + rightSum
- Store frequency of each subtree sum in a hashmap
- Track maximum frequency
- Return all sums with max frequency

---------------------------------------------------
Time Complexity:
- O(n), where n = number of nodes

Space Complexity:
- O(n) for hashmap + recursion stack

---------------------------------------------------
*/

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> freq;
    int maxFreq = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);

        int sum = root->val + leftSum + rightSum;
        freq[sum]++;
        maxFreq = max(maxFreq, freq[sum]);

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);

        vector<int> ans;
        for (auto &p : freq) {
            if (p.second == maxFreq) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};
