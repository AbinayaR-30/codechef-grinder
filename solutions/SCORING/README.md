# [Scoring (SCORING)](https://www.codechef.com/problems/SCORING)

- **Difficulty Rating**: 569
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the difference between Alice's and Bob's scores ($A - B = X$) and the sum of their scores ($A + B = Y$), we need to determine the individual scores of Alice ($A$) and Bob ($B$).

## Intuition & Mathematical Observation
This is a classic system of linear equations with two variables:
1. $A - B = X$
2. $A + B = Y$

By adding the two equations together:
$(A - B) + (A + B) = X + Y$
$2A = X + Y$
$A = \frac{X + Y}{2}$

By subtracting the first equation from the second:
$(A + B) - (A - B) = Y - X$
$2B = Y - X$
$B = \frac{Y - X}{2}$

Since the problem guarantees that a valid solution exists, $X+Y$ and $Y-X$ will always be even and non-negative, allowing us to compute the scores using simple integer division.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves constant time arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let A be Alice's score and B be Bob's score.
 * We are given:
 * 1) A - B = X
 * 2) A + B = Y
 * 
 * Adding the two equations:
 * 2A = X + Y  =>  A = (X + Y) / 2
 * 
 * Subtracting the first from the second:
 * 2B = Y - X  =>  B = (Y - X) / 2
 */

int main() {
    // Optimize standard I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // Calculate scores using the derived formulas
        long long alice = (x + y) / 2;
        long long bob = (y - x) / 2;

        cout << alice << " " << bob << "\n";
    }

    return 0;
}
```