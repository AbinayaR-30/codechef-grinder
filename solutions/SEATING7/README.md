# [Seating (SEATING7)](https://www.codechef.com/problems/SEATING7)

- **Difficulty Rating**: 913
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ total seats, some of which are already occupied ($M$ seats). $K$ new people arrive one by one. Each person is assigned the lowest-numbered available seat. We need to output the seat number assigned to each of the $K$ people in the order they arrive.

## Intuition & Mathematical Observation
Since the constraints are small ($N \le 100$), we do not need a complex data structure like a Segment Tree or a Priority Queue. 

1. **Tracking State**: We can use a boolean array (or a `vector<bool>`) of size $N+1$ to keep track of which seats are currently occupied.
2. **Simulation**: For each of the $K$ people, we perform a linear scan from seat $1$ to $N$. The first index `i` where `occupied[i]` is `false` is the seat assigned to that person.
3. **Update**: Once a seat is assigned, we mark it as `true` in our boolean array so that subsequent people do not take the same seat.

## Complexity Analysis
- **Time Complexity**: $O(T \times (M + K \times N))$, where $T$ is the number of test cases. Given $N, K \le 100$, the worst-case operations per test case are roughly $10^4$, which easily fits within the 1-second time limit.
- **Space Complexity**: $O(N)$ to store the status of the seats.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N seats, M are occupied. K people arrive one by one.
 * Each person takes the lowest numbered available seat.
 * Since N is small (up to 100), we can use a boolean array to track
 * occupied seats and iterate to find the lowest available seat for each of the K people.
 */

void solve() {
    int N, M, K;
    if (!(cin >> N >> M >> K)) return;

    // Track seat occupancy (1-indexed)
    vector<bool> occupied(N + 1, false);
    for (int i = 0; i < M; ++i) {
        int seat;
        cin >> seat;
        occupied[seat] = true;
    }

    // Process each of the K people
    vector<int> results;
    for (int i = 0; i < K; ++i) {
        for (int seat = 1; seat <= N; ++seat) {
            if (!occupied[seat]) {
                occupied[seat] = true; // Mark as taken
                results.push_back(seat);
                break;
            }
        }
    }

    // Output the results
    for (int i = 0; i < K; ++i) {
        cout << results[i] << (i == K - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```