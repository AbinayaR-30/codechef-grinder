# [Golf (LKDNGOLF)](https://www.codechef.com/problems/LKDNGOLF)

- **Difficulty Rating**: 1256
- **Solved in**: 1 attempt(s)

## Problem Summary
A golf course consists of a straight line of tiles numbered from $0$ to $N+1$. A ball is hit forward, landing on tiles $0, k, 2k, \dots$ until it reaches or exceeds $N+1$. Then, it is hit backward from $N+1$, landing on tiles $(N+1), (N+1)-k, (N+1)-2k, \dots$ until it reaches or goes below $0$. Given the target tile $x$, determine if the ball lands on $x$ during either the forward or the backward journey.

## Intuition & Mathematical Observation
The problem can be broken down into two independent conditions:

1.  **Forward Journey**: The ball lands on tiles $x$ such that $x$ is a multiple of $k$.
    *   Condition: `x % k == 0`
2.  **Backward Journey**: The ball starts at $N+1$ and moves in steps of $k$ downwards. The ball lands on $x$ if the distance between $N+1$ and $x$ is a multiple of $k$.
    *   Condition: `(N + 1 - x) % k == 0`

If either of these conditions is true, the ball lands on tile $x$. Since $N$ can be as large as $10^9$, we must use an $O(1)$ mathematical approach rather than simulating the jumps. Using `long long` ensures we handle the arithmetic safely, although standard integers would suffice for these constraints.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. Total time complexity is $O(T)$ for $T$ test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The hallway has tiles 0 to N+1.
 * Forward journey: The ball lands on tiles {0, k, 2k, ..., m*k} such that m*k <= N+1.
 * This means the ball lands on tile x if x % k == 0.
 * 
 * Backward journey: The ball starts at N+1 and lands on tiles {(N+1), (N+1)-k, (N+1)-2k, ...}.
 * This means the ball lands on tile x if (N+1 - x) is a multiple of k.
 * Mathematically, (N+1 - x) % k == 0.
 */

void solve() {
    long long N, x, k;
    if (!(cin >> N >> x >> k)) return;

    // Forward check: x is a multiple of k
    bool forward = (x % k == 0);
    
    // Backward check: (N + 1 - x) is a multiple of k
    bool backward = ((N + 1 - x) % k == 0);

    if (forward || backward) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```