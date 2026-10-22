# [Can_Reach (CAN_REACH)](https://www.codechef.com/problems/CAN_REACH)

- **Difficulty Rating**: 990
- **Solved in**: 2 attempt(s)

## Problem Summary
You start at the origin $(0, 0)$ on a 2D plane. You are allowed to move exactly $K$ units in any of the four cardinal directions (up, down, left, or right) in a single step. Given a target coordinate $(x, y)$ and the step size $K$, determine if it is possible to reach the target point starting from $(0, 0)$.

## Intuition & Mathematical Observation
To reach a point $(x, y)$ from $(0, 0)$ using steps of size $K$:
1. Each move changes either the x-coordinate or the y-coordinate by exactly $K$ units.
2. After any number of moves, the x-coordinate will be of the form $n \times K$ (where $n$ is an integer representing the net number of horizontal steps) and the y-coordinate will be of the form $m \times K$ (where $m$ is an integer representing the net number of vertical steps).
3. Therefore, for a point $(x, y)$ to be reachable, both $x$ and $y$ must be perfectly divisible by $K$. 
4. If $x \pmod K == 0$ and $y \pmod K == 0$, the target is reachable. Otherwise, it is impossible.

*Note: Since the problem allows moving in both positive and negative directions, we do not need to worry about the signs of $x$ and $y$; the divisibility rule holds regardless.*

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform two modulo operations and two comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * To reach (x, y) from (0, 0) by moving exactly K units at a time:
 * The total displacement in x must be a multiple of K (x = n * K).
 * The total displacement in y must be a multiple of K (y = m * K).
 * Therefore, the condition is simply (x % K == 0) AND (y % K == 0).
 */

void solve() {
    int x, y, K;
    if (!(cin >> x >> y >> K)) return;
    
    // Check if both x and y are divisible by K
    // We use abs() if the coordinates could be negative, 
    // though x % K == 0 handles negative numbers correctly in C++.
    if (x % K == 0 && y % K == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Optimize I/O operations
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