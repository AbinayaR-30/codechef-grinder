# [Little Chef and Sums (CHEFSUM)](https://www.codechef.com/problems/CHEFSUM)

- **Difficulty Rating**: 1252
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we define two functions:
1. `prefixSum(i)`: The sum of elements from index $1$ to $i$.
2. `suffixSum(i)`: The sum of elements from index $i$ to $N$.

We need to find the index $i$ (1-based) that minimizes the value of $f(i) = \text{prefixSum}(i) + \text{suffixSum}(i)$. If there are multiple such indices, we must return the smallest one.

## Intuition & Mathematical Observation
Let's expand the expression for $f(i)$:
$$f(i) = \sum_{k=1}^{i} A[k] + \sum_{k=i}^{N} A[k]$$

Notice that the element $A[i]$ is included in both the prefix sum and the suffix sum. We can rewrite the expression as:
$$f(i) = \left( \sum_{k=1}^{N} A[k] \right) + A[i]$$

Since the total sum of the array $\sum_{k=1}^{N} A[k]$ is a constant value regardless of the choice of $i$, minimizing $f(i)$ is mathematically equivalent to minimizing $A[i]$. 

Therefore, the problem reduces to finding the index of the smallest element in the array. If there are multiple occurrences of the minimum value, the problem asks for the smallest index, which is naturally handled by iterating through the array and only updating our minimum index when we find a value strictly smaller than our current minimum.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we only need to traverse the array once to find the minimum element.
- **Space Complexity**: $O(1)$, as we only store the current minimum value and its index, processing the input on the fly without needing to store the entire array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * f(i) = (A[1] + ... + A[i]) + (A[i] + ... + A[N])
 * f(i) = (A[1] + ... + A[N]) + A[i]
 * 
 * Minimizing f(i) is equivalent to minimizing A[i].
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    // Initialize min_val with a value larger than any possible A[i] (max 10^5)
    int min_val = 200000; 
    int min_idx = -1;
    
    for (int i = 1; i <= N; ++i) {
        int val;
        cin >> val;
        // We only update if we find a strictly smaller value to ensure 
        // we keep the smallest index in case of ties.
        if (val < min_val) {
            min_val = val;
            min_idx = i;
        }
    }
    
    cout << min_idx << "\n";
}

int main() {
    // Fast I/O for performance
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