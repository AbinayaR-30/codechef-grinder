# [Long Drive (LONGDRIVE)](https://www.codechef.com/problems/LONGDRIVE)

- **Difficulty Rating**: 939
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has already driven for 10 hours at an average speed of $X$ km/h. He wants his overall average speed for the entire trip to be at least $Y$ km/h. Given that he can drive at a maximum speed of 100 km/h for any additional hours, find the minimum number of additional hours required to achieve an average speed of at least $Y$ km/h.

## Intuition & Mathematical Observation
Let $n$ be the number of additional hours driven at a speed of $v = 100$ km/h.
The total distance covered is $10X + 100n$, and the total time taken is $10 + n$.

We require the average speed to be at least $Y$:
$$\frac{10X + 100n}{10 + n} \geq Y$$

Rearranging the inequality to solve for $n$:
1. $10X + 100n \geq Y(10 + n)$
2. $10X + 100n \geq 10Y + nY$
3. $100n - nY \geq 10Y - 10X$
4. $n(100 - Y) \geq 10(Y - X)$
5. $n \geq \frac{10(Y - X)}{100 - Y}$

Since $n$ must be an integer, we take the ceiling of the result. Using integer arithmetic, the ceiling of $\frac{a}{b}$ can be calculated as `(a + b - 1) / b`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves basic arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To minimize 'n', we maximize the speed for additional hours to 100 km/h.
 * The derived formula is n >= (10 * (Y - X)) / (100 - Y).
 * We use integer ceiling division to find the smallest integer n.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long X, Y;
        cin >> X >> Y;

        // Numerator: 10 * (Y - X)
        // Denominator: 100 - Y
        // n = ceil(numerator / denominator)
        
        long long numerator = 10 * (Y - X);
        long long denominator = 100 - Y;
        
        // Integer ceiling division: (a + b - 1) / b
        long long n = (numerator + denominator - 1) / denominator;
        
        cout << n << "\n";
    }

    return 0;
}
```