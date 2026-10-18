# [Equal Card Game (EQCARDGAME)](https://www.codechef.com/problems/EQCARDGAME)

- **Difficulty Rating**: 1058
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice has a standard deck of 52 cards. She wants to distribute these cards equally among $K$ people. However, she may need to discard some cards to ensure that the remaining number of cards is perfectly divisible by $K$. The goal is to find the minimum number of cards Alice must discard.

## Intuition & Mathematical Observation
To minimize the number of discarded cards, we need to maximize the number of cards kept ($N$) such that:
1. $N \le 52$
2. $N$ is a multiple of $K$ (i.e., $N \pmod K = 0$)

In integer arithmetic, the expression `(52 / K) * K` effectively finds the largest multiple of $K$ that is less than or equal to 52. 

- Let $N = \lfloor \frac{52}{K} \rfloor \times K$.
- The number of cards to discard is simply the total cards minus the cards kept: $52 - N$.

For example, if $K = 10$:
- $52 / 10 = 5$
- $5 \times 10 = 50$ (This is the maximum number of cards we can distribute)
- $52 - 50 = 2$ cards must be discarded.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has 52 cards. There are K people in total.
 * She needs to distribute the cards equally among K people.
 * Let N be the number of cards remaining after discarding some.
 * N must be a multiple of K, and N <= 52.
 * To minimize the number of discarded cards (52 - N), 
 * we need to maximize N such that N <= 52 and N % K == 0.
 * 
 * The largest multiple of K less than or equal to 52 is:
 * N = (52 / K) * K
 * The number of discarded cards is 52 - N.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int k;
        cin >> k;
        
        // Calculate the largest multiple of k less than or equal to 52
        int remaining_cards = (52 / k) * k;
        
        // The number of cards to discard
        int discarded = 52 - remaining_cards;
        
        cout << discarded << "\n";
    }
    
    return 0;
}
```