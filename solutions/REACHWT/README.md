# [Reach Weight (REACHWT)](https://www.codechef.com/problems/REACHWT)

- **Difficulty Rating**: 530
- **Solved in**: 2 attempt(s)

## Problem Summary
We are tasked with reaching a target weight $N$ using two types of weights:
1. A 1kg weight costing 20 rupees.
2. A 2kg weight costing 30 rupees.

The goal is to find the minimum cost required to achieve exactly $N$ kg.

## Intuition & Mathematical Observation
Let $x$ be the number of 1kg weights and $y$ be the number of 2kg weights. We have the constraint:
$$x + 2y = N$$

The total cost function is:
$$\text{Cost} = 20x + 30y$$

Substituting $x = N - 2y$ into the cost equation:
$$\text{Cost} = 20(N - 2y) + 30y$$
$$\text{Cost} = 20N - 40y + 30y$$
$$\text{Cost} = 20N - 10y$$

To minimize the cost, we need to maximize $y$ (the number of 2kg weights). Since $2y \le N$, the maximum possible value for $y$ is $\lfloor N/2 \rfloor$. 

- If $N$ is even, we use $N/2$ weights of 2kg and zero 1kg weights.
- If $N$ is odd, we use $(N-1)/2$ weights of 2kg and one 1kg weight.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves simple arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We want to reach N kg using 1kg weights (20 rupees) and 2kg weights (30 rupees).
 * Cost = 20x + 30y, where x + 2y = N.
 * Substituting x = N - 2y:
 * Cost = 20(N - 2y) + 30y = 20N - 10y.
 * To minimize cost, we maximize y.
 * Max y = N / 2.
 */

void solve() {
    long long n;
    if (!(cin >> n)) return;
    
    // Maximize the number of 2kg weights to minimize cost
    long long y = n / 2;
    long long x = n % 2;
    
    long long min_cost = (x * 20) + (y * 30);
    
    cout << min_cost << "\n";
}

int main() {
    // Optimize I/O operations
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