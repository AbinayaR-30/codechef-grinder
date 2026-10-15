# [Mirror Swap (MRSWAP)](https://www.codechef.com/problems/MRSWAP)

- **Difficulty Rating**: 667
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of size $2N$, we are allowed to perform a swap between the element at index $i$ and its "mirror" index $2N + 1 - i$ (using 1-based indexing). The goal is to maximize the sum of the elements in the first half of the array (indices $1$ to $N$) after performing any number of these swaps.

## Intuition & Mathematical Observation
The problem states that for every index $i$ in the first half ($1 \le i \le N$), there is a corresponding mirror index $j = 2N + 1 - i$ in the second half. Since we can swap $A[i]$ and $A[j]$ independently for each pair, we have two choices for the value at index $i$: either $A[i]$ or $A[j]$.

To maximize the sum of the first $N$ elements, we simply need to make the optimal choice for each pair independently:
- For each $i$ from $0$ to $N-1$ (in 0-based indexing), compare $A[i]$ and $A[2N - 1 - i]$.
- Select the larger of the two values to contribute to the total sum.
- Summing these maximums for all $N$ pairs will yield the global maximum sum for the first half of the array.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the first half of the array exactly once.
- **Space Complexity**: $O(N)$ to store the input array of size $2N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array of size 2N.
 * We can swap A[i] with A[2N + 1 - i] (1-indexed).
 * This means for each pair (A[i], A[2N + 1 - i]), we can choose which 
 * element goes into the first half (indices 1 to N) and which goes into 
 * the second half (indices N+1 to 2N).
 * 
 * To maximize the sum of the first N elements, for each pair (A[i], A[2N + 1 - i])
 * where 1 <= i <= N, we should pick the larger of the two values to be in the 
 * first half.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        cin >> A[i];
    }

    long long max_sum = 0;
    // We iterate through the first N elements and compare them with their mirror counterparts.
    // The mirror of A[i] (0-indexed) is A[2N - 1 - i].
    for (int i = 0; i < N; ++i) {
        max_sum += max(A[i], A[2 * N - 1 - i]);
    }

    cout << max_sum << "\n";
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