# [Gem Bundles (GEMBUND)](https://www.codechef.com/problems/GEMBUND)

- **Difficulty Rating**: 603
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $R$ red gems, $B$ blue gems, and $G$ green gems. You can sell gems individually for 3 coins each, or you can combine one of each color (1 Red, 1 Blue, 1 Green) into a bundle that sells for 10 coins. The goal is to maximize the total number of coins earned.

## Intuition & Mathematical Observation
Let $k$ be the number of bundles created. Since a bundle requires one of each color, $k$ can range from $0$ to $\min(R, B, G)$.

The total profit formula is:
$$\text{Total Coins} = (k \times 10) + (\text{Remaining Gems} \times 3)$$

Substituting the remaining gems:
$$\text{Remaining Gems} = (R - k) + (B - k) + (G - k) = (R + B + G) - 3k$$
$$\text{Total Coins} = 10k + 3((R + B + G) - 3k)$$
$$\text{Total Coins} = 10k + 3(R + B + G) - 9k$$
$$\text{Total Coins} = k + 3(R + B + G)$$

Since $3(R + B + G)$ is a constant for any given input, we maximize the total coins by maximizing $k$. Therefore, we should create as many bundles as possible, which is $k = \min(R, B, G)$.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case is solved in $O(1)$ time.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the gem counts and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have R red, B blue, and G green gems.
 * Each gem sells for 3 coins individually.
 * A bundle of (1R, 1B, 1G) sells for 10 coins.
 * 
 * Let k be the number of bundles we make.
 * k can range from 0 to min(R, B, G).
 * If we make k bundles, we use k of each gem.
 * Remaining gems: (R-k) red, (B-k) blue, (G-k) green.
 * Total coins = (k * 10) + ((R-k) + (B-k) + (G-k)) * 3
 *             = 10k + 3(R + B + G - 3k)
 *             = 10k + 3(R + B + G) - 9k
 *             = k + 3(R + B + G)
 * 
 * To maximize this, we need to maximize k.
 * Since k is the number of bundles, the maximum k is min(R, B, G).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long r, b, g;
        cin >> r >> b >> g;

        // Maximum number of bundles possible
        long long k = min({r, b, g});

        // Calculate max coins
        // Formula: k * 10 + (remaining gems) * 3
        long long total_gems = r + b + g;
        long long ans = (k * 10) + (total_gems - 3 * k) * 3;

        cout << ans << "\n";
    }

    return 0;
}
```