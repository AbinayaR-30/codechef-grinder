# [Average of Three (AVGOF3)](https://www.codechef.com/problems/AVGOF3)

- **Difficulty Rating**: 1141
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $X$, we need to find three **distinct** positive integers $A_1, A_2, A_3$ such that their average is exactly $X$. Mathematically, this is equivalent to finding three distinct integers such that their sum is $3X$.

## Intuition & Mathematical Observation
To satisfy the condition $\frac{A_1 + A_2 + A_3}{3} = X$, we must ensure $A_1 + A_2 + A_3 = 3X$.

A simple and effective strategy is to pick three consecutive integers centered around $X$:
- Let $A_1 = X - 1$
- Let $A_2 = X$
- Let $A_3 = X + 1$

**Verification:**
1. **Mean**: $\frac{(X-1) + X + (X+1)}{3} = \frac{3X}{3} = X$. (Condition satisfied)
2. **Distinctness**: Since $X-1 < X < X+1$, the integers are always distinct.
3. **Constraints**: The problem states $2 \le X \le 100$. 
   - The smallest value is $X=2$, yielding $\{1, 2, 3\}$, which are all positive integers.
   - The largest value is $X=100$, yielding $\{99, 100, 101\}$, which are well within the allowed range.

This construction is valid for all inputs provided in the problem.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find three distinct integers A1, A2, A3 such that:
 * (A1 + A2 + A3) / 3 = X
 * This implies A1 + A2 + A3 = 3 * X.
 * 
 * We can choose A1 = X - 1, A2 = X, and A3 = X + 1.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x;
        cin >> x;
        
        // Using the construction A1 = x-1, A2 = x, A3 = x+1
        // This ensures the mean is x and all numbers are distinct.
        cout << (x - 1) << " " << x << " " << (x + 1) << "\n";
    }

    return 0;
}
```