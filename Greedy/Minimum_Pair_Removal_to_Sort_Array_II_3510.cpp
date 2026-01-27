/*
Problem Name : Minimum Pair Removal to Sort Array II
LeetCode ID  : 3510
Difficulty  : Hard
Category    : Greedy / Priority Queue / Linked List / Simulation

---------------------------------------------------
Problem Statement:
You are given an array nums.

Operation:
- Select the adjacent pair with the minimum sum
- If multiple, choose the leftmost
- Replace the pair with their sum

Goal:
- Make the array non-decreasing
- Return the minimum number of operations

---------------------------------------------------
Key Observations:
1. Only adjacent inversions (nums[i] > nums[i+1]) prevent sorting.
2. Each operation merges two adjacent elements into one.
3. We should always merge the adjacent pair with:
   - Minimum sum
   - Leftmost position if tie
4. Merging affects neighboring comparisons, so we must update
   inversion count dynamically.

---------------------------------------------------
Core Idea:
- Maintain the array as a doubly-linked list.
- Track all adjacent pairs using a min-heap.
- Track how many "decreasing positions" exist.
- Continue merging until no decreasing pairs remain.

---------------------------------------------------
Data Structures Used:
- std::list       → simulate dynamic array with fast erase
- priority_queue  → get minimum adjacent pair efficiently
- bitset          → mark merged indices (lazy deletion)
- custom comparator → ensure leftmost pair is chosen on tie

---------------------------------------------------
Algorithm:
1. Convert array into a linked list
2. Count initial decreasing pairs
3. Push all adjacent pairs into a min-heap
4. While array is not sorted:
   - Extract valid minimum pair
   - Merge it
   - Update inversion count
   - Update neighboring pairs in heap
5. Return total operations

---------------------------------------------------
Time Complexity:
- O(n log n)

Space Complexity:
- O(n)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 100005;

struct Node {
    ll value;
    int leftIndex;
};

using ListIt = list<Node>::iterator;

struct Pair {
    ListIt first, second;
    ll sum;
    int leftPos;

    Pair(ListIt a, ListIt b)
        : first(a), second(b),
          sum(a->value + b->value),
          leftPos(a->leftIndex) {}
};

struct Compare {
    bool operator()(const Pair& a, const Pair& b) const {
        if (a.sum != b.sum) return a.sum > b.sum;
        return a.leftPos > b.leftPos;
    }
};

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        list<Node> arr;
        bitset<MAX_N> removed;
        priority_queue<Pair, vector<Pair>, Compare> pq;

        int inversions = 0;
        int operations = 0;

        arr.push_back({nums[0], 0});

        for (int i = 1; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
            auto curr = prev(arr.end());
            auto prevNode = prev(curr);

            pq.emplace(prevNode, curr);

            if (nums[i - 1] > nums[i]) inversions++;
        }

        while (inversions > 0 && !pq.empty()) {
            auto p = pq.top(); pq.pop();

            if (removed[p.first->leftIndex] || removed[p.second->leftIndex])
                continue;

            if (p.first->value + p.second->value != p.sum)
                continue;

            operations++;

            if (p.first->value > p.second->value)
                inversions--;

            auto left = (p.first == arr.begin()) ? arr.end() : prev(p.first);
            auto right = next(p.second);

            ll mergedValue = p.sum;

            if (left != arr.end()) {
                if (left->value > p.first->value && left->value <= mergedValue)
                    inversions--;
                if (left->value <= p.first->value && left->value > mergedValue)
                    inversions++;

                pq.emplace(left, p.first);
            }

            if (right != arr.end()) {
                if (p.second->value > right->value && mergedValue <= right->value)
                    inversions--;
                if (p.second->value <= right->value && mergedValue > right->value)
                    inversions++;

                pq.emplace(p.first, right);
            }

            p.first->value = mergedValue;
            removed[p.second->leftIndex] = true;
            arr.erase(p.second);
        }

        return operations;
    }
};
