/*
Problem Name : Intersection of Two Arrays II
LeetCode ID  : 350
Difficulty  : Easy
Link        : https://leetcode.com/problems/intersection-of-two-arrays-ii/

---------------------------------------------------
Problem Statement:
Given two integer arrays nums1 and nums2, return an array
of their intersection. Each element in the result should
appear as many times as it shows in both arrays.

You may return the result in any order.

---------------------------------------------------
Example 1:
Input  : nums1 = [1,2,2,1], nums2 = [2,2]
Output : [2,2]

Example 2:
Input  : nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output : [4,9]

---------------------------------------------------
Approach: Hash Map (Frequency Count)
---------------------------------------------------
Idea:
- Count frequencies of elements in nums1 using a hash map.
- Traverse nums2:
  - If the element exists in the map with frequency > 0,
    add it to the result and decrement the count.

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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        vector<int> result;

        // Count frequencies of nums1
        for (int num : nums1) {
            freq[num]++;
        }

        // Find intersection with nums2
        for (int num : nums2) {
            if (freq[num] > 0) {
                result.push_back(num);
                freq[num]--;
            }
        }

        return result;
    }
};
