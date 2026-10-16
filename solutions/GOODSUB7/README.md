# [Good Subsequence (GOODSUB7)](https://www.codechef.com/problems/GOODSUB7)

- **Difficulty Rating**: 899
- **Solved in**: 1 attempt(s)

## Problem Summary
The goal is to find the length of the longest "good" subsequence of a given array $A$. A subsequence is defined as "good" if every pair of adjacent elements in the subsequence has different parities (i.e., one is even and the other is odd).

## Intuition & Mathematical Observation
To maximize the length of the subsequence, we should greedily pick elements that satisfy the alternating parity condition. 

1. **Greedy Choice**: We iterate through the array from left to right. 
2. **State Tracking**: We maintain the parity of the last element added to our subsequence. 
3. **Decision Rule**: 
   - If we haven't picked any element yet, we pick the first one.
   - For every subsequent element, if its parity is different from the parity of the last element added, we include it in our subsequence and update the "last parity" tracker.
   - If the parity is the same, we skip the element because picking it would violate the "good" condition.

This greedy approach works because picking an element with a different parity as early as possible never restricts our ability to pick future elements; it only extends the current valid sequence.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We perform a single pass through the input array.
- **Space Complexity**: $O(1)$ auxiliary space (excluding the input storage), as we only store a few integer variables to track the count and the last parity.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A sequence is "good" if the parity of adjacent elements is different.
 * This means the sequence must alternate between odd and even numbers.
 * 
 * Greedy Strategy:
 * Iterate through the array and keep track of the parity of the last element 
 * added to our subsequence. If the current element has a different parity 
 * than the last added element, we include it.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (N == 0) {
        cout << 0 << "\n";
        return;
    }

    int count = 0;
    int last_parity = -1; // -1 indicates no element picked yet

    for (int i = 0; i < N; ++i) {
        int current_parity = A[i] % 2;
        // If it's the first element or the parity alternates, include it
        if (last_parity == -1 || current_parity != last_parity) {
            count++;
            last_parity = current_parity;
        }
    }

    cout << count << "\n";
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