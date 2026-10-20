# [Obtain the Sum (BIGARRAY)](https://www.codechef.com/problems/BIGARRAY)

- **Difficulty Rating**: 1368
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an array $A$ of size $N$ where $A[i] = i$ for all $1 \le i \le N$. We are asked to find an index $x$ such that if we remove the element at index $x$, the sum of the remaining elements equals a given integer $S$. If no such $x$ exists, we must output -1.

## Intuition & Mathematical Observation
1.  **Total Sum**: The sum of all elements in the array is the sum of the first $N$ natural numbers, given by the formula:
    $$\text{TotalSum} = \frac{N(N + 1)}{2}$$
2.  **Deriving $x$**: Let the sum of the remaining elements be $S$. If we remove the element at index $x$ (where $A[x] = x$), the equation becomes:
    $$\text{TotalSum} - x = S$$
    Rearranging this, we get:
    $$x = \text{TotalSum} - S$$
3.  **Validation**: Since the array contains elements from $1$ to $N$, the removed element $x$ must satisfy $1 \le x \le N$. If the calculated $x$ falls within this range, it is our answer; otherwise, no such element exists, and we output -1.
4.  **Data Types**: Given $N \le 10^9$, the `TotalSum` can reach approximately $5 \times 10^{17}$. This fits within a standard 64-bit integer (`long long` in C++), so we do not need special handling for overflow.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution relies on a simple arithmetic formula.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array A is defined as A[i] = i for 1 <= i <= N.
 * The sum of all elements in the array is TotalSum = N * (N + 1) / 2.
 * The condition given is:
 * (A[1] + ... + A[x-1]) + (A[x+1] + ... + A[N]) = S
 * This is equivalent to:
 * (TotalSum - A[x]) = S
 * Since A[x] = x, the equation becomes:
 * TotalSum - x = S
 * x = TotalSum - S
 * 
 * We need to check if the calculated x satisfies 1 <= x <= N.
 * 
 * Constraints:
 * N <= 10^9, so TotalSum can be up to ~5 * 10^17, which fits in a 64-bit integer (long long).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, s;
        cin >> n >> s;

        // Calculate the sum of the first N natural numbers
        // N=10^9, N*(N+1)/2 fits in long long (max ~5e17).
        long long total_sum = n * (n + 1) / 2;

        // Derived formula: x = TotalSum - S
        long long x = total_sum - s;

        // Check if x is within the valid range [1, N]
        if (x >= 1 && x <= n) {
            cout << x << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
```