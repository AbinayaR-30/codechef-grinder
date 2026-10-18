# [Yoga Class (YOGACLASS)](https://www.codechef.com/problems/YOGACLASS)

- **Difficulty Rating**: 879
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ hours available for yoga. There are two types of yoga sessions:
1. **Type 1**: Lasts 1 hour and earns $X$ amount.
2. **Type 2**: Lasts 2 hours and earns $Y$ amount.

The goal is to maximize the total earnings by choosing an optimal combination of these sessions such that the total time spent does not exceed $N$ hours.

## Intuition & Mathematical Observation
To maximize earnings, we need to consider the efficiency of the sessions:
*   A Type 2 session covers 2 hours and earns $Y$.
*   Two Type 1 sessions cover 2 hours and earn $2 \times X$.

We have two primary strategies to fill the $N$ hours:
1. **Prioritize Type 2 sessions**: Use as many 2-hour blocks as possible. The number of Type 2 sessions is $\lfloor N/2 \rfloor$, and the remaining $N \% 2$ hours are filled with Type 1 sessions. Total earnings: $(\lfloor N/2 \rfloor \times Y) + ((N \% 2) \times X)$.
2. **Use only Type 1 sessions**: If $2 \times X > Y$, it is actually more profitable to perform two 1-hour sessions instead of one 2-hour session. In this case, the total earnings would be $N \times X$.

By comparing these two strategies, we ensure the maximum possible earnings regardless of whether $Y$ is greater than or less than $2X$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculate the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N hours.
 * Type 1: 1 hour, earns X.
 * Type 2: 2 hours, earns Y.
 * 
 * We compare two strategies:
 * 1. Maximize Type 2 sessions: (N / 2) * Y + (N % 2) * X
 * 2. Use only Type 1 sessions: N * X
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;
        
        // Strategy 1: Use as many 2-hour blocks as possible
        long long num_type2 = n / 2;
        long long num_type1 = n % 2;
        long long earnings_with_type2 = (num_type2 * y) + (num_type1 * x);
        
        // Strategy 2: Use only 1-hour blocks
        long long earnings_only_type1 = n * x;
        
        // The answer is the maximum of the two strategies
        cout << max(earnings_with_type2, earnings_only_type1) << "\n";
    }

    return 0;
}
```