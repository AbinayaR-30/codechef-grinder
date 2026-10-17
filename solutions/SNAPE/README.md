# [Snape and Ladder (SNAPE)](https://www.codechef.com/problems/SNAPE)

- **Difficulty Rating**: 828
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the distance between the two points where the ladder touches the ground ($B$) and the length of one side of the ladder ($LS$), we need to find the minimum and maximum possible values for the length of the other side of the ladder ($RS$) such that the ladder forms a right-angled triangle with the ground.

## Intuition & Mathematical Observation
The problem describes a right-angled triangle where the ladder's sides ($LS$ and $RS$) and the base ($B$) form the components. Let $H$ be the vertical height of the ladder.

1.  **Minimum $RS$**: This occurs when the ladder is tilted such that the side $LS$ acts as the hypotenuse of a right triangle with base $B$ and height $H$. In this configuration, $RS$ is vertical ($RS = H$).
    *   Using the Pythagorean theorem: $H^2 + B^2 = LS^2$
    *   $H = \sqrt{LS^2 - B^2}$
    *   Therefore, **Min $RS = \sqrt{LS^2 - B^2}$**.

2.  **Maximum $RS$**: This occurs when the side $LS$ is vertical ($H = LS$). The side $RS$ then acts as the hypotenuse of a right triangle with base $B$ and height $LS$.
    *   Using the Pythagorean theorem: $RS^2 = H^2 + B^2$
    *   $RS^2 = LS^2 + B^2$
    *   Therefore, **Max $RS = \sqrt{LS^2 + B^2}$**.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and square root calculations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a right-angled triangle formed by the ladder side, the base, and the height.
 * Let B be the base (separation), LS be the left side, and RS be the right side.
 * 
 * Min RS = sqrt(LS^2 - B^2)
 * Max RS = sqrt(LS^2 + B^2)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        double b, ls;
        cin >> b >> ls;

        // Calculate minimum RS: sqrt(LS^2 - B^2)
        double min_rs = sqrt(ls * ls - b * b);
        
        // Calculate maximum RS: sqrt(LS^2 + B^2)
        double max_rs = sqrt(ls * ls + b * b);

        // Output with required precision
        cout << fixed << setprecision(5) << min_rs << " " << max_rs << "\n";
    }

    return 0;
}
```