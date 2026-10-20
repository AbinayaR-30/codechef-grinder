# [Technex Tickets (P2_175)](https://www.codechef.com/problems/P2_175)

- **Difficulty Rating**: 954
- **Solved in**: 1 attempt(s)

## Problem Summary
In this problem, we are tasked with determining the time at which a person standing at the $N$-th position in a queue will receive their ticket. At each second, the people at the 1st and 3rd positions of the current queue leave the queue. We need to find the specific second at which the person initially at position $N$ is removed.

## Intuition & Mathematical Observation
By simulating the process for the first few values of $N$, we can observe the pattern of when each position is removed:

| Initial Position ($N$) | Time Removed |
| :--- | :--- |
| 1 | 1 |
| 2 | 2 |
| 3 | 1 |
| 4 | 3 |
| 5 | 2 |
| 6 | 4 |
| 7 | 3 |
| 8 | 5 |
| 9 | 4 |

**Pattern Analysis:**
1. **Odd Positions ($N > 3$):** For odd numbers starting from 5, the time taken follows the sequence $2, 3, 4, \dots$. Specifically, for $N=5 \to 2$, $N=7 \to 3$, $N=9 \to 4$. The formula is $f(N) = (N-1)/2$.
2. **Even Positions:** For even numbers, the sequence is $2, 3, 4, 5, \dots$. Specifically, for $N=2 \to 2$, $N=4 \to 3$, $N=6 \to 4$. The formula is $f(N) = (N/2) + 1$.
3. **Base Cases:** $N=1$ and $N=3$ are special cases that both result in time $1$.

Combining these, we get a simple conditional logic to determine the output for any $N$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses a direct mathematical formula. The total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We derived the pattern based on the simulation of the queue removal process.
 * For N=1 and N=3, the time is 1.
 * For other odd N, the time is (N-1)/2.
 * For even N, the time is (N/2) + 1.
 */

void solve() {
    long long N;
    cin >> N;
    
    // Base cases for N=1 and N=3
    if (N == 1 || N == 3) {
        cout << 1 << "\n";
    } 
    // Formula for odd N > 3
    else if (N % 2 != 0) {
        cout << (N - 1) / 2 << "\n";
    } 
    // Formula for even N
    else {
        cout << (N / 2) + 1 << "\n";
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