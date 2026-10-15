# [Unequal Shuffle (UNQSHF)](https://www.codechef.com/problems/UNQSHF)

- **Difficulty Rating**: 726
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two strings $A$ and $B$ of length $N$ consisting only of characters 'a' and 'b', determine if it is possible to shuffle both strings independently such that for every index $i$ ($0 \le i < N$), $A[i] \neq B[i]$.

## Intuition & Mathematical Observation
To satisfy the condition $A[i] \neq B[i]$ for all $i$, we must ensure that:
1. Whenever $A[i] = \text{'a'}$, $B[i]$ must be $\text{'b'}$.
2. Whenever $A[i] = \text{'b'}$, $B[i]$ must be $\text{'a'}$.

Let $countA_a$ be the number of 'a's in $A$ and $countB_a$ be the number of 'a's in $B$.
- The number of 'b's in $A$ is $N - countA_a$.
- The number of 'b's in $B$ is $N - countB_a$.

For the condition to hold, every 'a' in $A$ must be paired with a 'b' in $B$. Thus, the number of 'a's in $A$ must equal the number of 'b's in $B$:
$$countA_a = N - countB_a$$
Rearranging this gives:
$$countA_a + countB_a = N$$

If this condition is met, we can always arrange the strings such that every 'a' in $A$ aligns with a 'b' in $B$, and every 'b' in $A$ aligns with an 'a' in $B$. If the sum does not equal $N$, it is impossible to satisfy the condition.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the strings, as we iterate through both strings once to count the occurrences of 'a'.
- **Space Complexity**: $O(N)$ to store the input strings (or $O(1)$ if processing character by character).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To satisfy A[i] != B[i] for all i, every 'a' in A must be matched with a 'b' in B,
 * and every 'b' in A must be matched with an 'a' in B.
 * This leads to the condition: countA_a == countB_b.
 * Since countB_b = N - countB_a, the condition becomes countA_a == N - countB_a,
 * or simply countA_a + countB_a == N.
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    int countA_a = 0;
    for (char c : A) if (c == 'a') countA_a++;

    int countB_a = 0;
    for (char c : B) if (c == 'a') countB_a++;

    if (countA_a + countB_a == N) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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