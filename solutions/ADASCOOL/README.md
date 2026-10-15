# [Ada School (ADASCOOL)](https://www.codechef.com/problems/ADASCOOL)

- **Difficulty Rating**: 1004
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an $N \times M$ grid of students. Each student must move to an adjacent cell (up, down, left, or right) such that every student ends up in a unique cell occupied by another student. Essentially, we need to determine if it is possible to form a **perfect matching** in the grid graph, where every student is paired with exactly one adjacent neighbor.

## Intuition & Mathematical Observation
A grid graph can be viewed as a bipartite graph (like a checkerboard). For a perfect matching to exist, the total number of vertices ($N \times M$) must be even.

1.  **If $N \times M$ is odd**: Both $N$ and $M$ must be odd. In a checkerboard coloring, the number of black and white cells will differ by 1. Therefore, it is impossible to pair every cell with an adjacent one.
2.  **If $N \times M$ is even**: At least one of $N$ or $M$ must be even.
    *   If $N$ is even, we can pair students vertically: $(1, j)$ with $(2, j)$, $(3, j)$ with $(4, j)$, and so on for every column $j$.
    *   If $M$ is even, we can pair students horizontally: $(i, 1)$ with $(i, 2)$, $(i, 3)$ with $(i, 4)$, and so on for every row $i$.

Thus, the condition for a perfect matching is simply that the total number of cells $N \times M$ is even, which is equivalent to checking if `(N * M) % 2 == 0`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves a constant time arithmetic check.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input dimensions.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A grid graph has a perfect matching if and only if the total number of 
 * vertices (N * M) is even. This is because a grid is a bipartite graph, 
 * and if the total number of nodes is odd, the partition sizes will differ 
 * by 1, making a perfect matching impossible. If at least one dimension 
 * is even, we can always tile the grid with 1x2 dominoes.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, m;
        cin >> n >> m;

        // If the total number of cells is even, a perfect matching exists.
        // This happens if at least one dimension is even.
        if ((n * m) % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```