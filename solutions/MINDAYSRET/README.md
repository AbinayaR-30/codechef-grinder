# [Back to Campus (MINDAYSRET)](https://www.codechef.com/problems/MINDAYSRET)

- **Difficulty Rating**: 933
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine the minimum number of days required to screen $N$ students, given that a maximum of $K$ students can be screened per day. If $N$ is not perfectly divisible by $K$, the remaining students will require an additional day of screening.

## Intuition & Mathematical Observation
The problem is a classic application of **ceiling division**. 
- If $N$ is perfectly divisible by $K$, the answer is simply $N / K$.
- If there is a remainder, we need one extra day to cover the remaining students.

Instead of using conditional statements or floating-point division (which can lead to precision issues), we can use the integer arithmetic formula for ceiling division:
$$\lceil N / K \rceil = \frac{N + K - 1}{K}$$
This formula works because adding $K-1$ to $N$ effectively "pushes" any remainder into the next integer multiple of $K$, ensuring the division result is rounded up correctly.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We need to find the minimum number of days to screen N students with a capacity of K per day.
 * This is equivalent to ceil(N / K).
 * Using integer arithmetic, ceil(N / K) = (N + K - 1) / K.
 * 
 * Complexity:
 * Time: O(T), where T is the number of test cases.
 * Space: O(1).
 */

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n, k;
        if (!(cin >> n >> k)) break;

        // Calculate ceil(n / k) using integer arithmetic
        // (n + k - 1) / k is the standard way to perform ceiling division
        int days = (n + k - 1) / k;
        
        cout << days << "\n";
    }

    return 0;
}
```