# [Make Multiple (MUL123)](https://www.codechef.com/problems/MUL123)

- **Difficulty Rating**: 959
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we want to reach a multiple of 3 using the minimum number of operations. The allowed operations are:
1. Increment $N$ by 1 ($N = N + 1$).
2. Replace $N$ with the next multiple of 5 strictly greater than $N$ ($N = (\lfloor N/5 \rfloor + 1) \times 5$).

We need to find the shortest sequence of operations to transform $N$ into any number $X$ such that $X \equiv 0 \pmod 3$.

## Intuition & Mathematical Observation
Since the target is to find the *minimum* number of operations, this is a classic **Shortest Path Problem** on an unweighted graph. 
- Each integer represents a node.
- The two operations represent directed edges from the current node to the next.
- Since the constraints on $N$ are small ($N \le 100$), the state space is very limited. Even if we perform several operations, the value of $N$ will not grow excessively large, making **Breadth-First Search (BFS)** an ideal approach.

**Key logic:**
- If $N$ is already a multiple of 3, the answer is 0.
- Otherwise, we explore states level by level. The first time we encounter a number divisible by 3, the current depth (number of operations) is guaranteed to be the minimum.

## Complexity Analysis
- **Time Complexity**: $O(V + E)$, where $V$ is the number of reachable states (up to 1000 in our implementation) and $E$ is the number of transitions (2 per state). Given the constraints, this is effectively $O(1)$ per test case.
- **Space Complexity**: $O(V)$ to store the `visited` array and the BFS queue, which is $O(1)$ given the fixed upper bound of 1000.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with N. We have two operations:
 * 1. N = N + 1
 * 2. N = next multiple of 5 strictly greater than N.
 * 
 * Since N is small (up to 100), we can use Breadth-First Search (BFS) 
 * to find the shortest path to any multiple of 3.
 */

int solve() {
    int N;
    cin >> N;

    // Base case: already a multiple of 3
    if (N % 3 == 0) return 0;

    // BFS to find the minimum operations
    queue<pair<int, int>> q;
    q.push({N, 0});
    
    // Visited array to prevent infinite loops
    vector<bool> visited(1000, false);
    visited[N] = true;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int val = curr.first;
        int dist = curr.second;

        // Possible next states
        int next1 = val + 1;
        int next2 = ((val / 5) + 1) * 5;

        int next_states[] = {next1, next2};

        for (int next_val : next_states) {
            // If we found a multiple of 3, return the distance + 1
            if (next_val % 3 == 0) return dist + 1;
            
            // Standard BFS: only visit if not seen before
            if (next_val < 1000 && !visited[next_val]) {
                visited[next_val] = true;
                q.push({next_val, dist + 1});
            }
        }
    }
    return -1;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}
```