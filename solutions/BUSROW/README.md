# [Bus Rows (BUSROW)](https://www.codechef.com/problems/BUSROW)

- **Difficulty Rating**: 727
- **Solved in**: 1 attempt(s)

## Problem Summary
A bus has $N$ rows, each containing $M$ seats. The seats are numbered sequentially from $1$ to $N \times M$. Given a specific seat number $X$, we need to determine the minimum number of rows one must walk past to reach the row containing seat $X$, considering the option to enter from either the front of the bus (row 1) or the back of the bus (row $N$).

## Intuition & Mathematical Observation
1.  **Finding the Row ($R$):** Since each row contains $M$ seats, the seats in row $i$ range from $(i-1) \times M + 1$ to $i \times M$. Using 1-based indexing, the row number $R$ for seat $X$ can be calculated using integer division:
    $$R = \lfloor \frac{X - 1}{M} \rfloor + 1$$

2.  **Calculating Distances:**
    *   **From the front:** If you enter from the front, you walk through rows $1, 2, \dots, R$. The number of rows traversed is simply $R$.
    *   **From the back:** If you enter from the back, you walk through rows $N, N-1, \dots, R$. The number of rows traversed is $N - R + 1$.

3.  **Optimization:** The goal is to find the minimum of these two values: $\min(R, N - R + 1)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated row number.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The bus has N rows, each with M seats.
 * Seat X is in row R.
 * To find R:
 * Since row i contains seats (i-1)*M + 1 to i*M,
 * we can calculate R using integer division:
 * R = (X - 1) / M + 1.
 * 
 * If we enter from the front, we walk through rows 1, 2, ..., R.
 * The number of rows walked is R.
 * 
 * If we enter from the back, we walk through rows N, N-1, ..., R.
 * The number of rows walked is (N - R + 1).
 * 
 * We need to find the minimum of these two values: min(R, N - R + 1).
 */

void solve() {
    long long N, M, X;
    if (!(cin >> N >> M >> X)) return;

    // Calculate the row number R (1-indexed)
    long long R = (X - 1) / M + 1;

    // Distance from front: R
    // Distance from back: N - R + 1
    long long dist_front = R;
    long long dist_back = N - R + 1;

    cout << min(dist_front, dist_back) << "\n";
}

int main() {
    // Fast I/O setup
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