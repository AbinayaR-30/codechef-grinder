# [Truth Teller And Liars 101 (TRUTHLIE)](https://www.codechef.com/problems/TRUTHLIE)

- **Difficulty Rating**: 1097
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ truth-tellers and $M$ liars. We need to determine the minimum number of people $X$ we must ask such that, regardless of which $X$ people we choose, we can definitively identify the correct path. If it is impossible to guarantee a correct identification regardless of the selection, we should output -1.

## Intuition & Mathematical Observation
To guarantee the correct path, the number of truth-tellers in our chosen group must strictly exceed the number of liars in that same group. 

1. **Worst-Case Scenario**: When we pick $X$ people, the worst-case scenario is that we pick as many liars as possible. Since there are $M$ liars total, if $X > M$, we are guaranteed to pick at least $X - M$ truth-tellers.
2. **Majority Condition**: To be certain of the truth, the number of truth-tellers must be strictly greater than the number of liars. Even in the worst case, the number of liars we might have picked is $M$. Therefore, we need:
   $$(X - M) > M$$
   $$X > 2M$$
   The smallest integer $X$ satisfying this is $X = 2M + 1$.
3. **Feasibility**: This strategy is only possible if we have enough people to pick from. We need $X \le N + M$. Substituting $X = 2M + 1$:
   $$2M + 1 \le N + M$$
   $$M + 1 \le N$$
   $$N > M$$
   If $N \le M$, it is impossible to guarantee a majority of truth-tellers, so we output -1.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few integer variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To be sure of the truth, the number of truth-tellers in our sample must 
 * strictly exceed the number of liars. 
 * In the worst case, we pick all M liars. To have a majority, we need 
 * (X - M) > M, which simplifies to X > 2M.
 * The smallest such X is 2M + 1.
 * This is only possible if the total number of people (N + M) is at least 2M + 1,
 * which simplifies to N > M.
 */

void solve() {
    int N, M;
    cin >> N >> M;

    // Check if it's possible to have a majority of truth-tellers
    if (N > M) {
        cout << 2 * M + 1 << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```