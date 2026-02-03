/*
Problem Name : Design Ride Sharing System
LeetCode ID  : 3829
Difficulty  : Medium
Category    : Design / Queue / Hashing

---------------------------------------------------
Idea:
- Riders and drivers arrive over time.
- Matching must happen in FIFO (arrival order).
- Riders can cancel before being matched.

Data Structures:
- queue<int> rq  -> maintains rider arrival order
- queue<int> dq  -> maintains driver arrival order
- unordered_set<int> activeRiders -> tracks riders who haven't cancelled or matched

Key Trick:
- We cannot delete a rider directly from the queue.
- Instead, we lazily remove cancelled riders during matching.

---------------------------------------------------
Time Complexity:
- addRider      : O(1)
- addDriver     : O(1)
- cancelRider   : O(1)
- match         : Amortized O(1)

Space Complexity:
- O(n)

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class RideSharingSystem {
public:
    queue<int> rq;                // rider queue
    queue<int> dq;                // driver queue
    unordered_set<int> active;    // active (not cancelled / not matched) riders

    RideSharingSystem() {}

    void addRider(int riderId) {
        rq.push(riderId);
        active.insert(riderId);
    }

    void addDriver(int driverId) {
        dq.push(driverId);
    }

    vector<int> matchDriverWithRider() {
        // Remove cancelled riders lazily
        while (!rq.empty() && !active.count(rq.front())) {
            rq.pop();
        }

        if (rq.empty() || dq.empty()) {
            return {-1, -1};
        }

        int driver = dq.front(); dq.pop();
        int rider  = rq.front(); rq.pop();

        active.erase(rider);

        return {driver, rider};
    }

    void cancelRider(int riderId) {
        active.erase(riderId);
    }
};
