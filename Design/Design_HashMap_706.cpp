/*
Problem Name : Design HashMap
LeetCode ID  : 706
Difficulty  : Easy
Link        : https://leetcode.com/problems/design-hashmap/

---------------------------------------------------
Approach: Direct Address Table
---------------------------------------------------
Idea:
- Use a vector of fixed size to simulate a hashmap.
- Since constraints are small, direct indexing works.

---------------------------------------------------
Time Complexity:
- O(1) per operation

Space Complexity:
- O(n)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
private:
    vector<int> mp;

public:
    MyHashMap() {
        mp.assign(1000001, -1);
    }

    void put(int key, int value) {
        mp[key] = value;
    }

    int get(int key) {
        return mp[key];
    }

    void remove(int key) {
        mp[key] = -1;
    }
};
