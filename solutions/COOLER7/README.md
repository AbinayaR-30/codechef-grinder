# [Cooler (COOLER7)](https://www.codechef.com/problems/COOLER7)

- **Difficulty Rating**: 555
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total time required to cool a room from an initial temperature $N$ to a target temperature $M$. The air conditioner takes $T$ minutes to reduce the temperature from $T$ to $T-1$. We need to find the sum of time taken for each degree reduction from $N$ down to $M$.

## Intuition & Mathematical Observation
To cool the room from $N$ to $M$, the temperature must pass through the sequence: $N \to N-1 \to N-2 \to \dots \to M$.

- The time taken to go from $N$ to $N-1$ is $N$ minutes.
- The time taken to go from $N-1$ to $N-2$ is $N-1$ minutes.
- ...
- The time taken to go from $M+1$ to $M$ is $M+1$ minutes.

The total time is the sum of the arithmetic series:
$$\text{Total Time} = N + (N-1) + (N-2) + \dots + (M+1)$$

This is an arithmetic progression where:
- The number of terms is $N - M$.
- The first term is $N$.
- The last term is $M + 1$.

Using the sum formula for an arithmetic series, $S = \frac{k(a_1 + a_n)}{2}$:
$$\text{Total Time} = \frac{(N - M) \times (N + M + 1)}{2}$$

Since the product of $(N - M)$ and $(N + M + 1)$ is always even (because if $N-M$ is odd, $N+M+1$ must be even, and vice versa), the division by 2 will always result in an integer.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation is performed using a constant-time mathematical formula.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The air conditioner takes X minutes to drop the temperature from X to X-1.
 * To go from N to M, we need to drop the temperature by (N - M) degrees.
 * 
 * Total time = N + (N-1) + (N-2) + ... + (M+1)
 * This is an arithmetic progression sum:
 * Sum = (Number of terms) * (First term + Last term) / 2
 * Number of terms = N - M
 * First term = N
 * Last term = M + 1
 * Total time = (N - M) * (N + M + 1) / 2
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // Using the arithmetic series formula:
        // Sum = (n - m) * (n + m + 1) / 2
        // Since (n - m) and (n + m + 1) have different parity, 
        // their product is always even, so integer division by 2 is safe.
        long long total_time = (n - m) * (n + m + 1) / 2;
        
        cout << total_time << "\n";
    }

    return 0;
}
```