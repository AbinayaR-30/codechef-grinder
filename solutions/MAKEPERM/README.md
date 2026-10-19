# [Make Permutation (MAKEPERM)](https://www.codechef.com/problems/MAKEPERM)

- **Difficulty Rating**: 1200
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of size $N$, we need to determine if it is possible to construct an array $B$ of non-negative integers such that $C_i = A_i + B_i$ forms a permutation of the numbers $\{1, 2, \dots, N\}$. In other words, we need to check if we can increase each element $A_i$ (or keep it the same) such that the resulting set of numbers is exactly $\{1, 2, \dots, N\}$.

## Intuition & Mathematical Observation
The condition $C_i = A_i + B_i$ with $B_i \ge 0$ implies that $C_i \ge A_i$. 

If we want to transform the array $A$ into a permutation of $\{1, 2, \dots, N\}$, the most efficient way to check feasibility is to sort both the array $A$ and the target set $\{1, 2, \dots, N\}$. 

Let the sorted array be $A'$ where $A'_0 \le A'_1 \le \dots \le A'_{N-1}$.
The target permutation sorted is $1, 2, \dots, N$.

For a valid assignment to exist, each $A'_i$ must be able to "reach" at least the value $(i+1)$. If any $A'_i > (i+1)$, it is impossible to transform $A'_i$ into any value $v \in \{1, \dots, i+1\}$ because $A'_i$ is already greater than those values, and we are only allowed to increase elements (add $B_i \ge 0$). Conversely, if $A'_i \le (i+1)$ for all $i$, we can always set $B_i = (i+1) - A'_i$, which satisfies $B_i \ge 0$.

Thus, the condition simplifies to: **After sorting $A$, check if $A[i] \le i+1$ for all $0 \le i < N$.**

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan takes $O(N)$. Given $N$ is typically up to $10^5$, this fits well within the time limits.
- **Space Complexity**: $O(N)$ to store the array $A$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N. We need to find if there exists an array B 
 * of non-negative integers such that C_i = A_i + B_i forms a permutation of 1 to N.
 * 
 * Since B_i >= 0, we must have C_i >= A_i.
 * If we sort array A in non-decreasing order, the condition is satisfied 
 * if and only if for all i from 0 to N-1: sorted_A[i] <= (i + 1).
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort A to compare with the sorted permutation 1, 2, ..., N
    sort(A.begin(), A.end());
    
    bool possible = true;
    for (int i = 0; i < N; ++i) {
        // The i-th smallest element in the permutation is (i + 1)
        // We need A[i] <= (i + 1) to ensure B[i] >= 0
        if (A[i] > (i + 1)) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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