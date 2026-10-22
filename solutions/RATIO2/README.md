# [Ratio By 2 (RATIO2)](https://www.codechef.com/problems/RATIO2)

- **Difficulty Rating**: 1035
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two positive integers $X$ and $Y$, we want to reach a state where either $X \ge 2Y$ or $Y \ge 2X$. In one operation, we can increment or decrement either $X$ or $Y$ by 1. We need to find the minimum number of operations required to satisfy the condition.

## Intuition & Mathematical Observation
The problem asks for the minimum number of operations to satisfy a ratio condition. Since the constraints on $X$ and $Y$ are very small ($X, Y \le 10$), the optimal target values $(X', Y')$ will not be significantly far from the initial values $(X, Y)$.

1. **Target Condition**: We are looking for any pair $(i, j)$ such that $i \ge 2j$ or $j \ge 2i$.
2. **Search Space**: Since $X, Y \le 10$, iterating through a small range (e.g., $1$ to $30$) for both $i$ and $j$ is sufficient to cover all potential optimal target states.
3. **Cost Function**: The number of operations to reach a target $(i, j)$ from $(X, Y)$ is defined by the Manhattan distance: $|X - i| + |Y - j|$.
4. **Optimization**: By iterating through all valid pairs $(i, j)$ within the search range, we can calculate the cost for each and keep track of the minimum value found.

## Complexity Analysis
- **Time Complexity**: $O(T \times N^2)$, where $T$ is the number of test cases and $N$ is the range of our search space (in this case, $N=30$). Since $N$ is a small constant, this effectively runs in $O(T)$ time.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the current state and the minimum operations found.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given X and Y. We want to reach a state where X >= 2Y or Y >= 2X.
 * In one operation, we can change X or Y by +1 or -1.
 * Given the constraints are small (X, Y <= 10), we can iterate through all 
 * possible target values for X' and Y' within a reasonable range and find 
 * the minimum operations.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    long long min_ops = 1e18;

    // We check a range [1, 30] for target values i and j.
    // This range is sufficient given the small input constraints.
    for (int i = 1; i <= 30; ++i) {
        for (int j = 1; j <= 30; ++j) {
            // Check if the target state satisfies the ratio condition
            if (i >= 2 * j || j >= 2 * i) {
                long long ops = abs(X - i) + abs(Y - j);
                if (ops < min_ops) {
                    min_ops = ops;
                }
            }
        }
    }
    cout << min_ops << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```