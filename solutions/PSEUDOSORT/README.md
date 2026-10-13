# [Pseudo Sorted Array (PSEUDOSORT)](https://www.codechef.com/problems/PSEUDOSORT)

- **Difficulty Rating**: 1067
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine if an array can be sorted in non-decreasing order by performing **at most one** swap of adjacent elements. An array that is already sorted is considered "pseudo-sorted."

## Intuition & Mathematical Observation
1. **Already Sorted**: If the array is already sorted, the condition is satisfied immediately.
2. **Identifying the Swap**: If the array is not sorted, there must be at least one index $i$ such that $A[i] > A[i+1]$. To fix the array with exactly one swap, we must target the first occurrence of such an inversion.
3. **The Strategy**:
   - Traverse the array to find the first index $i$ where $A[i] > A[i+1]$.
   - If no such index exists, the array is already sorted.
   - If such an index exists, swap $A[i]$ and $A[i+1]$.
   - After the swap, perform a full check to verify if the array is now sorted. If it is, the answer is "YES"; otherwise, it is "NO".
4. **Why only the first inversion?** If there are multiple inversions, swapping any pair other than the first one (or swapping a pair that doesn't resolve the first inversion) will not result in a sorted array. Thus, checking the first inversion is sufficient.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of elements in the array. We perform one pass to find the inversion and one pass to verify the sorted order.
- **Space Complexity**: $O(N)$ to store the array elements.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An array is pseudo-sorted if it is already sorted or can be sorted by 
 * swapping exactly one adjacent pair (A[i], A[i+1]).
 * 
 * Strategy:
 * 1. Find the first index 'i' where A[i] > A[i+1].
 * 2. If no such index exists, the array is already sorted -> YES.
 * 3. If such an index exists, perform the swap A[i] and A[i+1].
 * 4. After the swap, check if the entire array is sorted.
 * 5. If it is sorted, output YES, otherwise NO.
 */

bool isSorted(const vector<long long>& a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Find the first inversion
    int first_inversion = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            first_inversion = i;
            break;
        }
    }

    // If no inversion, it's already sorted
    if (first_inversion == -1) {
        cout << "YES" << "\n";
        return;
    }

    // Perform the swap at the first inversion point
    swap(a[first_inversion], a[first_inversion + 1]);

    // Check if the array is now sorted
    if (isSorted(a, n)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```