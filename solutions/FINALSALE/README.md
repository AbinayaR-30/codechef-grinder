# [Sale (FINALSALE)](https://www.codechef.com/problems/FINALSALE)

- **Difficulty Rating**: 1180
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef owns a shop and records the daily sales in an array $A$ of size $N$. Chef decides to close the shop on some day $k$ (where $1 \le k \le N$). The total profit is calculated as the sum of all sales from day $1$ to day $k-1$, plus **twice** the sales of day $k$. The goal is to choose an index $k$ that maximizes this total profit.

## Intuition & Mathematical Observation
Let $S_k$ be the prefix sum of the array up to index $k$ (i.e., $S_k = \sum_{i=1}^{k} A_i$).
The problem states that if we close on day $k$, the total sales $T_k$ is:
$$T_k = \left( \sum_{i=1}^{k-1} A_i \right) + 2 \cdot A_k$$

We can rewrite this expression to simplify the calculation:
$$T_k = \left( \sum_{i=1}^{k-1} A_i + A_k \right) + A_k$$
$$T_k = S_k + A_k$$

Since we need to find the maximum $T_k$ for all $1 \le k \le N$, we can iterate through the array once, maintaining a running prefix sum, and at each step $k$, calculate $S_k + A_k$. We keep track of the maximum value encountered during this iteration. Because $A_i$ can be up to $10^9$ and $N$ up to $3 \cdot 10^5$, the total sum will exceed the capacity of a 32-bit integer, so we must use `long long` in C++.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we perform a single pass through the array of size $N$. The total time complexity is $O(\sum N)$ across all test cases.
- **Space Complexity**: $O(N)$ to store the input array. This can be optimized to $O(1)$ by calculating the prefix sum on the fly, but $O(N)$ is well within the memory limits.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef chooses a day 'k' (1-indexed) to close the shop.
 * Total sales = (Sum of A[1] to A[k-1]) + (2 * A[k])
 * This can be rewritten as: (Sum of all A[1] to A[k]) + A[k]
 * 
 * Let S[k] be the prefix sum of the array A up to index k.
 * Total sales = S[k] + A[k]
 * 
 * We need to find max(S[k] + A[k]) for all 1 <= k <= N.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long current_prefix_sum = 0;
    long long max_sales = -2e18; // Initialize with a very small value

    for (int i = 0; i < n; ++i) {
        current_prefix_sum += a[i];
        // Total sales if we close on day i+1 is (prefix_sum_up_to_i) + a[i]
        long long current_total = current_prefix_sum + a[i];
        if (current_total > max_sales) {
            max_sales = current_total;
        }
    }

    cout << max_sales << "\n";
}

int main() {
    // Fast I/O
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