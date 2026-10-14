# [Sharing Cookies (SHARING)](https://www.codechef.com/problems/SHARING)

- **Difficulty Rating**: 232
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice has $A$ cookies and Bob has $B$ cookies, where $A > B$. Alice wants to give some number of cookies $x$ to Bob such that they both end up with the same number of cookies. We need to determine if such an integer $x$ exists and, if so, output the value of $x$. If it is impossible to make their cookie counts equal, output -1.

## Intuition & Mathematical Observation
To make their cookie counts equal, the following equation must hold after the transfer:
$$A - x = B + x$$

Rearranging the terms to solve for $x$:
$$A - B = 2x$$
$$x = \frac{A - B}{2}$$

From this equation, we can derive two conditions for a valid solution:
1. **Parity**: Since $x$ must be an integer, $(A - B)$ must be divisible by 2 (i.e., $(A - B) \pmod 2 == 0$). If the difference is odd, it is impossible to split the cookies equally.
2. **Positivity**: Since the problem states $A > B$, the difference $(A - B)$ is always positive, ensuring $x > 0$.

If $(A - B)$ is even, the answer is $\frac{A - B}{2}$. Otherwise, the answer is $-1$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has A cookies, Bob has B cookies. A > B.
 * Let x be the number of cookies Alice gives to Bob.
 * After the transfer:
 * Alice has A - x cookies.
 * Bob has B + x cookies.
 * For them to be equal: A - x = B + x
 * A - B = 2x
 * x = (A - B) / 2
 * 
 * For x to be a valid number of cookies (an integer), (A - B) must be even.
 * Since A > B, A - B is always positive, so x will be positive if (A - B) is even.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    // Read input A and B
    if (!(cin >> A >> B)) return 0;

    long long diff = A - B;

    // Check if the difference is even
    if (diff % 2 == 0) {
        cout << (diff / 2) << "\n";
    } else {
        // If the difference is odd, they cannot have equal cookies
        cout << -1 << "\n";
    }

    return 0;
}
```