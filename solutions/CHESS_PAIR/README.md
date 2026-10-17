# [Chess Pairing (CHESS_PAIR)](https://www.codechef.com/problems/CHESS_PAIR)

- **Difficulty Rating**: 892
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $2N$ total players, where $X$ players are rated and the remaining $2N - X$ players are unrated. We need to pair all $2N$ players into $N$ pairs such that the number of pairs consisting of two rated players is minimized. We are asked to output the number of rated players who are paired with another rated player.

## Intuition & Mathematical Observation
To minimize the number of rated-rated pairs, we should maximize the number of rated-unrated pairs. 

1. Let $R = X$ (rated players) and $U = 2N - X$ (unrated players).
2. Each unrated player can "neutralize" one rated player by forming a rated-unrated pair.
3. If $X \le N$, we have enough unrated players to pair with every rated player. Thus, the number of rated players paired with other rated players is **0**.
4. If $X > N$, we use all $U$ unrated players to pair with $U$ rated players. The remaining rated players are $X - U$.
   - Substituting $U = 2N - X$:
   - Remaining rated players = $X - (2N - X) = 2X - 2N$.
   - Since these remaining players must be paired with each other, all $2X - 2N$ of them will be paired with another rated player.

Therefore, the answer is $\max(0, 2X - 2N)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have 2N total players, X of whom are rated.
 * We want to minimize the number of rated players paired with other rated players.
 * 
 * Let R = X (number of rated players)
 * Let U = 2N - X (number of unrated players)
 * 
 * Each pair consists of 2 players.
 * To minimize rated-rated pairs, we should prioritize pairing rated players with unrated players.
 * Each rated-unrated pair uses 1 rated player and 1 unrated player.
 * We can form at most U such pairs (since we only have U unrated players).
 * 
 * After forming as many rated-unrated pairs as possible:
 * 1. If X <= N, we can pair all X rated players with unrated players.
 *    The number of rated players with rated opponents is 0.
 * 2. If X > N, we have more rated players than unrated players.
 *    We use all U unrated players to pair with U rated players.
 *    Remaining rated players = X - U = X - (2N - X) = 2X - 2N.
 *    These remaining rated players must be paired with each other.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        // If x <= n, we can pair every rated player with an unrated player.
        // If x > n, we have x - (2n - x) = 2x - 2n rated players left over
        // who must be paired with each other.
        
        if (x <= n) {
            cout << 0 << "\n";
        } else {
            cout << (2 * x - 2 * n) << "\n";
        }
    }

    return 0;
}
```