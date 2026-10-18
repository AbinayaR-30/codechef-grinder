# [Odd Repeat (REPEAT)](https://www.codechef.com/problems/REPEAT)

- **Difficulty Rating**: 1218
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an array of length $N + K - 1$. This array contains all the first $N$ positive odd numbers, but one specific odd number $x$ is repeated $K$ times instead of appearing just once. Given the total sum $S$ of the elements in the array, we need to identify the value of $x$.

## Intuition & Mathematical Observation
1. **Sum of Odd Numbers**: The first $N$ positive odd numbers are $1, 3, 5, \dots, (2N-1)$. A well-known mathematical property is that the sum of the first $N$ odd numbers is exactly $N^2$.
2. **Formulating the Equation**:
   - Let the original set of $N$ odd numbers have a sum of $N^2$.
   - In the modified array, we remove one instance of $x$ and add $K$ instances of $x$.
   - The total sum $S$ can be expressed as:
     $$S = (\text{Sum of first } N \text{ odd numbers}) - x + (K \cdot x)$$
     $$S = N^2 + x(K - 1)$$
3. **Solving for $x$**:
   - Rearranging the equation to isolate $x$:
     $$x(K - 1) = S - N^2$$
     $$x = \frac{S - N^2}{K - 1}$$
4. **Constraints**: Since $N \le 10^4$, $N^2$ will be at most $10^8$, which fits comfortably within a standard 64-bit integer (`long long` in C++).

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic calculation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array contains the first N positive odd numbers.
 * The first N positive odd numbers are: 1, 3, 5, ..., (2N - 1).
 * The sum of the first N positive odd numbers is N^2.
 * 
 * Let x be the number that appears K times.
 * The array consists of all N odd numbers (sum = N^2), but one of them (x) 
 * is replaced by x repeated K times instead of once.
 * 
 * Effectively, the sum S is:
 * S = (Sum of first N odd numbers) - x + (K * x)
 * S = N^2 - x + K * x
 * S = N^2 + x * (K - 1)
 * 
 * Rearranging to solve for x:
 * x * (K - 1) = S - N^2
 * x = (S - N^2) / (K - 1)
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k, s;
        cin >> n >> k >> s;

        // Calculate N^2
        long long n_squared = n * n;

        // Calculate the repeated number x
        // x = (S - N^2) / (K - 1)
        long long x = (s - n_squared) / (k - 1);

        cout << x << "\n";
    }

    return 0;
}
```