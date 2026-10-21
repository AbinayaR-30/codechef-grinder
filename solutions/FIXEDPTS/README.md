# [Fixed Points (FIXEDPTS)](https://www.codechef.com/problems/FIXEDPTS)

- **Difficulty Rating**: 884
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$ (the length of a permutation) and an integer $K$, determine if it is possible to construct a permutation $P$ of length $N$ such that there are exactly $K$ fixed points. A fixed point is defined as an index $i$ such that $P[i] = i$.

## Intuition & Mathematical Observation
To solve this, we consider the elements that are **not** fixed points. Let $M = N - K$ be the number of elements that must not be fixed points. These $M$ elements must form a **derangement** (a permutation where no element appears in its original position).

1. **Case $M = 0$**: If $N = K$, all elements are fixed points. This is simply the identity permutation, which is always valid.
2. **Case $M = 1$**: If $N - K = 1$, we have exactly one element left that must be placed in a position other than its own. However, in a permutation of length 1, the only available position is its own. Thus, it is **impossible** to have exactly one non-fixed point.
3. **Case $M \ge 2$**: If we have 2 or more elements, we can always arrange them such that none of them are in their original positions (e.g., by swapping them). Therefore, a derangement is always possible for any $M \ge 2$.

**Conclusion**: A valid permutation exists if and only if $N - K \neq 1$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a simple subtraction and comparison. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to determine if a permutation of length N can have exactly K fixed points.
 * 
 * 1. If we choose K indices to be fixed points (P[i] = i), we are left with (N - K) 
 *    elements that must be deranged (no element i is at position i).
 * 2. A derangement of size M exists if and only if M != 1.
 *    - If M = 0, there is 1 derangement (the empty set).
 *    - If M = 1, there are 0 derangements (impossible to have 0 fixed points in a set of 1).
 *    - If M >= 2, there is always at least one derangement.
 * 
 * Therefore, the condition is:
 * - We can always pick K fixed points.
 * - The remaining (N - K) elements must be able to form a derangement.
 * - This is possible if (N - K) != 1.
 * - So, if N - K == 1, it is impossible. Otherwise, it is possible.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        // If N - K == 1, we are left with exactly one element that cannot be 
        // a fixed point, which is impossible.
        if (n - k == 1) {
            cout << "No" << "\n";
        } else {
            // For all other cases (N-K == 0 or N-K >= 2), a valid permutation exists.
            // N-K == 0: All elements are fixed points (Identity permutation).
            // N-K >= 2: We can swap elements to ensure no fixed points in the remaining set.
            cout << "Yes" << "\n";
        }
    }

    return 0;
}
```