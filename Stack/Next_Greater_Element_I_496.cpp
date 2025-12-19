/*
Problem Name : Next Greater Element I
LeetCode ID  : 496
Difficulty  : Easy
Link        : https://leetcode.com/problems/next-greater-element-i/

---------------------------------------------------
Approach: Monotonic Stack
---------------------------------------------------
Idea:
- Use stack to find next greater element.
- Store results in hashmap.

---------------------------------------------------
Time Complexity:
- O(n)

Space Complexity:
- O(n)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> result;
        for (int num : nums1) {
            result.push_back(mp.count(num) ? mp[num] : -1);
        }

        return result;
    }
};
