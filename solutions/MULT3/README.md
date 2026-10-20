# [Multiple of 3 (MULT3)](https://www.codechef.com/problems/MULT3)

- **Difficulty Rating**: 297
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a positive integer $N$ ($1 \le N \le 10$), find the nearest multiple of 3. If there are two multiples of 3 equidistant from $N$, choose the smaller one.

## Intuition & Mathematical Observation
To find the nearest multiple of 3, we analyze the remainder of $N$ when divided by 3 ($N \pmod 3$):

1.  **If $N \pmod 3 = 0$**: $N$ is already a multiple of 3. The nearest multiple is $N$ itself.
2.  **If $N \pmod 3 = 1$**: The two surrounding multiples of 3 are $(N-1)$ and $(N+2)$. The distance to $(N-1)$ is 1, while the distance to $(N+2)$ is 2. Since we want the nearest (and smaller if equidistant), we choose $(N-1)$.
3.  **If $N \pmod 3 = 2$**: The two surrounding multiples of 3 are $(N-2)$ and $(N+1)$. The distance to $(N-2)$ is 2, while the distance to $(N+1)$ is 1. We choose $(N+1)$.

This logic covers all cases for any positive integer $N$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ because the solution involves a constant number of arithmetic operations and conditional checks.
- **Space Complexity**: $O(1)$ as we only use a single variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an integer N and need to find the nearest multiple of 3.
 * 
 * Logic:
 * 1. If N % 3 == 0, the nearest multiple is N itself.
 * 2. If N % 3 == 1, the nearest multiple is (N-1).
 * 3. If N % 3 == 2, the nearest multiple is (N+1).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    long long remainder = n % 3;

    if (remainder == 0) {
        cout << n << "\n";
    } else if (remainder == 1) {
        cout << (n - 1) << "\n";
    } else {
        // remainder == 2
        cout << (n + 1) << "\n";
    }

    return 0;
}
```