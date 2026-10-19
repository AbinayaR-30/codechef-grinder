# [OR Permutation (PERMOR)](https://www.codechef.com/problems/PERMOR)

- **Difficulty Rating**: 1196
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to construct a permutation $A$ of the numbers $\{1, 2, \dots, N\}$ such that for all $3 \le i \le N$, the condition $A_i \neq (A_{i-1} \mid A_{i-2})$ is satisfied, where $\mid$ denotes the bitwise OR operation.

## Intuition & Mathematical Observation
The bitwise OR operation $x \mid y$ generally results in a value greater than or equal to $\max(x, y)$. 

If we attempt to use an increasing sequence $(1, 2, 3, \dots, N)$, we encounter a failure at $i=3$ because $A_3 = 3$ and $(A_2 \mid A_1) = (2 \mid 1) = 3$, violating the condition $A_i \neq (A_{i-1} \mid A_{i-2})$.

However, if we reverse the sequence to $(N, N-1, \dots, 1)$, we observe the following:
- For any $i$, $A_i$ is strictly smaller than $A_{i-1}$ and $A_{i-2}$.
- Since $A_i < A_{i-1}$ and $A_i < A_{i-2}$, it is highly unlikely for $A_i$ to equal $(A_{i-1} \mid A_{i-2})$ because the bitwise OR of two larger numbers will almost always result in a value larger than $A_i$.
- Testing small cases:
    - For $N=3$: Sequence is $(3, 2, 1)$. $A_3=1, A_2=2, A_1=3$. $(2 \mid 3) = 3$. Since $1 \neq 3$, it holds.
    - For $N=4$: Sequence is $(4, 3, 2, 1)$. $A_3=2, A_2=3, A_1=4$. $(3 \mid 4) = 7 \neq 2$. $A_4=1, A_3=2, A_2=3$. $(2 \mid 3) = 3 \neq 1$. It holds.

Thus, the simple descending permutation $N, N-1, \dots, 1$ satisfies the condition for all $N \ge 3$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate from $N$ down to $1$ once to print the permutation.
- **Space Complexity**: $O(1)$, as we do not store the permutation in an array and only use a few variables for iteration.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find a permutation A of size N such that A[i] != (A[i-1] | A[i-2]) 
 * for all 3 <= i <= N.
 * 
 * By testing the descending sequence (N, N-1, ..., 1), we ensure that A[i] 
 * is always smaller than its predecessors, making it impossible for the 
 * bitwise OR of the two larger predecessors to equal the smaller current element.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        // Output the permutation in descending order: N, N-1, ..., 1
        for (int i = n; i >= 1; --i) {
            cout << i << (i == 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}
```