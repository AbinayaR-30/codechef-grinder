# [Far from origin (FARFROMO)](https://www.codechef.com/problems/FARFROMO)

- **Difficulty Rating**: 750
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine which of two people, Alex or Bob, is standing further away from the origin $(0, 0)$ on a 2D Cartesian plane. We are given the coordinates $(x_1, y_1)$ for Alex and $(x_2, y_2)$ for Bob. If Alex is further, we output "ALEX"; if Bob is further, we output "BOB"; if they are at the same distance, we output "EQUAL".

## Intuition & Mathematical Observation
The Euclidean distance of a point $(x, y)$ from the origin $(0, 0)$ is defined as:
$$\text{Distance} = \sqrt{x^2 + y^2}$$

To compare the distances of two points, we do not need to calculate the square root, which is computationally expensive and can lead to floating-point precision errors. Instead, we can compare the **squared distances**:
$$\text{Distance}^2 = x^2 + y^2$$

Since $f(d) = d^2$ is a monotonically increasing function for $d \ge 0$, if $d_1^2 > d_2^2$, then $d_1 > d_2$. By comparing $x_1^2 + y_1^2$ and $x_2^2 + y_2^2$, we can determine the answer using only integer arithmetic. Given the constraints $|x|, |y| \le 1000$, the maximum squared distance is $1000^2 + 1000^2 = 2,000,000$, which fits safely within a standard 32-bit integer.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since there are $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the coordinates and squared distances.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The distance of a point (x, y) from the origin (0, 0) is given by the formula:
 * Distance = sqrt(x^2 + y^2)
 * To compare the distances of Alex (X1, Y1) and Bob (X2, Y2), we can compare
 * the squared distances to avoid floating point precision issues and the 
 * computational cost of sqrt().
 * 
 * Squared Distance_Alex = X1^2 + Y1^2
 * Squared Distance_Bob = X2^2 + Y2^2
 * 
 * Constraints: -1000 <= X, Y <= 1000
 * Max squared distance = 1000^2 + 1000^2 = 2,000,000.
 * This fits comfortably within a standard 32-bit signed integer, 
 * but using long long is good practice to prevent overflow in similar problems.
 */

void solve() {
    long long x1, y1, x2, y2;
    if (!(cin >> x1 >> y1 >> x2 >> y2)) return;

    long long distSqAlex = (x1 * x1) + (y1 * y1);
    long long distSqBob = (x2 * x2) + (y2 * y2);

    if (distSqAlex > distSqBob) {
        cout << "ALEX" << "\n";
    } else if (distSqBob > distSqAlex) {
        cout << "BOB" << "\n";
    } else {
        cout << "EQUAL" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```