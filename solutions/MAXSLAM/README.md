# [Maximum Slams (MAXSLAM)](https://www.codechef.com/problems/MAXSLAM)

- **Difficulty Rating**: 224
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef currently has $X$ Grand Slam titles. He aims to reach a total of at least 25 titles. Since Chef wins 4 Grand Slam titles every year, we need to determine the minimum number of years required for Chef to reach or exceed the target of 25 titles.

## Intuition & Mathematical Observation
To find the number of years $Y$, we set up the inequality:
$$X + 4Y \ge 25$$
Rearranging for $Y$:
$$4Y \ge 25 - X$$
$$Y \ge \frac{25 - X}{4}$$

Since $Y$ must be an integer, we need the ceiling of the division:
$$Y = \lceil \frac{25 - X}{4} \rceil$$

In integer arithmetic, the ceiling of $\frac{a}{b}$ can be calculated as `(a + b - 1) / b`. Applying this to our formula where $a = 25 - X$ and $b = 4$:
$$Y = \frac{(25 - X) + 4 - 1}{4} = \frac{25 - X + 3}{4}$$

Given the constraint $0 \le X \le 24$, the value of $(25 - X)$ will always be between 1 and 25, ensuring the result is always a positive integer representing the minimum years required.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$ — No additional data structures are used; only a few integer variables are stored.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * Chef needs at least 25 total wins.
 * Current wins = X.
 * Wins needed = 25 - X.
 * Each year, Chef wins 4 Grand Slams.
 * Let Y be the number of years.
 * We need 4 * Y >= 25 - X.
 * 
 * Since X <= 24, 25 - X is always positive (1 to 25).
 * The number of years Y is the smallest integer such that 4 * Y >= 25 - X.
 * This is equivalent to ceil((25 - X) / 4.0).
 * Using integer arithmetic, this is (25 - X + 3) / 4.
 */

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int X;
    if (!(std::cin >> X)) return 0;
    
    int needed = 25 - X;
    
    // Since constraints are 0 <= X <= 24, needed is always > 0.
    // Calculate ceiling of (needed / 4) using integer division
    int years = (needed + 3) / 4;
    
    std::cout << years << std::endl;

    return 0;
}
```