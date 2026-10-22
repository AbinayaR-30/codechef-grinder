# [Coloured Balloons (BALLOONS)](https://www.codechef.com/problems/BALLOONS)

- **Difficulty Rating**: 584
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ different types of balloons, where the $i$-th type of balloon has a cost of $i$ rupees. For each type $i$, we are provided with the quantity $A_i$ of balloons available. The goal is to calculate the total cost incurred by purchasing all the given balloons.

## Intuition & Mathematical Observation
The problem asks for the total cost of a collection of items where each item type has a specific unit price. 
- The cost of one balloon of type $i$ is $i$.
- We have $A_i$ balloons of type $i$.
- Therefore, the total cost for all balloons of type $i$ is $A_i \times i$.
- The total cost for all $N$ types is the summation:
  $$\text{Total Cost} = \sum_{i=1}^{N} (A_i \times i)$$

Given the constraints ($N \le 100$ and $A_i \le 100$), the maximum possible cost is $100 \times (100 \times 100) = 1,000,000$, which easily fits within a standard 32-bit integer. However, using `long long` is a safe practice to avoid potential overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the $N$ balloon types exactly once. With $T$ test cases, the total time complexity is $O(T \times N)$.
- **Space Complexity**: $O(1)$, as we only store the running total and the current input value, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N colours of balloons.
 * The i-th colour balloon costs i rupees.
 * We are given A_i, the number of balloons of the i-th colour.
 * The total cost is the sum of (A_i * i) for all i from 1 to N.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    long long total_cost = 0;
    for (int i = 1; i <= N; ++i) {
        long long A_i;
        cin >> A_i;
        // The cost of the i-th colour is i, and we bought A_i of them.
        total_cost += (A_i * i);
    }
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O setup for performance
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