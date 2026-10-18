# [International Gym Day (GYMDAY)](https://www.codechef.com/problems/GYMDAY)

- **Difficulty Rating**: 1201
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to buy a gym membership that costs $X$ coins. He currently has $Y$ coins. For every trial session he attends, he spends 1 coin, but he receives a discount of $D\%$ on the original price of the membership. We need to find the minimum number of trial sessions $n$ (where $0 \le n \le Y$) such that Chef can afford the membership with his remaining budget. If it is impossible to afford the membership even after spending all his coins on sessions, output -1.

## Intuition & Mathematical Observation
The condition for Chef to afford the membership after $n$ sessions is:
$$\text{Remaining Budget} \ge \text{Discounted Price}$$

1. **Remaining Budget**: After $n$ sessions, Chef has $Y - n$ coins left.
2. **Discounted Price**: The original price $X$ is reduced by $n \times D\%$. The new price is $X \times \frac{100 - (n \times D)}{100}$.

The inequality becomes:
$$(Y - n) \ge X \times \frac{100 - n \times D}{100}$$

To avoid floating-point precision errors, we multiply both sides by 100:
$$(Y - n) \times 100 \ge X \times (100 - n \times D)$$

Since the constraints on $Y$ are small, we can simply iterate through all possible values of $n$ from $0$ to $Y$. The first $n$ that satisfies the inequality is our answer. If the loop completes without finding such an $n$, it is impossible to afford the membership.

## Complexity Analysis
- **Time Complexity**: $O(Y)$ per test case. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(1)$, as we only use a few variables for calculation.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has budget Y and membership cost X.
 * Each trial session costs 1 coin.
 * After n trial sessions:
 * - Remaining budget: Y - n
 * - Discount: n * D %
 * - Membership cost: X * (100 - n * D) / 100
 * 
 * We need to find the minimum n >= 0 such that:
 * (Y - n) >= X * (100 - n * D) / 100
 * 
 * Constraints are small enough to iterate n from 0 to Y.
 * Condition: (Y - n) * 100 >= X * (100 - n * D)
 */

void solve() {
    int D, X, Y;
    cin >> D >> X >> Y;

    // Iterate through possible number of sessions from 0 to Y
    for (int n = 0; n <= Y; ++n) {
        // Remaining budget after n sessions: Y - n
        // Discounted price: X * (100 - n * D) / 100
        // Use cross-multiplication to avoid floating point issues:
        // (Y - n) * 100 >= X * (100 - n * D)
        
        long long remaining_budget = (long long)(Y - n) * 100;
        long long discounted_price = (long long)X * (100 - n * D);
        
        if (remaining_budget >= discounted_price) {
            cout << n << "\n";
            return;
        }
    }

    // If no n works
    cout << -1 << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```