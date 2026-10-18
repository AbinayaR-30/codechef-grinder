# [Bishop Moves (BISHOPMV)](https://www.codechef.com/problems/BISHOPMV)

- **Difficulty Rating**: 914
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the coordinates of two squares on an $8 \times 8$ chessboard, $(x_1, y_1)$ and $(x_2, y_2)$, determine the minimum number of moves a bishop requires to travel from the starting square to the target square. If the target is unreachable, output -1.

## Intuition & Mathematical Observation
A bishop moves diagonally. We can categorize the possible outcomes based on the geometric properties of the chessboard:

1.  **0 Moves**: If $(x_1, y_1) = (x_2, y_2)$, the bishop is already there. (Though the problem constraints imply distinct squares).
2.  **1 Move**: A bishop can reach any square on the same diagonal. Two squares are on the same diagonal if the absolute difference of their coordinates is equal: $|x_1 - x_2| = |y_1 - y_2|$.
3.  **2 Moves**: A bishop is restricted to squares of the same color. The color of a square $(x, y)$ is determined by the parity of the sum of its coordinates $(x + y) \pmod 2$. If the starting and ending squares have the same parity, they are the same color, and a bishop can always reach the target in at most 2 moves by intersecting the diagonals.
4.  **Impossible (-1)**: If the squares have different parities, they are of different colors. Since a bishop never changes the color of the square it occupies, it is impossible to reach the target.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations and comparisons.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the coordinates.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A bishop moves along diagonals.
 * Two cells (x1, y1) and (x2, y2) are on the same diagonal if:
 * abs(x1 - x2) == abs(y1 - y2)
 * 
 * If they are on the same diagonal, 1 move.
 * If they are not on the same diagonal, we check if they are reachable.
 * A bishop can only reach cells of the same color.
 * The color of a cell (x, y) is determined by (x + y) % 2.
 * If (x1 + y1) % 2 != (x2 + y2) % 2, it is impossible (-1).
 * If they are the same color, it is always possible in 2 moves.
 */

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // Check if same diagonal
    if (abs(x1 - x2) == abs(y1 - y2)) {
        cout << 1 << "\n";
    } 
    // Check if same color (same parity of sum of coordinates)
    else if ((x1 + y1) % 2 == (x2 + y2) % 2) {
        cout << 2 << "\n";
    } 
    // Different colors, impossible for a bishop
    else {
        cout << -1 << "\n";
    }
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