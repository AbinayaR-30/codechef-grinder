# [Tekken (TEKKEN)](https://www.codechef.com/problems/TEKKEN)

- **Difficulty Rating**: 947
- **Solved in**: 1 attempt(s)

## Problem Summary
Anna, Bob, and Claudio are participating in a Tekken tournament. They fight in pairs. When two players with health $X$ and $Y$ fight, both players lose $\min(X, Y)$ health. This effectively means the player with lower health is eliminated (health becomes 0), and the player with higher health is reduced by the amount of the lower health. We need to determine if Anna can win (i.e., have health $> 0$) after all fights are concluded, assuming we can choose the order of the fights.

## Intuition & Mathematical Observation
To maximize Anna's chances of having positive health at the end, we should minimize the health of the opponent she eventually faces. 

1. **Optimal Strategy**: Let Bob and Claudio fight each other first. 
2. **The Result of the First Fight**: After Bob and Claudio fight, the survivor will have a health value equal to $|B - C|$.
3. **The Final Fight**: Anna then fights the survivor of the first match. Anna will have positive health if and only if her initial health $A$ is strictly greater than the survivor's health.
4. **Condition**: Anna wins if $A > |B - C|$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations and comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the health values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Anna (A), Bob (B), and Claudio (C) fight in pairs.
 * Each fight reduces both players' health by min(X, Y).
 * Effectively, the player with lower health becomes 0, and the player with higher health
 * reduces by the amount of the lower health.
 * 
 * We want to see if Anna can have > 0 health at the end.
 * To maximize Anna's chances, we should let Bob and Claudio fight each other first.
 * After Bob and Claudio fight, the winner (whoever had more health) will have 
 * health = abs(B - C).
 * Then Anna fights this winner.
 * Anna will have positive health if A > abs(B - C).
 */

void solve() {
    long long A, B, C;
    if (!(cin >> A >> B >> C)) return;

    // First, let Bob and Claudio fight.
    // The remaining health of the survivor between Bob and Claudio is abs(B - C).
    long long survivor_BC = abs(B - C);

    // Now Anna fights the survivor.
    // Anna's final health will be A - min(A, survivor_BC).
    // This is positive if A > survivor_BC.
    if (A > survivor_BC) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```