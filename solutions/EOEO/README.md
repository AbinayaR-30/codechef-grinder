# [The Tom and Jerry Game! (EOEO)](https://www.codechef.com/problems/EOEO)

- **Difficulty Rating**: 1337
- **Solved in**: 1 attempt(s)

## Problem Summary
Tom and Jerry are playing a game with a number $TS$ (Tom's starting number). Jerry chooses a number $JS$ such that $1 \le JS < TS$. The game proceeds by repeatedly dividing both numbers by 2 as long as both are even. The game ends when at least one of the numbers becomes odd. Jerry wins if the final $JS$ is odd and the final $TS$ is even. We need to find the number of possible values for $JS$ that result in a win for Jerry.

## Intuition & Mathematical Observation
Let $TS = 2^k \cdot m$, where $m$ is an odd integer. 
The game rules state that we divide both numbers by 2 until at least one is odd. This is equivalent to removing all factors of 2 from both numbers.

Let $JS = 2^p \cdot n$, where $n$ is an odd integer.
After the division process:
- The final value of $TS$ will be $m$ (which is odd).
- The final value of $JS$ will be $n$ (which is odd).

For Jerry to win, the final $TS$ must be even and the final $JS$ must be odd. However, the problem states the game ends when *at least one* is odd. If we divide both by $2^{\min(k, p)}$, the number with the smaller power of 2 becomes odd first. 
- If $k < p$: $TS$ becomes odd, $JS$ remains even. This doesn't match the win condition.
- If $k > p$: $TS$ remains even, $JS$ becomes odd. **Jerry wins.**

Thus, Jerry wins if $JS$ has strictly more factors of 2 than $TS$.
If $TS = 2^k \cdot m$, then $JS$ must be a multiple of $2^{k+1}$.
We need to count how many multiples of $2^{k+1}$ exist in the range $[1, TS]$.
This is simply:
$$\text{Count} = \lfloor \frac{TS}{2^{k+1}} \rfloor$$

## Complexity Analysis
- **Time Complexity**: $O(\log(TS))$ per test case, as we perform a loop to find the highest power of 2 dividing $TS$. Given $T$ test cases, the total complexity is $O(T \cdot \log(TS))$.
- **Space Complexity**: $O(1)$, as we only use a few variables for calculation.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let TS = 2^k * m, where m is odd.
 * Jerry wins if JS has more factors of 2 than TS.
 * This means JS must be a multiple of 2^(k+1).
 * The number of such multiples JS <= TS is floor(TS / 2^(k+1)).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long ts;
        cin >> ts;

        // Find the power of 2 that divides ts (2^k)
        long long temp_ts = ts;
        long long power_of_2 = 1;
        while (temp_ts % 2 == 0) {
            temp_ts /= 2;
            power_of_2 *= 2;
        }

        // Jerry wins if JS is a multiple of (power_of_2 * 2).
        // The number of multiples of (power_of_2 * 2) up to TS is TS / (power_of_2 * 2).
        long long ans = ts / (power_of_2 * 2);
        
        cout << ans << "\n";
    }

    return 0;
}
```