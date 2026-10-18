# [Easy Permutation (EASYPERM)](https://www.codechef.com/problems/EASYPERM)

- **Difficulty Rating**: 1057
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to construct a permutation $A$ of the set $\{1, 2, \dots, N\}$ such that the Least Common Multiple (LCM) of the sequence $S = \{1+A_1, 2+A_2, \dots, N+A_N\}$ is minimized.

## Intuition & Mathematical Observation
Let $B_i = i + A_i$. We want to minimize $\text{LCM}(B_1, B_2, \dots, B_N)$.
First, consider the sum of all elements in the sequence $B$:
$$\sum_{i=1}^{N} B_i = \sum_{i=1}^{N} (i + A_i) = \sum_{i=1}^{N} i + \sum_{i=1}^{N} A_i$$
Since $A$ is a permutation of $\{1, \dots, N\}$, $\sum A_i = \sum i = \frac{N(N+1)}{2}$.
Therefore, $\sum B_i = N(N+1)$.

If we choose the permutation $A_i = N - i + 1$, then for every index $i$:
$$B_i = i + (N - i + 1) = N + 1$$
In this case, the sequence $B$ becomes $\{N+1, N+1, \dots, N+1\}$. The LCM of this sequence is simply $N+1$. 

Since the average value of $B_i$ is $N+1$, and the LCM of a set of numbers must be at least the maximum value in that set, the LCM cannot be smaller than $N+1$. Thus, the permutation $A = \{N, N-1, \dots, 1\}$ is optimal.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate from $N$ down to $1$ to print the permutation.
- **Space Complexity**: $O(1)$, as we do not store the permutation in an array and print the values directly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct a permutation A of {1, 2, ..., N} such that 
 * LCM(1+A_1, 2+A_2, ..., N+A_N) is minimized.
 * 
 * By setting A_i = N - i + 1, we ensure that i + A_i = N + 1 for all i.
 * This results in an LCM of N + 1, which is the theoretical minimum.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        // Output the permutation N, N-1, ..., 1
        for (int i = 0; i < n; ++i) {
            cout << (n - i) << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
```