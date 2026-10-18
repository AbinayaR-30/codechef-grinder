# [Maximum Score (MAXSCORE7)](https://www.codechef.com/problems/MAXSCORE7)

- **Difficulty Rating**: 1202
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a binary array of size $N$ consisting only of $0$s and $1$s, we want to maximize our score. A score increases by $1$ whenever we remove a pair of adjacent elements $(0, 1)$ or $(1, 0)$. We need to determine the maximum possible score achievable by repeatedly performing this operation.

## Intuition & Mathematical Observation
The core observation is that every operation consumes exactly one $0$ and one $1$. 
- If we have $C_0$ zeros and $C_1$ ones, each operation reduces both counts by $1$.
- We can continue performing this operation as long as there is at least one $0$ and at least one $1$ remaining in the array.
- Even if the $0$s and $1$s are not initially adjacent, the problem structure implies that we can always perform operations until one of the two types of digits is completely exhausted.
- Therefore, the total number of operations (and thus the maximum score) is simply limited by the count of the digit that appears less frequently.

The result is mathematically defined as:
$$\text{Max Score} = \min(\text{count of } 0\text{s}, \text{count of } 1\text{s})$$

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array exactly once to count the zeros and ones.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the counts, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The score increases by 1 only when we remove a pair (0, 1) or (1, 0).
 * Each such operation consumes one 0 and one 1.
 * Since we can always bring a 0 and a 1 together as long as both exist 
 * (by removing other pairs or simply finding an adjacent pair), 
 * the maximum number of such operations is min(count of 0s, count of 1s).
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val == 0) {
            c0++;
        } else {
            c1++;
        }
    }
    // The maximum score is the number of pairs of (0, 1) we can form.
    cout << min(c0, c1) << "\n";
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```