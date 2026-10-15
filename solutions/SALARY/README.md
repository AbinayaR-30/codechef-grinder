# [The Minimum Number Of Moves (SALARY)](https://www.codechef.com/problems/SALARY)

- **Difficulty Rating**: 1286
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ workers, each with an initial salary $W_i$. In one operation, we can choose one worker and increase the salary of all *other* $N-1$ workers by 1. The goal is to find the minimum number of operations required to make all workers' salaries equal.

## Intuition & Mathematical Observation
The key insight is to realize that increasing $N-1$ workers by 1 is mathematically equivalent to decreasing the salary of the one worker *not* chosen by 1, relative to the others. 

If we want to equalize all salaries, we must eventually bring every worker's salary down to the level of the worker who currently has the minimum salary. 

Let $min\_w$ be the minimum salary in the initial array. To make every worker's salary equal to $min\_w$, each worker $i$ must be the "chosen one" (the one who does not receive the +1 increment) exactly $(W_i - min\_w)$ times. 

Therefore, the total number of operations required is the sum of the differences between each worker's salary and the minimum salary:
$$\text{Total Operations} = \sum_{i=1}^{N} (W_i - min\_w)$$

This can be simplified to:
$$\text{Total Operations} = \sum W_i - (N \times min\_w)$$

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array once to find the sum and the minimum value.
- **Space Complexity**: $O(N)$ to store the salaries (or $O(1)$ if we calculate the sum and minimum on the fly without storing the array).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Increasing everyone except worker i by 1 is equivalent to decreasing worker i 
 * by 1 relative to the others. To equalize all salaries, we must reduce every 
 * worker's salary to the current minimum salary.
 * 
 * Total operations = sum(W_i - min_w) for all i.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> w(n);
    long long min_val = 10001; // Constraint: W_i <= 10000
    long long sum = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        if (w[i] < min_val) {
            min_val = w[i];
        }
        sum += w[i];
    }
    
    // The total number of operations is sum(W_i - min_val)
    // which is sum(W_i) - n * min_val
    long long result = sum - (long long)n * min_val;
    cout << result << "\n";
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