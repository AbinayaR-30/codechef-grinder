# [Sell All the Cars (CARSELL)](https://www.codechef.com/problems/CARSELL)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef owns $N$ cars, each with an initial price $P_i$. Every year, the price of every unsold car decreases by 1 (until it reaches 0). Chef can sell at most one car per year. The goal is to determine the maximum total profit Chef can achieve by choosing the optimal order to sell the cars.

## Intuition & Mathematical Observation
To maximize the total profit, we must minimize the "loss" caused by the price depreciation. Since every unsold car loses 1 unit of value each year, we want to sell the most expensive cars as early as possible to prevent them from depreciating further.

1. **Sorting**: By sorting the car prices in descending order ($P_1 \ge P_2 \ge \dots \ge P_N$), we ensure that the largest values are sold when the depreciation penalty is smallest.
2. **Depreciation**: In the $i$-th year (0-indexed), a car that originally cost $P_i$ will have depreciated by $i$ units. Its selling price will be $\max(0, P_i - i)$.
3. **Modulo Arithmetic**: Since the total profit can be very large, we perform all additions modulo $10^9 + 7$.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \log N)$, where $T$ is the number of test cases and $N$ is the number of cars. The bottleneck is the sorting step, which is efficient enough for $N = 10^5$ within the 1-second time limit.
- **Space Complexity**: $O(N)$ to store the prices of the cars in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N cars with initial prices P_i.
 * Each year, the price of every unsold car decreases by 1 (minimum 0).
 * To maximize profit, we should sell the most expensive cars first.
 * If we sort the prices in descending order: P_1 >= P_2 >= ... >= P_N,
 * in year 0 (first year), we sell the car with price P_1. Profit = P_1.
 * In year 1, the remaining cars have prices max(0, P_i - 1). We sell the largest.
 * By sorting descending, in year 'i' (0-indexed), the price of the car sold
 * will be max(0, P_i - i).
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    // Sort in descending order to sell the most expensive cars first
    sort(P.begin(), P.end(), greater<long long>());

    long long total_profit = 0;
    long long MOD = 1000000007;

    for (int i = 0; i < N; ++i) {
        // Price of the car at year i is max(0, P[i] - i)
        long long current_price = P[i] - i;
        if (current_price > 0) {
            total_profit = (total_profit + current_price) % MOD;
        }
    }

    cout << total_profit << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```