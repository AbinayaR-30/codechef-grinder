# [Hungry Chef (BURGERS2)](https://www.codechef.com/problems/BURGERS2)

- **Difficulty Rating**: 1187
- **Solved in**: 1 attempt(s)

## Problem Summary
The goal is to buy exactly $N$ burgers with a total budget of $R$. There are two types of burgers: normal burgers costing $X$ and premium burgers costing $Y$ (where $Y > X$). We need to find the number of normal burgers ($n_{normal}$) and premium burgers ($n_{premium}$) such that their sum is $N$ and their total cost is at most $R$. If no such combination exists, output -1.

## Intuition & Mathematical Observation
We are given the following system:
1. $n_{normal} + n_{premium} = N$
2. $X \cdot n_{normal} + Y \cdot n_{premium} \le R$

By substituting $n_{normal} = N - n_{premium}$ into the second equation:
$X(N - n_{premium}) + Y \cdot n_{premium} \le R$
$X \cdot N - X \cdot n_{premium} + Y \cdot n_{premium} \le R$
$n_{premium}(Y - X) \le R - X \cdot N$

Since $Y > X$, we can isolate $n_{premium}$:
$n_{premium} \le \frac{R - X \cdot N}{Y - X}$

**Key Logic:**
1. **Feasibility**: If $R < X \cdot N$, even the cheapest possible combination (all normal burgers) exceeds the budget. In this case, output -1.
2. **Maximization**: To satisfy the constraints, we calculate the maximum possible $n_{premium}$ using the derived formula. Since we cannot have more than $N$ burgers, we cap $n_{premium}$ at $N$.
3. **Result**: Once $n_{premium}$ is determined, $n_{normal}$ is simply $N - n_{premium}$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We derive the number of premium burgers using the inequality:
 * n_premium <= (R - X * N) / (Y - X)
 * 
 * If R < X * N, it is impossible to buy N burgers.
 * Otherwise, we take the largest integer satisfying the inequality, 
 * capped at N.
 */

void solve() {
    long long X, Y, N, R;
    cin >> X >> Y >> N >> R;

    // If even buying N normal burgers costs more than R, it's impossible.
    if (R < X * N) {
        cout << -1 << "\n";
        return;
    }

    // Calculate max possible premium burgers
    // n_premium * (Y - X) <= R - X * N
    long long max_premium = (R - X * N) / (Y - X);

    // We must have at most N burgers total
    if (max_premium > N) {
        max_premium = N;
    }

    long long n_premium = max_premium;
    long long n_normal = N - n_premium;

    cout << n_normal << " " << n_premium << "\n";
}

int main() {
    // Fast I/O
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