/*
Problem Name : Divide an Array Into Subarrays With Minimum Cost II
LeetCode ID  : 3013
Difficulty  : Hard
Category    : Sliding Window + Heap + Ordered Set

---------------------------------------------------
Idea:
- nums[0] is always chosen
- Choose (k-1) more elements from a sliding window
- Window size = dist + 1
- Maintain k-1 minimum elements using set + min heap

---------------------------------------------------
Time Complexity:
- O(n log k)

Space Complexity:
- O(k)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        long long currSum = nums[0];   // nums[0] is always included
        long long ans = LLONG_MAX;

        // chosen k-1 minimum elements
        set<pair<int,int>> chosen;

        // candidate elements
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> pq;

        // initialize window [1 ... dist+1]
        for (int i = 1; i <= dist + 1; i++) {
            pq.push({nums[i], i});
        }

        // pick initial k-1 smallest
        for (int i = 0; i < k - 1; i++) {
            auto p = pq.top(); pq.pop();
            chosen.insert(p);
            currSum += p.first;
        }

        ans = min(ans, currSum);

        int start = 1, end = dist + 1;

        // slide window
        while (end + 1 < n) {
            end++;
            pq.push({nums[end], end});

            // remove outgoing element
            auto rem = make_pair(nums[start], start);
            if (chosen.count(rem)) {
                chosen.erase(rem);
                currSum -= rem.first;
            }

            // remove invalid heap elements
            while (!pq.empty() && pq.top().second <= start) {
                pq.pop();
            }

            // add smallest valid
            auto nxt = pq.top(); pq.pop();
            chosen.insert(nxt);
            currSum += nxt.first;

            // rebalance if size exceeds
            while (chosen.size() > k - 1) {
                auto it = prev(chosen.end()); // largest
                currSum -= it->first;
                pq.push(*it);
                chosen.erase(it);
            }

            ans = min(ans, currSum);
            start++;
        }

        return ans;
    }
};
