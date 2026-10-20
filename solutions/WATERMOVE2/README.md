# [Water Moving (Max) (WATERMOVE2)](https://www.codechef.com/problems/WATERMOVE2)

- **Difficulty Rating**: 934
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ cups, each containing a certain amount of water $A_i$. You are allowed to perform exactly $K$ operations. In each operation, you choose two cups $i$ and $j$ and move all the water from cup $i$ into cup $j$. The goal is to maximize the amount of water in a single cup after exactly $K$ operations.

## Intuition & Mathematical Observation
To maximize the water in a single cup, we want to aggregate as much water as possible into one target cup. 

1. **Merging Strategy**: Each operation allows us to combine the contents of one cup into another. To maximize the contents of one cup, we should pick the cup that already has the most water and merge the next $K$ largest cups into it.
2. **Constraint $K < N$**: If we have fewer operations than the number of cups, we can pick the largest cup and add the contents of the $K$ next largest cups to it. This uses exactly $K$ operations and results in a sum of the $K+1$ largest values.
3. **Constraint $K \ge N$**: If we have enough operations to merge all cups into one, we can simply combine everything. Once all water is in one cup, any remaining operations can be performed by moving "zero" water from an empty cup to the target cup, effectively wasting the extra operations without changing the total sum. Thus, if $K \ge N-1$, the answer is simply the sum of all water in all cups.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case due to the sorting of the array $A$. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(N)$ to store the amounts of water in the $N$ cups.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N cups with amounts A_i.
 * In one operation, we move all water from cup i to cup j.
 * We must perform exactly K operations.
 * 
 * Strategy:
 * 1. If K >= N-1, we can merge all cups into one. The result is the total sum.
 * 2. If K < N-1, we pick the largest cup and merge the K largest remaining cups into it.
 *    This results in the sum of the (K+1) largest elements.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }

    // If we can perform enough operations to merge all cups (N-1 operations needed)
    if (K >= N - 1) {
        cout << total_sum << "\n";
    } else {
        // Sort descending to pick the largest elements
        sort(A.rbegin(), A.rend());
        long long max_val = A[0];
        // Merge the next K largest cups into the largest one
        for (int i = 1; i <= K; ++i) {
            max_val += A[i];
        }
        cout << max_val << "\n";
    }
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