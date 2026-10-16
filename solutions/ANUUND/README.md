# [Ups and Downs (ANUUND)](https://www.codechef.com/problems/PRACTICE/problems/ANUUND)

- **Difficulty Rating**: 1198
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, the goal is to rearrange the elements such that they satisfy the "wiggle" condition:
$A[0] \le A[1] \ge A[2] \le A[3] \ge A[4] \dots$
Essentially, the elements at even indices must be less than or equal to their immediate neighbors, and elements at odd indices must be greater than or equal to their immediate neighbors.

## Intuition & Mathematical Observation
The problem can be solved efficiently by leveraging the properties of a sorted array. 

1. **Sorting**: First, sort the array in non-decreasing order: $A[0] \le A[1] \le A[2] \le A[3] \le A[4] \dots$
2. **Swapping Strategy**: To satisfy the condition $A[0] \le A[1] \ge A[2] \le A[3] \ge A[4] \dots$, we observe that the sorted array already satisfies the "less than" parts ($A[0] \le A[1]$, $A[2] \le A[3]$, etc.). 
3. **The Fix**: By swapping every adjacent pair $(A[i], A[i+1])$ where $i$ is odd (i.e., swapping $(A[1], A[2]), (A[3], A[4]), \dots$), we force the "greater than" condition.
    - After sorting: $A[0] \le A[1] \le A[2] \le A[3] \le A[4]$
    - After swapping $A[1]$ and $A[2]$: $A[0] \le A[2] \le A[1] \le A[3] \le A[4]$
    - Because $A[1] \le A[2]$ was true originally, after the swap, $A[1] \ge A[2]$ is guaranteed.
    - This pattern propagates through the array, ensuring the alternating $\le$ and $\ge$ conditions are met for all indices.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$, dominated by the sorting step. The subsequent linear scan to swap elements takes $O(N)$.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to satisfy: A[0] <= A[1] >= A[2] <= A[3] >= A[4] ...
 * 
 * Strategy:
 * 1. Sort the array in non-decreasing order.
 * 2. Swap adjacent pairs (A[i], A[i+1]) for all odd i.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Step 1: Sort the array
    sort(a.begin(), a.end());

    // Step 2: Swap adjacent elements starting from index 1
    // This ensures A[i] >= A[i+1] for odd i
    for (int i = 1; i + 1 < n; i += 2) {
        swap(a[i], a[i + 1]);
    }

    // Output the result
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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