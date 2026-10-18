# [From heaven to earth (ELEVSTRS)](https://www.codechef.com/problems/ELEVSTRS)

- **Difficulty Rating**: 1066
- **Solved in**: 1 attempt(s)

## Problem Summary
We need to determine whether it is faster to reach the $N$-th floor using the stairs or the elevator. 
- **Stairs**: The distance covered is the diagonal of the building's height. Given $N$ floors, the distance is $N \times \sqrt{2}$. The speed is $V_1$.
- **Elevator**: The elevator must travel to the $N$-th floor and then return to the ground floor. The total distance covered is $2 \times N$. The speed is $V_2$.

We must output "Elevator" if the elevator takes less time, otherwise "Stairs".

## Intuition & Mathematical Observation
To solve this, we calculate the time taken for both methods using the formula: $\text{Time} = \frac{\text{Distance}}{\text{Velocity}}$.

1.  **Time for Stairs ($T_s$):**
    $$T_s = \frac{N \times \sqrt{2}}{V_1}$$
2.  **Time for Elevator ($T_e$):**
    $$T_e = \frac{2 \times N}{V_2}$$

Since the constraints for $N, V_1, V_2$ are small (up to 100), we can perform these calculations using `double` precision floating-point numbers without worrying about precision errors. We simply compare $T_e$ and $T_s$ and print the result accordingly.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculated times.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Stairs:
 *    Distance = N * sqrt(2)
 *    Velocity = V1
 *    Time_stairs = (N * sqrt(2)) / V1
 * 
 * 2. Elevator:
 *    The elevator starts at ground, goes to N (distance N), then back to ground (distance N).
 *    Total distance = 2 * N
 *    Velocity = V2
 *    Time_elevator = (2 * N) / V2
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        double n, v1, v2;
        cin >> n >> v1 >> v2;

        double time_stairs = (n * sqrt(2.0)) / v1;
        double time_elevator = (2.0 * n) / v2;

        if (time_elevator < time_stairs) {
            cout << "Elevator" << "\n";
        } else {
            cout << "Stairs" << "\n";
        }
    }

    return 0;
}
```