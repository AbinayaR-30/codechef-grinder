# [Odds and Evens (ODDSEVENS)](https://www.codechef.com/problems/ODDSEVENS)

- **Difficulty Rating**: 872
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob play a simple game involving two numbers, $a$ and $b$, each chosen from the range $[1, 5]$. The sum of these numbers ($a + b$) determines the winner:
- If the sum is **odd**, Alice wins.
- If the sum is **even**, Bob wins.

Given $T$ test cases, we need to determine the winner for each pair $(a, b)$.

## Intuition & Mathematical Observation
The problem boils down to checking the parity (odd or even nature) of the sum of two integers. 
- A sum is **odd** if one number is even and the other is odd.
- A sum is **even** if both numbers are even or both numbers are odd.

In programming, we can determine this efficiently using the modulo operator (`%`). If `(a + b) % 2 != 0`, the sum is odd (Alice wins); otherwise, the sum is even (Bob wins).

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Since we perform a constant number of arithmetic operations per test case, the solution runs in linear time relative to the input size.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the sum, regardless of the number of test cases.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice and Bob play a game where they pick numbers a and b (1 to 5).
 * Sum = a + b.
 * If Sum is odd, Alice wins.
 * If Sum is even, Bob wins.
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= a, b <= 5
 * 
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        // Calculate the sum
        int sum = a + b;
        
        // Check parity using modulo operator
        if (sum % 2 != 0) {
            // Sum is odd, Alice wins
            cout << "Alice" << "\n";
        } else {
            // Sum is even, Bob wins
            cout << "Bob" << "\n";
        }
    }
    
    return 0;
}
```