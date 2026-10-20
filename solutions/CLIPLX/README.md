# [IPL and RCB (CLIPLX)](https://www.codechef.com/problems/CLIPLX)

- **Difficulty Rating**: 1167
- **Solved in**: 1 attempt(s)

## Problem Summary
RCB needs to earn at least $X$ points from $Y$ matches. A win grants 2 points, a tie grants 1 point, and a loss grants 0 points. We need to find the **minimum number of wins** required to achieve at least $X$ points.

## Intuition & Mathematical Observation
Let $w$ be the number of wins, $t$ be the number of ties, and $l$ be the number of losses. We are given:
1. $w + t + l = Y$ (Total matches)
2. $2w + t = X$ (Total points)

We want to minimize $w$. From the second equation, $t = X - 2w$. 
Since the number of ties $t$ cannot be negative, $2w \le X$. 
More importantly, since we have a limited number of matches $Y$, we know that $w + t \le Y$ (because losses $l \ge 0$).

Substituting $t = X - 2w$ into the inequality $w + t \le Y$:
$$w + (X - 2w) \le Y$$
$$X - w \le Y$$
$$w \ge X - Y$$

Since $w$ cannot be negative, the minimum number of wins required is $\max(0, X - Y)$. 
- If $X \le Y$, we can achieve the points using only ties (or a mix of ties and losses), so 0 wins are needed.
- If $X > Y$, we must win at least $X - Y$ matches to make up for the points that cannot be covered by ties alone.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic operation. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * RCB needs X points from Y matches.
 * Win = 2 points, Tie = 1 point, Loss = 0 points.
 * We want to minimize wins (w).
 * The minimum wins required is max(0, X - Y).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long X, Y;
        cin >> X >> Y;

        // If X <= Y, we can get all points by tying matches, so 0 wins needed.
        // If X > Y, we need at least (X - Y) wins to cover the deficit.
        long long ans = max(0LL, X - Y);
        cout << ans << "\n";
    }

    return 0;
}
```