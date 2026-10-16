# [Arya In Grid (ARYAGRID)](https://www.codechef.com/problems/ARYAGRID)

- **Difficulty Rating**: 1341
- **Solved in**: 2 attempt(s)

## Problem Summary
Arya is placed at position $(X_0, Y_0)$ on an $N \times M$ grid. She can move to any cell $(r, c)$ such that the difference between the coordinates is a multiple of $L$. Specifically, she can reach $(r, c)$ if $|r - X_0|$ is a multiple of $L$ and $|c - Y_0|$ is a multiple of $L$. We need to calculate the total number of reachable cells within the grid boundaries $1 \le r \le N$ and $1 \le c \le M$.

## Intuition & Mathematical Observation
The condition that $|r - X_0|$ is a multiple of $L$ implies that $r \equiv X_0 \pmod L$. Similarly, $c \equiv Y_0 \pmod L$. 

Since the choice of row $r$ and column $c$ are independent, the total number of reachable cells is the product of the number of valid rows and the number of valid columns:
$$\text{Total Cells} = (\text{count of valid } r) \times (\text{count of valid } c)$$

To find the number of valid $r$ in the range $[1, N]$:
1. **Smallest valid $r$**: We find the smallest integer $\ge 1$ such that $r \equiv X_0 \pmod L$. This is calculated as $r_{min} = X_0 - \lfloor \frac{X_0 - 1}{L} \rfloor \times L$.
2. **Largest valid $r$**: We find the largest integer $\le N$ such that $r \equiv X_0 \pmod L$. This is calculated as $r_{max} = X_0 + \lfloor \frac{N - X_0}{L} \rfloor \times L$.
3. **Count**: Since these values form an arithmetic progression with common difference $L$, the count is $\frac{r_{max} - r_{min}}{L} + 1$.

The same logic applies to the columns $c$ in the range $[1, M]$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses simple arithmetic operations.
- **Space Complexity**: $O(1)$, as we only store a few `long long` variables.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Arya can reach cell (r, c) if and only if:
 * r = X0 + k1 * L  (where 1 <= r <= N)
 * c = Y0 + k2 * L  (where 1 <= c <= M)
 * 
 * This means r % L == X0 % L and c % L == Y0 % L.
 * We need to count how many integers r in [1, N] satisfy r % L == X0 % L
 * and how many integers c in [1, M] satisfy c % L == Y0 % L.
 */

void solve() {
    long long N, M, X0, Y0, L;
    if (!(cin >> N >> M >> X0 >> Y0 >> L)) return;

    // Calculate number of valid rows in [1, N]
    long long r_min = X0 - ((X0 - 1) / L) * L;
    long long r_max = X0 + ((N - X0) / L) * L;
    long long count_r = (r_max - r_min) / L + 1;

    // Calculate number of valid columns in [1, M]
    long long c_min = Y0 - ((Y0 - 1) / L) * L;
    long long c_max = Y0 + ((M - Y0) / L) * L;
    long long count_c = (c_max - c_min) / L + 1;

    // Total reachable cells is the product of valid rows and columns
    cout << count_r * count_c << "\n";
}

int main() {
    // Optimize I/O operations
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