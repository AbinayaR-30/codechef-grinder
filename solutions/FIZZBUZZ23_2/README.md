# [Survival Time (FIZZBUZZ23_2)](https://www.codechef.com/problems/FIZZBUZZ23_2)

- **Difficulty Rating**: 716
- **Solved in**: 1 attempt(s)

## Problem Summary
A family of 5 members needs to survive for a certain number of days. Each member consumes $X$ buns per day. You are given $N$ total buns and an additional $D$ days of survival time provided by other food sources. You need to calculate the total number of days the family can survive, considering both the buns and the extra $D$ days.

## Intuition & Mathematical Observation
1. **Daily Consumption**: Since there are 5 family members and each consumes $X$ buns, the total consumption per day is $5 \times X$.
2. **Buns Sustainability**: The number of days the buns will last is determined by dividing the total number of buns $N$ by the daily consumption rate ($5 \times X$). Using integer division (`N / (5 * X)`) automatically handles cases where there are fewer buns than required for a full day, resulting in 0 days.
3. **Total Survival Time**: The family survives for the duration the buns last plus the additional $D$ days provided by other sources. 
   - Formula: $\text{Total Days} = \lfloor \frac{N}{5 \times X} \rfloor + D$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. For $T$ test cases, the total complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total family members = 5.
 * Daily consumption = 5 * X.
 * Number of days the buns last = floor(N / (5 * X)).
 * Total survival days = (days buns last) + D.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x, d;
        cin >> n >> x >> d;

        // Total buns consumed by the family per day
        long long daily_consumption = 5 * x;

        // Number of days the buns can sustain the family
        // Integer division handles the "not enough buns" condition automatically
        long long days_with_buns = n / daily_consumption;

        // Total survival time is the days with buns plus the extra D days
        long long total_days = days_with_buns + d;

        cout << total_days << "\n";
    }

    return 0;
}
```