# [Selling Donuts (DONUTSELL)](https://www.codechef.com/problems/DONUTSELL)

- **Difficulty Rating**: 754
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ types of donuts, each with an initial stock count $A_i$. A sequence of $M$ customers arrives, where each customer requests a specific type of donut $B_i$. If the requested donut is in stock ($A_{B_i} > 0$), the shop sells one unit (decrementing the stock). If the stock for that type is zero, the customer leaves unhappy. The goal is to calculate the total number of "sad" (unhappy) customers.

## Intuition & Mathematical Observation
The problem can be modeled as a direct simulation. Since the constraints are small ($N, M \le 100$), we do not need complex data structures. 

1. **Storage**: We store the donut counts in an array (or vector) of size $N+1$ to accommodate 1-based indexing, which matches the input format for donut types.
2. **Simulation**: As we iterate through the list of $M$ customer requests:
   - If the requested donut type has a count greater than 0, we decrement the count.
   - If the count is 0, it implies the shop is out of that specific donut, so we increment a counter for `sad_customers`.
3. **Efficiency**: Because we process each customer request exactly once and perform constant-time lookups and updates, the simulation is highly efficient.

## Complexity Analysis
- **Time Complexity**: $O(T \times (N + M))$, where $T$ is the number of test cases, $N$ is the number of donut types, and $M$ is the number of customers. Given $N, M \le 100$, this performs well within the time limit.
- **Space Complexity**: $O(N)$ to store the initial counts of the $N$ donut types.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Selling Donuts
 * Approach:
 * We are given N types of donuts with initial counts A_i.
 * M customers arrive sequentially, each wanting one donut of type B_i.
 * If A[B_i] > 0, we decrement A[B_i] and the customer is satisfied.
 * If A[B_i] == 0, the customer is sad.
 * We need to count the total number of sad customers.
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    // Use 1-based indexing for convenience since B_i is 1 to N
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    int sad_customers = 0;
    for (int i = 0; i < M; ++i) {
        int type;
        cin >> type;
        
        // Check if the requested donut type is available
        if (A[type] > 0) {
            A[type]--;
        } else {
            // No donuts of this type left, customer is sad
            sad_customers++;
        }
    }

    cout << sad_customers << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```