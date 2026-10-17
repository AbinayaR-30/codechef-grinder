# [Convert to permutation (PERMUTATION)](https://www.codechef.com/problems/PERMUTATION)

- **Difficulty Rating**: 1197
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we want to transform it into a permutation of $\{1, 2, \dots, N\}$. The only allowed operation is to increase any element by 1. We need to find the minimum number of operations required to achieve this, or determine if it is impossible.

## Intuition & Mathematical Observation
1. **Sorting is Key**: Since we want to reach the set $\{1, 2, \dots, N\}$, the most efficient way to map our current values to the target values is to sort the array $A$ in non-decreasing order. By sorting, we ensure that the smallest element in $A$ is compared against $1$, the second smallest against $2$, and so on.
2. **Constraint Check**: The problem states we can only *increase* elements. Therefore, for any element $A[i]$ (after sorting), if $A[i] > (i + 1)$, it is impossible to reach the target value $(i + 1)$ because we cannot decrease the value. In this case, we output `-1`.
3. **Greedy Calculation**: If $A[i] \le (i + 1)$ for all $i$, the minimum number of operations to make $A[i]$ equal to $(i + 1)$ is simply $(i + 1) - A[i]$. Summing these differences for all $i$ gives the total minimum operations required.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan takes $O(N)$, resulting in an overall complexity of $O(N \log N)$ per test case.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N. We can only increase elements.
 * We want to reach a permutation of {1, 2, ..., N}.
 * 
 * Strategy:
 * 1. Sort the array A in non-decreasing order.
 * 2. To minimize operations, we should map the smallest elements of A to the 
 *    smallest elements of the target permutation {1, 2, ..., N}.
 * 3. After sorting, if A[i] > (i + 1), it is impossible to reach the target 
 *    permutation because we can only increase elements. Thus, return -1.
 * 4. Otherwise, the cost to transform A[i] to (i + 1) is (i + 1) - A[i].
 * 5. Sum these costs for all i from 0 to N-1.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array to greedily match smallest available values
    sort(A.begin(), A.end());

    long long total_ops = 0;
    for (int i = 0; i < N; ++i) {
        // The target value for the i-th smallest element is (i + 1)
        long long target = i + 1;
        
        // If the current element is already greater than the target,
        // we cannot decrease it, so it's impossible.
        if (A[i] > target) {
            cout << -1 << "\n";
            return;
        }
        
        // Add the difference to total operations
        total_ops += (target - A[i]);
    }

    cout << total_ops << "\n";
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