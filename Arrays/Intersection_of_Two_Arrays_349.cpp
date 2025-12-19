/*
Problem Name : Intersection of Two Arrays
LeetCode ID  : 349
Difficulty  : Easy
Link        : https://leetcode.com/problems/intersection-of-two-arrays/

---------------------------------------------------
Problem Statement:
Given two integer arrays nums1 and nums2, return an array
of their intersection. Each element in the result must be
unique and you may return the result in any order.

---------------------------------------------------
Example 1:
Input  : nums1 = [1,2,2,1], nums2 = [2,2]
Output : [2]

Example 2:
Input  : nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output : [9,4] (order does not matter)

---------------------------------------------------
Approach: Hash Set (Optimal)
---------------------------------------------------
Idea:
- Store all elements of nums1 in a hash set.
- Traverse nums2:
  - If an element exists in the set, add it to result
    and remove it from the set to ensure uniqueness.

---------------------------------------------------
Time Complexity:
- O(n + m), where n and m are sizes of nums1 and nums2

Space Complexity:
- O(n)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end());
        vector<int> result;

        for (int num : nums2) {
            if (st.count(num)) {
                result.push_back(num);
                st.erase(num); // ensure uniqueness
            }
        }

        return result;
    }
};
