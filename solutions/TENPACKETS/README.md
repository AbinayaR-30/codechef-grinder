# [Buy Ten Packets (TENPACKETS)](https://www.codechef.com/problems/TENPACKETS)

- **Difficulty Rating**: 669
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef needs to purchase exactly 10 packets of noodles. He has two options available:
1. Buy a pack of 2 packets for $X$ rupees.
2. Buy a pack of 4 packets for $Y$ rupees.

The goal is to find the minimum cost to obtain exactly 10 packets, given the constraint that $Y \le 2X$ (meaning a 4-pack is always cheaper or equal to buying two 2-packs).

## Intuition & Mathematical Observation
To get 10 packets, we can represent the total as $10 = 4a + 2b$, where $a$ is the number of 4-packs and $b$ is the number of 2-packs. The possible non-negative integer combinations $(a, b)$ are:
1. $(0, 5) \implies \text{Cost} = 5X$
2. $(1, 3) \implies \text{Cost} = Y + 3X$
3. $(2, 1) \implies \text{Cost} = 2Y + X$

We are given the constraint $Y \le 2X$. Let's compare these costs:
*   **Comparing (0, 5) and (1, 3):** $Y + 3X$ vs $5X$. Since $Y \le 2X$, then $Y + 3X \le 2X + 3X = 5X$. Thus, $(1, 3)$ is always better than or equal to $(0, 5)$.
*   **Comparing (1, 3) and (2, 1):** $2Y + X$ vs $Y + 3X$. Subtracting $Y + X$ from both sides, we compare $Y$ vs $2X$. Since $Y \le 2X$, it follows that $2Y + X \le Y + 3X$.

Therefore, the combination $(2, 1)$—buying two 4-packs and one 2-pack—is mathematically guaranteed to be the most cost-effective strategy.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs 10 packets.
 * Options:
 * - 2 packets for X
 * - 4 packets for Y
 * 
 * We need to form 10 using combinations of 2 and 4.
 * Possible combinations (number of 4-packs, number of 2-packs):
 * 1. (0, 5): 0 * Y + 5 * X = 5X
 * 2. (1, 3): 1 * Y + 3 * X = Y + 3X
 * 3. (2, 1): 2 * Y + 1 * X = 2Y + X
 * 
 * Since Y <= 2X, the cost of 4 packets (Y) is always less than or equal to 
 * the cost of two 2-packs (2X). Therefore, we should prioritize using 
 * the 4-pack as much as possible to minimize the cost.
 * 
 * Comparing the combinations:
 * - 5X vs Y + 3X: 
 *   Since Y <= 2X, Y + 3X <= 2X + 3X = 5X. So (1, 3) is always <= (0, 5).
 * - Y + 3X vs 2Y + X:
 *   Since Y <= 2X, 2Y + X <= Y + 2X + X = Y + 3X. So (2, 1) is always <= (1, 3).
 * 
 * Thus, the minimum cost is always 2Y + X.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Based on the logic derived, the optimal strategy is to buy 
        // two 4-packs and one 2-pack to reach 10 packets.
        long long min_cost = 2 * y + x;
        
        cout << min_cost << "\n";
    }

    return 0;
}
```