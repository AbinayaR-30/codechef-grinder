# [Chocolate Eating (CHOCEAT)](https://www.codechef.com/problems/CHOCEAT)

- **Difficulty Rating**: 903
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $A$ milk chocolates and $B$ dark chocolates. He eats them one by one. A satisfaction point is gained for every chocolate eaten, provided that the number of milk chocolates eaten so far is not equal to the number of dark chocolates eaten so far. We need to determine the maximum total satisfaction Chef can achieve by choosing the order in which he eats the chocolates.

## Intuition & Mathematical Observation
Let $m$ be the number of milk chocolates eaten and $d$ be the number of dark chocolates eaten. We gain a point at each step unless $m = d$.

1. **Case 1: $A \neq B$**
   If we eat all chocolates of the more abundant type first, we can ensure that $m$ never equals $d$ throughout the entire process. For example, if $A > B$, we eat all $A$ milk chocolates first. At every step, $m > 0$ and $d = 0$, so $m \neq d$. Then, as we eat the $B$ dark chocolates, $m$ remains $A$ while $d$ increases from $1$ to $B$. Since $A > B$, $m$ will never equal $d$ during this phase either. Thus, we gain a point for every single chocolate.
   **Total Satisfaction = $A + B$**.

2. **Case 2: $A = B$**
   If we have an equal number of both, we will inevitably hit the state $m = d$ at some point. Specifically, if we eat one of each, we hit $m=d$ at the very first step ($1=1$). To maximize satisfaction, we should avoid the $m=d$ condition as much as possible. By eating one type until we have eaten all of them, we only hit the $m=d$ condition once (at the very end when $m=A$ and $d=B$, since $A=B$).
   **Total Satisfaction = $(A + B) - 1$**.

Combining these, the answer is $A + B$ if $A \neq B$, and $A + B - 1$ if $A = B$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple conditional check. The total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has A milk chocolates and B dark chocolates.
 * Satisfaction increases if (milk_eaten != dark_eaten).
 * 
 * If A != B, we can eat all of the larger quantity first, 
 * ensuring m != d at every step. Total = A + B.
 * If A == B, we are forced to hit m == d at least once.
 * Total = A + B - 1.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        
        if (a == b) {
            // If counts are equal, we lose 1 point when m == d
            cout << a + b - 1 << "\n";
        } else {
            // If counts are unequal, we can avoid m == d entirely
            cout << a + b << "\n";
        }
    }
    return 0;
}
```