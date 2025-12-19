/*
Problem Name : Majority Element
LeetCode ID  : 169
Difficulty  : Easy
Link        : https://leetcode.com/problems/majority-element/

---------------------------------------------------
Problem Statement:
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than
⌊n / 2⌋ times. It is guaranteed that the majority element
always exists.

---------------------------------------------------
Example 1:
Input  : nums = [3,2,3]
Output : 3

Example 2:
Input  : nums = [2,2,1,1,1,2,2]
Output : 2

---------------------------------------------------
Approach 1: Hash Map Counting
---------------------------------------------------
Idea:
- Count frequency of each element using a hash map.
- Return the element whose frequency is greater than n/2.

---------------------------------------------------
Time Complexity:
- O(n)

Space Complexity:
- O(n)

---------------------------------------------------
Approach 2: Boyer–Moore Voting Algorithm (Optimal)
---------------------------------------------------
Idea:
- Maintain a candidate and a counter.
- If counter becomes zero, choose current element as candidate.
- Increase counter if same as candidate, else decrease.
- The final candidate is the majority element.

---------------------------------------------------
Time Complexity:
- O(n)

Space Complexity:
- O(1)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // -------------------------------
    // Approach 1: Hash Map
    // -------------------------------
    int majorityElementMap(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int num : nums) {
            mp[num]++;
        }

        for (auto &it : mp) {
            if (it.second > n / 2) {
                return it.first;
            }
        }

        return -1; // Guaranteed to exist
    }

    // -------------------------------
    // Approach 2: Boyer–Moore (Optimal)
    // -------------------------------
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};
