# [Chef and Pairing Slippers (CHEFSLP)](https://www.codechef.com/problems/CHEFSLP)

- **Difficulty Rating**: 930
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ slippers in total, consisting of $L$ left slippers and $R$ right slippers (where $R = N - L$). A pair of slippers consists of one left and one right slipper. Given that each pair can be sold for $X$ rupees, calculate the maximum total revenue Chef can earn by selling as many pairs as possible.

## Intuition & Mathematical Observation
1. **Identify the limiting factor**: To form a pair, we need exactly one left slipper and one right slipper. If we have $L$ left slippers and $R$ right slippers, the number of complete pairs we can form is limited by the smaller of the two quantities.
2. **Calculate pairs**: The number of pairs is given by $\min(L, R)$. Since $R = N - L$, the formula becomes $\min(L, N - L)$.
3. **Calculate revenue**: Once the number of pairs is determined, the total revenue is simply the number of pairs multiplied by the price per pair ($X$).
4. **Data Types**: While the constraints ($N, L, X \le 1000$) allow the result to fit in a standard 32-bit integer, using `long long` is a good practice to prevent overflow in similar problems with larger constraints.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of arithmetic operations, the total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total slippers = N
 * Left slippers = L
 * Right slippers = R = N - L
 * A pair consists of one left and one right slipper.
 * The number of pairs that can be formed is limited by the minimum of the 
 * number of left slippers and the number of right slippers.
 * Pairs = min(L, N - L)
 * Total revenue = Pairs * X
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, l, x;
        cin >> n >> l >> x;

        // Calculate number of right slippers
        long long r = n - l;

        // Number of pairs is the minimum of left and right slippers
        long long pairs = min(l, r);

        // Total earnings
        long long result = pairs * x;

        cout << result << "\n";
    }

    return 0;
}
```