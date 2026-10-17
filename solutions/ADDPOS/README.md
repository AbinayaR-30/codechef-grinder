# [Add to make Positive (ADDPOS)](https://www.codechef.com/problems/ADDPOS)

- **Difficulty Rating**: 719
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of length $N$, we need to find the smallest non-negative integer $X$ such that the sum of all elements in the modified array (where each element $A_i$ becomes $A_i + X$) is non-negative. That is, we need to satisfy:
$$\sum_{i=1}^{N} (A_i + X) \ge 0$$

## Intuition & Mathematical Observation
We can expand the summation expression:
$$\sum_{i=1}^{N} A_i + \sum_{i=1}^{N} X \ge 0$$
$$\left(\sum_{i=1}^{N} A_i\right) + N \cdot X \ge 0$$

Let $S$ be the sum of all elements in the array ($\sum A_i$). The inequality becomes:
$$S + N \cdot X \ge 0$$
$$N \cdot X \ge -S$$

1. **Case 1: $S \ge 0$**
   If the sum is already non-negative, the smallest non-negative integer $X$ that satisfies the condition is $0$.

2. **Case 2: $S < 0$**
   We need $X \ge \frac{-S}{N}$. Since $X$ must be an integer, we take the ceiling of the division:
   $$X = \lceil \frac{-S}{N} \rceil$$
   In integer arithmetic, the ceiling of $\frac{a}{b}$ (where $a, b > 0$) is calculated as `(a + b - 1) / b`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to calculate the sum.
- **Space Complexity**: $O(1)$, as we only store the running sum and a few variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of length N.
 * We want to find the minimum non-negative integer X such that:
 * Sum(A_i + X) >= 0 for all i from 1 to N.
 * 
 * Expanding the sum:
 * Sum(A_i) + Sum(X) >= 0
 * Sum(A_i) + N * X >= 0
 * N * X >= -Sum(A_i)
 * X >= -Sum(A_i) / N
 */

void solve() {
    int N;
    cin >> N;
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        long long val;
        cin >> val;
        sum += val;
    }

    if (sum >= 0) {
        cout << 0 << "\n";
    } else {
        // We need N * X >= -sum
        // Let target = -sum (which is positive)
        // X = ceil(target / N)
        // Using integer arithmetic: ceil(a / b) = (a + b - 1) / b
        long long target = -sum;
        long long X = (target + N - 1) / N;
        cout << X << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```