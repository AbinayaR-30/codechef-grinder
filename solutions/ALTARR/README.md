# [Alternating Array (ALTARR)](https://www.codechef.com/problems/ALTARR)

- **Difficulty Rating**: 787
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we want to make the array "alternating." An array is considered alternating if the parity (even or odd) of adjacent elements is always different. We are allowed to change any element in the array. The goal is to find the minimum number of changes required to make the array alternating.

## Intuition & Mathematical Observation
An alternating array must follow one of two possible parity patterns:
1. **Pattern 1**: Starts with an Odd number (Odd, Even, Odd, Even, ...).
2. **Pattern 2**: Starts with an Even number (Even, Odd, Even, Odd, ...).

For any given index $i$:
- In **Pattern 1**, the expected parity is `1` if $i$ is even, and `0` if $i$ is odd.
- In **Pattern 2**, the expected parity is `0` if $i$ is even, and `1` if $i$ is odd.

By iterating through the array once, we can calculate the cost (number of changes) required to transform the original array into Pattern 1 (`count1`) and Pattern 2 (`count2`). Since the array must eventually follow one of these two patterns, the final answer is simply the minimum of these two counts: $\min(\text{count1}, \text{count2})$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to compare parities.
- **Space Complexity**: $O(N)$ to store the input array. This can be optimized to $O(1)$ if we process the input elements on the fly without storing them.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An array is alternating if the parity of A[i] is different from A[i+1].
 * There are only two possible patterns for an alternating array of length N:
 * Pattern 1: Odd, Even, Odd, Even, ...
 * Pattern 2: Even, Odd, Even, Odd, ...
 * 
 * For each pattern, we count how many elements in the original array do not 
 * match the required parity. The minimum of these two counts is the answer.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // count1: cost to make it Odd, Even, Odd, Even...
    // count2: cost to make it Even, Odd, Even, Odd...
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < N; ++i) {
        int parity = A[i] % 2; // 1 for odd, 0 for even
        
        // Pattern 1: index i should have parity (i % 2 == 0 ? 1 : 0)
        int expected1 = (i % 2 == 0) ? 1 : 0;
        if (parity != expected1) {
            count1++;
        }

        // Pattern 2: index i should have parity (i % 2 == 0 ? 0 : 1)
        int expected2 = (i % 2 == 0) ? 0 : 1;
        if (parity != expected2) {
            count2++;
        }
    }

    cout << min(count1, count2) << "\n";
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