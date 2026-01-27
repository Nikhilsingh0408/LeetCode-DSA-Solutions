/*
Problem Name : Apple Redistribution into Boxes
LeetCode ID  : 3074
Difficulty  : Easy
Category    : Greedy / Sorting

---------------------------------------------------
Problem Statement:
You are given:
- apple[i] → number of apples in the i-th pack
- capacity[j] → capacity of the j-th box

Apples from the same pack can be split across boxes.

Return the minimum number of boxes required to store
all apples.

---------------------------------------------------
Key Observation:
- Only the TOTAL number of apples matters.
- To minimize the number of boxes used, we should
  always pick the boxes with the largest capacities first.

---------------------------------------------------
Approach: Greedy + Sorting
---------------------------------------------------
Steps:
1. Compute total number of apples.
2. Sort the capacity array in descending order.
3. Keep picking boxes until total capacity ≥ total apples.

---------------------------------------------------
Why This Works:
- Using the largest boxes first minimizes the count.
- Since apples can be freely distributed, box order
  does not matter beyond capacity.

---------------------------------------------------
Time Complexity:
- O(m log m), where m = number of boxes

Space Complexity:
- O(1) (ignoring sorting)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApple = 0;
        for (int a : apple) totalApple += a;

        // Sort capacities in descending order
        sort(capacity.begin(), capacity.end(), greater<int>());

        int boxesUsed = 0;
        for (int cap : capacity) {
            if (totalApple <= 0) break;
            totalApple -= cap;
            boxesUsed++;
        }

        return boxesUsed;
    }
};
