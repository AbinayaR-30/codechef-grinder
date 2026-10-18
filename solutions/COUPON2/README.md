# [Chef and Coupon (COUPON2)](https://www.codechef.com/problems/COUPON2)

- **Difficulty Rating**: 1222
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to order food for two days. Each day, he orders three items. There is a delivery charge $D$ for each order unless the total cost of items on that day is at least $150$. Chef can purchase a coupon for price $C$, which makes the delivery charge $0$ for both days, but he still has to pay the coupon price $C$. We need to determine if buying the coupon is strictly cheaper than not buying it.

## Intuition & Mathematical Observation
To solve this, we calculate the total cost under two scenarios:

1.  **Without Coupon:**
    *   Chef pays for all items on Day 1 ($SumA$) and Day 2 ($SumB$).
    *   Chef pays the delivery charge $D$ for both days regardless of the order value.
    *   `Total = SumA + SumB + 2 * D`

2.  **With Coupon:**
    *   Chef pays for all items on Day 1 ($SumA$) and Day 2 ($SumB$).
    *   Chef pays the coupon price $C$.
    *   Delivery charges are waived only if the daily total is $\ge 150$.
    *   `Total = SumA + SumB + C + (delivery_day1) + (delivery_day2)`
        *   Where `delivery_day` is $0$ if the day's sum $\ge 150$, otherwise it is $D$.

We compare these two totals. If `costWith < costWithout`, the answer is "YES"; otherwise, it is "NO".

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the sums and costs, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Cost without coupon: (SumA + D) + (SumB + D) = SumA + SumB + 2*D
 * - Cost with coupon: SumA + SumB + C + (delivery_charge_day1) + (delivery_charge_day2)
 *   - delivery_charge_day1 = (SumA >= 150) ? 0 : D
 *   - delivery_charge_day2 = (SumB >= 150) ? 0 : D
 * 
 * Chef buys the coupon if: Cost_with_coupon < Cost_without_coupon
 */

void solve() {
    long long D, C;
    cin >> D >> C;
    
    long long A1, A2, A3;
    cin >> A1 >> A2 >> A3;
    long long sumA = A1 + A2 + A3;
    
    long long B1, B2, B3;
    cin >> B1 >> B2 >> B3;
    long long sumB = B1 + B2 + B3;
    
    // Cost without coupon
    long long costWithout = sumA + sumB + 2 * D;
    
    // Cost with coupon
    long long deliveryDay1 = (sumA >= 150) ? 0 : D;
    long long deliveryDay2 = (sumB >= 150) ? 0 : D;
    long long costWith = sumA + sumB + C + deliveryDay1 + deliveryDay2;
    
    if (costWith < costWithout) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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