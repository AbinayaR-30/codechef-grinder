# [Max Triangle (MAXTRI)](https://www.codechef.com/problems/MAXTRI)

- **Difficulty Rating**: 664
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a set of sticks with lengths $1, 2, 3, \dots, N$, we need to select three sticks that form a non-degenerate triangle such that their perimeter is maximized. If no such triangle can be formed, output -1.

## Intuition & Mathematical Observation
To form a non-degenerate triangle with sides $A, B,$ and $C$ (where $A \le B \le C$), the triangle inequality theorem states that $A + B > C$. To maximize the perimeter $P = A + B + C$, we should choose the largest possible values for $A, B,$ and $C$.

1. **Selecting the sides**: Let the largest side be $C = N$. To maximize the sum, we pick the next two largest available sticks: $B = N-1$ and $A = N-2$.
2. **Checking the condition**: We must satisfy $A + B > C$.
   Substituting our choices: $(N-2) + (N-1) > N$
   $2N - 3 > N$
   $N > 3$
3. **Edge Cases**:
   - If $N=3$, the sticks are $\{1, 2, 3\}$. Here, $1+2 = 3$, which forms a degenerate triangle (a line segment), not a non-degenerate one. Thus, for $N < 4$, it is impossible to form a triangle.
   - For $N \ge 4$, the largest perimeter is $(N) + (N-1) + (N-2) = 3N - 3$.

Since $N$ can be up to $10^8$, the result $3N-3$ will be approximately $3 \times 10^8$, which fits comfortably within a standard 32-bit integer, though `long long` is used for safety.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves simple arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have sticks of lengths 1, 2, ..., N.
 * We want to choose three sticks A, B, C such that they form a non-degenerate triangle.
 * The condition for a non-degenerate triangle is: A + B > C (assuming A <= B <= C).
 * To maximize the perimeter (A + B + C), we pick the largest possible sticks:
 * C = N, B = N-1, A = N-2.
 * Condition: (N-2) + (N-1) > N  => 2N - 3 > N => N > 3.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;

        if (n < 4) {
            // Cannot form a triangle with sticks 1, 2, 3 or smaller
            cout << -1 << "\n";
        } else {
            // The maximum perimeter is formed by the three largest sticks: N, N-1, N-2
            // Perimeter = N + (N-1) + (N-2) = 3N - 3
            long long result = 3 * n - 3;
            cout << result << "\n";
        }
    }

    return 0;
}
```