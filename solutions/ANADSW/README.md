# [Anti Adjacent Swaps (ANADSW)](https://www.codechef.com/problems/ANADSW)

- **Difficulty Rating**: 1306
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of size $N$, we are allowed to swap any two elements $A[i]$ and $A[j]$ if and only if $|i - j| > 1$. We need to determine if it is possible to sort the array in non-decreasing order using any number of these operations.

## Intuition & Mathematical Observation
The core of the problem lies in understanding the reachability of permutations based on the size of $N$:

1.  **$N=1$**: The array is already sorted. Always **YES**.
2.  **$N=2$**: The only possible swap distance is $|1-2|=1$. Since we require $|i-j| > 1$, no swaps are possible. The array is sortable only if it is already sorted.
3.  **$N=3$**: We can only swap indices $(1, 3)$. We cannot swap $(1, 2)$ or $(2, 3)$. This means the middle element $A[2]$ is fixed. We can only swap the first and third elements. We check if the array is sorted initially or if swapping $A[1]$ and $A[3]$ results in a sorted array.
4.  **$N \ge 4$**: With at least 4 elements, we have enough "workspace" to perform any arbitrary swap. To swap two adjacent elements $A[i]$ and $A[i+1]$, we can use an auxiliary index $k$ (where $k \neq i, i+1$) to perform a sequence of swaps:
    *   Swap $(i, k)$
    *   Swap $(i+1, k)$
    *   Swap $(i, k)$
    Because we can perform any arbitrary swap, we can achieve any permutation of the array, including the sorted one. Thus, for $N \ge 4$, the answer is always **YES**.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we perform a simple check for $N=3$ and constant time operations for other cases.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We can swap A[i] and A[j] if |i - j| > 1.
 * 
 * Summary:
 * N=1: YES
 * N=2: Sorted? YES : NO
 * N=3: Sorted? YES : (Swap A1, A3 sorted? YES : NO)
 * N>=4: Always YES (because we can perform any swap).
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (N == 1) {
        cout << "YES" << "\n";
    } else if (N == 2) {
        if (A[0] <= A[1]) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else if (N == 3) {
        // Check if already sorted
        bool sorted = true;
        for (int i = 0; i < N - 1; ++i) if (A[i] > A[i+1]) sorted = false;
        if (sorted) {
            cout << "YES" << "\n";
            return;
        }
        // Check if swapping A[0] and A[2] makes it sorted
        swap(A[0], A[2]);
        sorted = true;
        for (int i = 0; i < N - 1; ++i) if (A[i] > A[i+1]) sorted = false;
        if (sorted) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else {
        // For N >= 4, we can perform any swap, so we can always sort.
        cout << "YES" << "\n";
    }
}

int main() {
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