# [Three Friends (THREEFR)](https://www.codechef.com/problems/THREEFR)

- **Difficulty Rating**: 1074
- **Solved in**: 1 attempt(s)

## Problem Summary
Three friends have amounts of money $A, B,$ and $C$. We are given three values $X, Y,$ and $Z$, which represent the absolute differences between the amounts: $X = |A - B|$, $Y = |B - C|$, and $Z = |C - A|$. We need to determine if it is possible for these three friends to have amounts $A, B,$ and $C$ that satisfy these absolute differences simultaneously.

## Intuition & Mathematical Observation
Let the differences be $x = A - B$, $y = B - C$, and $z = C - A$. 
By summing these equations, we get:
$$(A - B) + (B - C) + (C - A) = x + y + z = 0$$

Since we are given the absolute values $X = |x|, Y = |y|, Z = |z|$, the condition $x + y + z = 0$ implies that there must exist some combination of signs $s_1, s_2, s_3 \in \{1, -1\}$ such that:
$$s_1 X + s_2 Y + s_3 Z = 0$$

By rearranging this equation, we can see that the condition is satisfied if any one of the values is equal to the sum of the other two. For example, if $s_1=1, s_2=1, s_3=-1$, then $X + Y - Z = 0$, which simplifies to $X + Y = Z$. 

Checking all sign combinations leads to the following sufficient conditions:
1. $X + Y = Z$
2. $X + Z = Y$
3. $Y + Z = X$

If any of these hold, the friends can have amounts that satisfy the given differences.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of arithmetic operations and comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and perform calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The condition for the three friends to have valid amounts is that the sum 
 * of the differences (with appropriate signs) must equal zero.
 * This simplifies to checking if any one of the given values is the sum 
 * of the other two.
 */

void solve() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    // Check if any one value is the sum of the other two.
    // This covers all valid sign combinations for x + y + z = 0.
    if ((X + Y == Z) || (X + Z == Y) || (Y + Z == X)) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }
}

int main() {
    // Optimize I/O operations
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