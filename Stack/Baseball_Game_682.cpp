/*
Problem Name : Baseball Game
LeetCode ID  : 682
Difficulty  : Easy
Link        : https://leetcode.com/problems/baseball-game/

---------------------------------------------------
Approach: Stack Simulation
---------------------------------------------------
Idea:
- Use stack to keep track of valid scores.
- Handle operations: "+", "D", "C".

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
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for (string &op : operations) {
            if (op == "C") {
                st.pop();
            } else if (op == "D") {
                st.push(2 * st.top());
            } else if (op == "+") {
                int top1 = st.top(); st.pop();
                int top2 = st.top();
                st.push(top1);
                st.push(top1 + top2);
            } else {
                st.push(stoi(op));
            }
        }

        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
