# [Gotta Catch Em All (GCEA)](https://www.codechef.com/problems/GCEA)

- **Difficulty Rating**: 898
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ Pekómon, each with a specific difficulty level $A_i$. To catch a Pekómon, you have two options:
1. Use **Normal Pekóballs**: The cost is $A_i \times X$.
2. Use a **Master Pekóball**: The cost is a flat rate of $Y$.

The goal is to calculate the minimum total cost required to catch all $N$ Pekómon.

## Intuition & Mathematical Observation
For each individual Pekómon $i$, we want to minimize the cost incurred. Since the choice for one Pekómon does not affect the cost of another, we can make an independent greedy decision for each:

*   Calculate the cost of using Normal Pekóballs: $C_{normal} = A_i \times X$.
*   Compare this with the cost of using a Master Pekóball: $C_{master} = Y$.
*   The optimal cost for the $i$-th Pekómon is simply $\min(C_{normal}, C_{master})$.

The total minimum cost is the summation of these individual minimums:
$$\text{Total Cost} = \sum_{i=1}^{N} \min(A_i \times X, Y)$$

Given the constraints ($N, X, Y, A_i \le 100$), the maximum possible cost is $100 \times 100 \times 100 = 1,000,000$, which fits well within a standard 32-bit integer. However, using `long long` is a good practice to prevent overflow in similar problems with larger constraints.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the list of Pekómon exactly once.
- **Space Complexity**: $O(1)$ (or $O(N)$ if storing the input array), as we only need to keep track of the running total cost.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each Pekómon with difficulty A_i, we choose the minimum of:
 * 1. Normal Pekóballs: A_i * X
 * 2. Master Pekóball: Y
 * 
 * Total cost = sum(min(A_i * X, Y)) for all i.
 */

void solve() {
    int N;
    long long X, Y;
    cin >> N >> X >> Y;
    
    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        int difficulty;
        cin >> difficulty;
        
        // Calculate cost for current Pekómon
        long long normal_cost = (long long)difficulty * X;
        total_cost += min(normal_cost, Y);
    }
    
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O setup
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