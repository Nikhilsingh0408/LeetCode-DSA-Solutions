/*
Problem Name : Merge Sorted Array
LeetCode ID  : 88
Difficulty  : Easy
Link        : https://leetcode.com/problems/merge-sorted-array/

---------------------------------------------------
Problem Statement:
You are given two sorted integer arrays nums1 and nums2,
and two integers m and n representing the number of valid
elements in nums1 and nums2 respectively.

Merge nums2 into nums1 such that nums1 becomes a single
sorted array in non-decreasing order.

Note:
- nums1 has a size of m + n.
- The last n elements of nums1 are placeholders (0).

---------------------------------------------------
Example 1:
Input  : nums1 = [1,2,3,0,0,0], m = 3
         nums2 = [2,5,6], n = 3
Output : [1,2,2,3,5,6]

Example 2:
Input  : nums1 = [1], m = 1
         nums2 = [], n = 0
Output : [1]

Example 3:
Input  : nums1 = [0], m = 0
         nums2 = [1], n = 1
Output : [1]

---------------------------------------------------
Approach 1: Append + Sort (Simple Approach)
---------------------------------------------------
Idea:
- Copy all elements of nums2 into nums1.
- Sort the entire nums1 array.

Time Complexity:
- O((m + n) log(m + n))

Space Complexity:
- O(1)

---------------------------------------------------
Approach 2: Two Pointer from Back (Optimal Approach)
---------------------------------------------------
Idea:
- Start filling nums1 from the back to avoid overwriting.
- Compare the last elements of nums1 and nums2.
- Place the larger element at the end.

Why it works:
- nums1 has extra space at the end.
- Both arrays are already sorted.

Time Complexity:
- O(m + n)

Space Complexity:
- O(1)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // -------------------------------
    // Approach 1: Append + Sort
    // -------------------------------
    void mergeSimple(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;

        // Copy elements of nums2 into nums1
        for (int i = m; i < nums1.size(); i++) {
            nums1[i] = nums2[j++];
        }

        // Sort the merged array
        sort(nums1.begin(), nums1.end());
    }

    // -------------------------------
    // Approach 2: Two Pointers (Optimal)
    // -------------------------------
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;          // Last index of valid nums1
        int j = n - 1;          // Last index of nums2
        int k = m + n - 1;      // Last index of nums1

        // Merge from the back
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // Copy remaining elements of nums2 (if any)
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
