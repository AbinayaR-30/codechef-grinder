# [Change Please (CHANGE_PLZ)](https://www.codechef.com/problems/CHANGE_PLZ)

- **Difficulty Rating**: 760
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given an amount $X$ that you owe for a ride. You pay the driver 100 dollars. The driver needs to return the change, but they only possess 10-dollar bills. You need to calculate the total amount the driver can return to you, which is the largest multiple of 10 that is less than or equal to the actual change due ($100 - X$).

## Intuition & Mathematical Observation
1. **Calculate Change Due**: The total change you are owed is $R = 100 - X$.
2. **Constraint**: The driver can only return multiples of 10.
3. **Mathematical Logic**: To find the largest multiple of 10 less than or equal to $R$, we can use integer division. In C++, dividing an integer by 10 truncates the decimal part (e.g., $87 / 10 = 8$). Multiplying this result back by 10 gives the largest multiple of 10 less than or equal to the original number (e.g., $8 \times 10 = 80$).
4. **Formula**: `result = ( (100 - X) / 10 ) * 10`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * You owe X dollars. You give 100 dollars.
 * The change due is (100 - X).
 * The driver only has 10 dollar bills.
 * The driver can pay back the largest multiple of 10 that is less than or equal to (100 - X).
 * 
 * Let R = 100 - X.
 * We need to find the largest multiple of 10 <= R.
 * This is equivalent to (R / 10) * 10 using integer division.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x;
        cin >> x;
        
        // Calculate the amount the driver owes back
        int change_due = 100 - x;
        
        // The driver can only return multiples of 10.
        // Integer division by 10 truncates the remainder, 
        // effectively finding the floor of the number of 10-dollar bills.
        int result = (change_due / 10) * 10;
        
        cout << result << "\n";
    }
    
    return 0;
}
```