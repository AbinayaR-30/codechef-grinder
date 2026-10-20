# [Vaccine Production (VACCINE1)](https://www.codechef.com/problems/VACCINE1)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given two companies that start producing vaccines on different days ($D_1$ and $D_2$) with different daily production rates ($V_1$ and $V_2$). We need to determine the earliest day $d$ such that the cumulative number of vaccines produced by both companies combined reaches or exceeds a target value $P$.

## Intuition & Mathematical Observation
The total number of vaccines produced is a monotonically increasing function of time. 
- Company 1 contributes $V_1$ vaccines per day starting from day $D_1$.
- Company 2 contributes $V_2$ vaccines per day starting from day $D_2$.

Given the constraints ($D, V \le 100$ and $P \le 1000$), the total number of days required will be relatively small. A **linear simulation** approach is highly efficient here. We simply increment the day counter one by one, check if the current day is greater than or equal to the start day for each company, add their respective production rates to a running total, and stop once the total reaches $P$.

## Complexity Analysis
- **Time Complexity**: $O(P / \min(V_1, V_2))$, which simplifies to $O(P)$ in the worst case. Given $P \le 1000$, this performs well within the time limits.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to track the state.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two companies producing vaccines starting from day D1 and D2 with rates V1 and V2.
 * We need to find the smallest day 'd' such that the total vaccines produced >= P.
 * 
 * Total vaccines produced by day 'd':
 * - Company A produces (d - D1 + 1) * V1 vaccines if d >= D1, else 0.
 * - Company B produces (d - D2 + 1) * V2 vaccines if d >= D2, else 0.
 * 
 * Since the number of vaccines produced is monotonically increasing with 'd',
 * we can either use binary search or a simple linear simulation.
 * Given the constraints (D, V <= 100, P <= 1000), a linear simulation is O(P) 
 * which is well within the time limit.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D1, V1, D2, V2, P;
    if (!(cin >> D1 >> V1 >> D2 >> V2 >> P)) return 0;

    int total_vaccines = 0;
    int day = 0;

    // Simulate day by day until total_vaccines >= P
    while (total_vaccines < P) {
        day++;
        if (day >= D1) {
            total_vaccines += V1;
        }
        if (day >= D2) {
            total_vaccines += V2;
        }
    }

    cout << day << "\n";

    return 0;
}
```