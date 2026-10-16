# [Chocolate Distribution (CHOCOCHEF)](https://www.codechef.com/problems/CHOCOCHEF)

- **Difficulty Rating**: 1104
- **Solved in**: 3 attempt(s)

## Problem Summary
Given an integer $N$ ($4 \le N \le 10^9$), we need to distribute $N$ chocolates into three jars ($a, b, c$) such that:
1. $a + b + c = N$
2. $a, b, c \ge 1$
3. Exactly two jars contain the same number of chocolates.
4. At least one jar contains an odd number of chocolates.

## Intuition & Mathematical Observation
To satisfy the conditions efficiently, we can fix two of the jars to have the smallest possible positive integer value, which is $1$.

Let $a = 1$ and $b = 1$. 
Then, the third jar must be $c = N - (a + b) = N - 2$.

**Verification of constraints:**
1. **Sum**: $1 + 1 + (N - 2) = N$. (Satisfied)
2. **Positivity**: Since the problem states $N \ge 4$, then $N - 2 \ge 2$. Thus, $a, b, c \ge 1$. (Satisfied)
3. **Exactly two jars equal**: We have two jars with $1$. As long as $N - 2 \neq 1$ (i.e., $N \neq 3$), we have exactly two jars equal. Since $N \ge 4$, this condition holds.
4. **At least one odd**: Since $1$ is an odd number, the condition that at least one jar contains an odd number of chocolates is always satisfied.

Thus, the construction $(1, 1, N-2)$ is a valid solution for all $N \ge 4$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a simple arithmetic subtraction and output the result. Total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We need to distribute N chocolates into three jars (a, b, c) such that:
 * 1. a + b + c = N
 * 2. At least one jar has an odd number of chocolates.
 * 3. Exactly two jars have the same number of chocolates.
 * 4. a, b, c >= 1.
 * 
 * Construction:
 * Let the jars be (1, 1, N-2).
 * - Sum: 1 + 1 + (N-2) = N.
 * - Equality: Two jars have 1, so exactly two are equal (unless N-2 = 1, i.e., N=3, but N >= 4).
 * - Odd: 1 is odd, so at least one jar is odd.
 * - Positivity: Since N >= 4, N-2 >= 2, so all jars >= 1.
 */

void solve() {
    long long N;
    if (!(cin >> N)) return;
    // Output the construction 1, 1, N-2
    cout << "1 1 " << N - 2 << "\n";
}

int main() {
    // Optimize I/O operations
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