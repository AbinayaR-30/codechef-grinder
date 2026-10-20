# [Lost Weekends (LOSTWKND)](https://www.codechef.com/problems/LOSTWKND)

- **Difficulty Rating**: 1063
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has 5 weekdays, and for each day $i$, he has $A_i$ hours of work to complete. Each hour of office work requires $P$ hours of effort. We need to determine if Chef can complete all his work within the 120 hours available during the 5 weekdays (5 days $\times$ 24 hours/day). If the total required effort exceeds 120 hours, he must work on the weekend.

## Intuition & Mathematical Observation
1. **Total Work Calculation**: The total effort required is the sum of work hours for all 5 days multiplied by the conversion factor $P$:
   $$\text{Total Work} = (A_1 + A_2 + A_3 + A_4 + A_5) \times P$$
2. **Constraint Check**: The total time available in the 5 weekdays is fixed at $5 \times 24 = 120$ hours.
3. **Decision Logic**:
   - If $\text{Total Work} > 120$, Chef cannot finish within the weekdays, so output `"Yes"`.
   - Otherwise, he can finish within the weekdays, so output `"No"`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations. For $T$ test cases, the complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated sum.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has 5 weekdays. For each day i, he has A_i hours of work to do at the office.
 * 1 hour of office work = P hours of home work.
 * Total work required in home hours = (A_1 + A_2 + A_3 + A_4 + A_5) * P.
 * Total available hours in 5 weekdays = 5 * 24 = 120 hours.
 * 
 * If the total work required exceeds 120 hours, Chef must work on the weekend.
 * Otherwise, he can complete the work within the 5 weekdays.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a1, a2, a3, a4, a5, p;
        cin >> a1 >> a2 >> a3 >> a4 >> a5 >> p;
        
        // Calculate total work in home hours
        long long total_work = (a1 + a2 + a3 + a4 + a5) * p;
        
        // Total available hours in 5 days (24 hours per day)
        long long total_available = 5 * 24;
        
        // If total work exceeds available hours, he must work on weekends
        if (total_work > total_available) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}
```