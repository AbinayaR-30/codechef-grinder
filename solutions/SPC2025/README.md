# [New-Pro Coder (SPC2025)](https://www.codechef.com/problems/SPC2025)

- **Difficulty Rating**: 467
- **Solved in**: 2 attempt(s)

## Problem Summary
The task is to determine whether a coder is a "NEWBIE" or a "PRO" based on their performance. Given the total number of problems $N$ and the number of problems solved $M$, a coder is classified as a "NEWBIE" if they have solved at least half of the total problems ($M \ge N / 2$). Otherwise, they are classified as a "PRO".

## Intuition & Mathematical Observation
The condition provided is $M \ge \frac{N}{2}$. 

To avoid potential precision issues associated with floating-point division, we can rearrange the inequality by multiplying both sides by 2:
$$2 \times M \ge N$$

This allows us to perform the comparison using only integer arithmetic, which is both safer and more efficient. If the condition $2M \ge N$ evaluates to true, we print "NEWBIE"; otherwise, we print "PRO".

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations and comparisons, regardless of the input size.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store the two integers $N$ and $M$.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * Ved is a NEWBIE if M >= N / 2.0.
 * To avoid floating point arithmetic, we can multiply both sides by 2:
 * 2 * M >= N
 * 
 * If this condition holds, output NEWBIE, otherwise output PRO.
 * 
 * Constraints:
 * 1 <= N, M <= 1000.
 * The logic fits well within standard integer types.
 */

int main() {
    // Fast I/O setup
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    if (std::cin >> N >> M) {
        // Condition: M >= N / 2.0
        // Equivalent to: 2 * M >= N
        if (2 * M >= N) {
            std::cout << "NEWBIE" << std::endl;
        } else {
            std::cout << "PRO" << std::endl;
        }
    }

    return 0;
}
```