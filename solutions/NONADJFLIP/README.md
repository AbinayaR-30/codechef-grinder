# [Non Adjacent Flips (NONADJFLIP)](https://www.codechef.com/problems/NONADJFLIP)

- **Difficulty Rating**: 1128
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we want to transform it into a string consisting only of '0's. In one operation, we can choose a subset of indices such that no two chosen indices are adjacent (i.e., no two indices $i$ and $j$ satisfy $|i - j| = 1$) and flip the bits at these indices (changing '0' to '1' and '1' to '0'). We need to find the minimum number of operations required to make the entire string '0'.

## Intuition & Mathematical Observation
To solve this, we analyze the state of the string based on the distribution of '1's:

1.  **Case 0: No '1's present.**
    If the string is already all '0's, we need **0** operations.
2.  **Case 1: No adjacent '1's.**
    If there are '1's present but no two '1's are adjacent, we can simply select all indices containing a '1' in a single operation. Since no two '1's are adjacent, this set of indices satisfies the problem constraint. Thus, we need **1** operation.
3.  **Case 2: Adjacent '1's present.**
    If there is at least one pair of adjacent '1's, we cannot flip them all at once. However, we can always partition the set of '1's into two subsets such that each subset contains no adjacent '1's (for example, by picking all even-indexed '1's for the first operation and all odd-indexed '1's for the second). Therefore, **2** operations are always sufficient to clear the string.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We perform a single linear scan to check for the existence of '1's and adjacent '1's.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. If the string is already all '0's, 0 operations are needed.
 * 2. If there are no two '1's that are adjacent, we can flip all '1's in a single operation.
 * 3. If there are adjacent '1's, we cannot flip them in the same operation.
 *    We can always split the '1's into two sets such that no two '1's in the same set are adjacent.
 *    Thus, 2 operations are sufficient.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    bool has_ones = false;
    bool has_adjacent_ones = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            has_ones = true;
            if (i > 0 && S[i - 1] == '1') {
                has_adjacent_ones = true;
            }
        }
    }

    if (!has_ones) {
        cout << 0 << "\n";
    } else if (has_adjacent_ones) {
        cout << 2 << "\n";
    } else {
        cout << 1 << "\n";
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