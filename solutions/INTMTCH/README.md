# [Interesting Match (INTMTCH)](https://www.codechef.com/problems/INTMTCH)

- **Difficulty Rating**: 240
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine if a match between two players is "Interesting" or "Boring" based on their scores, $X$ and $Y$. A match is considered "Interesting" if the absolute difference between the two scores is at most 2 (i.e., $|X - Y| \le 2$). Otherwise, the match is "Boring".

## Intuition & Mathematical Observation
The core of the problem is to evaluate the condition $|X - Y| \le 2$. 
1. We read the two integers $X$ and $Y$ from the input.
2. We calculate the absolute difference using the `abs()` function from the `<cmath>` library.
3. We compare the result:
   - If `abs(X - Y) <= 2`, output "Interesting".
   - Otherwise, output "Boring".

Since the constraints are very small ($0 \le X, Y \le 10$), this approach is highly efficient and handles all edge cases correctly.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic and comparison operations regardless of the input values.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store the two integers and the difference.

## Solution Code

```cpp
#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problem: Interesting Match
 * The problem asks to determine if the absolute difference between two integers X and Y
 * is at most 2.
 * 
 * Constraints: 0 <= X, Y <= 10.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    // Read the two integers directly as per the problem format
    if (cin >> x >> y) {
        // Calculate absolute difference
        int diff = abs(x - y);

        // Check if the difference is at most 2
        if (diff <= 2) {
            cout << "Interesting" << endl;
        } else {
            cout << "Boring" << endl;
        }
    }

    return 0;
}
```