/*
Problem Name : Convert Sorted Array to Binary Search Tree
LeetCode ID  : 108
Difficulty  : Easy
Link        : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

---------------------------------------------------
Problem Statement:
Given an integer array nums sorted in strictly increasing
order, convert it into a height-balanced Binary Search Tree.

A height-balanced BST is a binary tree in which the depth
of the two subtrees of every node never differs by more
than one.

---------------------------------------------------
Example 1:
Input  : nums = [-10,-3,0,5,9]
Output : [0,-3,9,-10,null,5]

Example 2:
Input  : nums = [1,3]
Output : [3,1]

---------------------------------------------------
Approach: Divide and Conquer (Recursive)
---------------------------------------------------
Idea:
- Since the array is sorted, the middle element should be
  chosen as the root to maintain balance.
- Recursively build:
  - Left subtree from left half
  - Right subtree from right half
- This guarantees a height-balanced BST.

---------------------------------------------------
Time Complexity:
- O(n), where n is the number of elements

Space Complexity:
- O(log n) due to recursion stack (balanced tree)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function to build BST recursively
    TreeNode* solve(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = (start + end) / 2;

        // Create root with middle element
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively build left and right subtrees
        root->left  = solve(nums, start, mid - 1);
        root->right = solve(nums, mid + 1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};
