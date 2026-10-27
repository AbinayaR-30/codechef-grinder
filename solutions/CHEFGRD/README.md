# [Akash and Grid (CHEFGRD)](https://www.codechef.com/problems/CHEFGRD)

- **Difficulty Rating**: 1311
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an $N \times N$ grid (where $N$ is odd), the center of the grid is defined as $(\frac{N+1}{2}, \frac{N+1}{2})$. We are given a starting position $(x_s, y_s)$. We can move diagonally for free (cost 0) or move to an adjacent cell (up, down, left, right) with a cost of 1. The goal is to find the minimum cost to reach the center of the grid.

## Intuition & Mathematical Observation
The key to this problem lies in the parity of the coordinates:

1.  **Diagonal Moves**: A diagonal move changes both $x$ and $y$ by $\pm 1$. Consequently, the sum of the coordinates $(x + y)$ changes by either $+2, 0, \text{ or } -2$. This means the **parity** of $(x + y)$ remains invariant under diagonal moves.
2.  **Adjacent Moves**: An adjacent move changes either $x$ or $y$ by $\pm 1$. This changes the sum $(x + y)$ by exactly $\pm 1$, thereby flipping the parity of the sum.
3.  **The Center**: The center is at $(C, C)$ where $C = \frac{N+1}{2}$. The sum of the center's coordinates is $2C = N+1$. Since $N$ is odd, $N+1$ is always even.
4.  **Conclusion**: 
    *   If the sum of the starting coordinates $(x_s + y_s)$ is **even**, it has the same parity as the center $(2C)$. Therefore, we can reach the center using only diagonal moves at a **cost of 0**.
    *   If the sum $(x_s + y_s)$ is **odd**, it has a different parity than the center. We must perform at least one adjacent move to change the parity, resulting in a **cost of 1**.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple parity check. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and perform the calculation.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The grid size N is odd, and the center is at (C, C) where C = (N + 1) / 2.
 * Diagonal moves are free (cost 0).
 * Horizontal/Vertical moves cost 1.
 * 
 * The parity of the sum of coordinates (x + y) changes with every horizontal/vertical move.
 * Diagonal moves keep the parity of (x + y) constant.
 * The center (C, C) has a coordinate sum of 2C = N + 1, which is always even.
 * If (xs + ys) is even, the parity matches the center (cost 0).
 * If (xs + ys) is odd, the parity does not match the center (cost 1).
 */

void solve() {
    long long N, xs, ys;
    cin >> N >> xs >> ys;
    
    // Check if the sum of coordinates has the same parity as the center (even).
    if ((xs + ys) % 2 == 0) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
    }
}

int main() {
    // Fast I/O
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