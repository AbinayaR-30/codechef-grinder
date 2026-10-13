# [Which Fuel is Cheaper (CHEAPFUEL)](https://www.codechef.com/problems/CHEAPFUEL)

- **Difficulty Rating**: 926
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the initial prices of petrol ($X$) and diesel ($Y$). Every month, the price of petrol increases by $A$ and the price of diesel increases by $B$. We need to determine which fuel will be cheaper after $K$ months. If the prices are equal after $K$ months, we should output "SAME PRICE".

## Intuition & Mathematical Observation
The price of a fuel after $K$ months can be calculated using a simple linear growth formula:
- **Final Petrol Price**: $P_{final} = X + (A \times K)$
- **Final Diesel Price**: $D_{final} = Y + (B \times K)$

By calculating these two values, we can directly compare them:
1. If $P_{final} < D_{final}$, petrol is cheaper.
2. If $D_{final} < P_{final}$, diesel is cheaper.
3. If $P_{final} == D_{final}$, both fuels cost the same.

Since the constraints are small (up to 1000), standard integer arithmetic is sufficient, though `long long` is used to ensure safety against potential overflow in larger variations of this problem.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of arithmetic operations and comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculated results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial price of petrol: X
 * Initial price of diesel: Y
 * Monthly increase for petrol: A
 * Monthly increase for diesel: B
 * Number of months: K
 * 
 * Price of petrol after K months: X + (A * K)
 * Price of diesel after K months: Y + (B * K)
 */

void solve() {
    long long X, Y, A, B, K;
    if (!(cin >> X >> Y >> A >> B >> K)) return;

    // Calculate final prices after K months
    long long final_petrol = X + (A * K);
    long long final_diesel = Y + (B * K);

    // Compare the results
    if (final_petrol < final_diesel) {
        cout << "PETROL" << "\n";
    } else if (final_diesel < final_petrol) {
        cout << "DIESEL" << "\n";
    } else {
        cout << "SAME PRICE" << "\n";
    }
}

int main() {
    // Fast I/O setup for performance
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