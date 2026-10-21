# [Chef and Serves (CHSERVE)](https://www.codechef.com/problems/CHSERVE)

- **Difficulty Rating**: 1101
- **Solved in**: 1 attempt(s)

## Problem Summary
In a game of table tennis, Chef and Cook take turns serving. The serve changes every $K$ points. Specifically, Chef starts serving for the first $K$ points (points $0$ to $K-1$), then Cook serves for the next $K$ points (points $K$ to $2K-1$), then Chef serves again, and so on. Given the current scores of Chef ($P_1$) and Cook ($P_2$), determine whose turn it is to serve.

## Intuition & Mathematical Observation
The total number of points played in the game is $S = P_1 + P_2$. Since the serve changes every $K$ points, we can determine how many times the serve has switched by calculating the integer division of the total points by $K$:
$$\text{turns} = \lfloor \frac{P_1 + P_2}{K} \rfloor$$

- If $\text{turns}$ is **even**, the serve is in its initial state (Chef's turn).
- If $\text{turns}$ is **odd**, the serve has switched an odd number of times (Cook's turn).

This logic holds because every block of $K$ points represents a complete cycle of one person's service turn. By checking the parity of the quotient, we can identify the server without simulating the game point-by-point.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The total number of points scored is S = P1 + P2.
 * The serve changes every K points.
 * 
 * Number of times the serve has changed is floor(S / K).
 * If floor(S / K) is even, it is Chef's turn.
 * If floor(S / K) is odd, it is Cook's turn.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long p1, p2, k;
        cin >> p1 >> p2 >> k;
        
        long long total_points = p1 + p2;
        long long turns = total_points / k;
        
        if (turns % 2 == 0) {
            cout << "CHEF" << "\n";
        } else {
            cout << "COOK" << "\n";
        }
    }
    
    return 0;
}
```