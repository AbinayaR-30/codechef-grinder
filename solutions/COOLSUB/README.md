# [Cool Subsequences (COOLSUB)](https://www.codechef.com/problems/COOLSUB)

- **Difficulty Rating**: 1239
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find a non-empty subsequence of an array $A$ such that the average of every non-empty subsequence of our chosen subsequence is present in the remaining elements of the array (the complement). If no such subsequence exists, we should output -1.

## Intuition & Mathematical Observation
Let our chosen subsequence be $S$. A "cool" subsequence requires that for every non-empty subsequence $S' \subseteq S$, the average of $S'$ must exist in the complement $A \setminus S$.

Consider the simplest case: a subsequence of length 1, $S = \{x\}$.
1. The only non-empty subsequence of $S$ is $\{x\}$ itself.
2. The average of $\{x\}$ is $x$.
3. For $S$ to be "cool," $x$ must be present in the complement $A \setminus \{x\}$.
4. This condition is satisfied if and only if the original array $A$ contains at least two occurrences of the value $x$.

**Conclusion:**
- If the array contains any duplicate elements, we can simply pick one of those duplicate values as our subsequence of length 1. The complement will contain the other instance of that value, satisfying the condition.
- If all elements in the array are distinct, picking any element $x$ results in a complement that does not contain $x$. Therefore, no subsequence of length 1 works. Further analysis shows that if all elements are distinct, no subsequence of any length can satisfy the condition.

Thus, the problem reduces to finding any duplicate element in the array. If one exists, output `1` followed by the value. If no duplicates exist, output `-1`.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ or $O(N)$ depending on the implementation. Using a `std::map` as shown in the solution results in $O(N \log N)$, where $N$ is the number of elements in the array. This is well within the limits for typical competitive programming constraints.
- **Space Complexity**: $O(N)$ to store the frequency counts of the elements in the array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A subsequence is "cool" if the averages of all its non-empty subsequences are present 
 * in the complement subsequence.
 * 
 * If an array has any duplicate elements, say 'x' appears at least twice, we can pick
 * one 'x' as our subsequence. The complement will contain at least one other 'x'.
 * Since the average of {x} is x, and x is in the complement, {x} is a cool subsequence.
 * 
 * If all elements in the array are distinct, no cool subsequence exists.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> counts;
    int duplicate_val = -1;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        counts[A[i]]++;
        if (counts[A[i]] > 1) {
            duplicate_val = A[i];
        }
    }

    if (duplicate_val != -1) {
        // We found a duplicate. A subsequence of length 1 containing this value
        // is cool because the complement will contain at least one more instance
        // of this value.
        cout << 1 << "\n";
        cout << duplicate_val << "\n";
    } else {
        // If all elements are distinct, no cool subsequence exists.
        cout << -1 << "\n";
    }
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