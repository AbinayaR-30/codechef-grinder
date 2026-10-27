# [Dance Moves (DANCEMOVES)](https://www.codechef.com/problems/DANCEMOVES)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef starts at position $X$ and wants to reach position $Y$. He has two types of moves:
1. **Moonwalk**: Move from $k$ to $k+2$.
2. **Slide**: Move from $k$ to $k-1$.

We need to find the minimum number of moves required to reach $Y$ starting from $X$.

## Intuition & Mathematical Observation
Let $D = Y - X$ be the distance we need to cover.

### Case 1: $Y \ge X$ (Moving forward)
We want to reach $Y$ using a combination of moonwalks ($+2$) and slides ($-1$).
*   **If $D$ is even**: We can reach the target using only moonwalks. The number of moves is simply $D/2$.
*   **If $D$ is odd**: We cannot reach the target using only $+2$ moves. We perform one extra moonwalk to reach $D+1$ (which is even) and then use one slide to return to $D$. 
    *   Number of moonwalks: $(D+1)/2$
    *   Number of slides: $1$
    *   Total moves: $(D+1)/2 + 1 = (D/2) + 2$ (using integer division).

### Case 2: $Y < X$ (Moving backward)
Since the only way to decrease the position is the slide move ($-1$), and we cannot use the moonwalk to move backward, we must use the slide move $|D|$ times.
*   Total moves: $X - Y$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at X, target is Y.
 * Moves:
 * 1. k -> k + 2
 * 2. k -> k - 1
 * 
 * Let 'a' be the number of moonwalks (+2) and 'b' be the number of slides (-1).
 * We want to reach Y from X: X + 2a - b = Y
 * So, 2a - b = Y - X
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    if (Y >= X) {
        long long diff = Y - X;
        if (diff % 2 == 0) {
            // Even distance: only moonwalks needed
            cout << diff / 2 << "\n";
        } else {
            // Odd distance: (diff+1)/2 moonwalks + 1 slide
            // Example: 3 to 8, diff=5. (5+1)/2 = 3 moonwalks (to 9), 1 slide (to 8). Total 4.
            cout << (diff / 2) + 2 << "\n";
        }
    } else {
        // If Y < X, we only use slides (-1)
        cout << (X - Y) << "\n";
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