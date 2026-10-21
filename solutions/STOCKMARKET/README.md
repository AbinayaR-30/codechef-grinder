# [Chef and Stocks (STOCKMARKET)](https://www.codechef.com/problems/STOCKMARKET)

- **Difficulty Rating**: 948
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an array $A$ of $N$ integers representing the profit or loss on each day. We are required to choose exactly one day to skip (remove its value from the total) such that the sum of the remaining $N-1$ days is maximized.

## Intuition & Mathematical Observation
To maximize the sum of the remaining elements, we need to subtract the smallest possible value from the total sum of the array. 

Mathematically, if the total sum of the array is $S = \sum_{i=1}^{N} A_i$, and we choose to skip the element at index $k$, the resulting sum is $S - A_k$. To maximize this value, we must minimize $A_k$. Therefore, the optimal strategy is:
1. Calculate the total sum of all elements in the array.
2. Find the minimum element present in the array.
3. Subtract the minimum element from the total sum.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to calculate the sum and find the minimum element. Given the constraint $\sum N \le 10^6$, this approach is highly efficient.
- **Space Complexity**: $O(1)$ (excluding the input storage), as we only need to maintain variables for the `total_sum` and the `min_val`.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N days of profit/loss A_i.
 * We need to skip exactly one day to maximize the total profit.
 * Total profit = (Sum of all A_i) - A_k, where A_k is the profit of the day we skip.
 * To maximize the total profit, we need to minimize A_k.
 * Therefore, the result is (Sum of all A_i) - (Minimum value in A).
 */

void solve() {
    int N;
    cin >> N;
    
    long long total_sum = 0;
    long long min_val = 101; // Since max A_i is 100, 101 is a safe initial value
    
    for (int i = 0; i < N; ++i) {
        long long val;
        cin >> val;
        total_sum += val;
        if (val < min_val) {
            min_val = val;
        }
    }
    
    // The maximum profit after skipping one day is the total sum minus the minimum element.
    cout << (total_sum - min_val) << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
```