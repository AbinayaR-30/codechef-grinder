# [Bus Seating (BUSSEAT)](https://www.codechef.com/problems/BUSSEAT)

- **Difficulty Rating**: 640
- **Solved in**: 1 attempt(s)

## Problem Summary
A bus has $N$ rows, each containing 2 seats. Passengers board the bus one by one and follow a specific seating preference:
1. They prefer to sit in an empty row.
2. If no empty row is available, they sit in a row that already has one person.

We need to calculate the total number of people who end up sitting next to someone.

## Intuition & Mathematical Observation
The seating process can be broken down into two phases:

1. **Phase 1 (Empty Rows):** As long as there are empty rows, the first $N$ people will each occupy one seat in a unique row. At the end of this phase, there are $N$ rows, each containing exactly one person. Since no one is sharing a row, the number of people sitting next to someone is **0**.
   - Condition: $K \le N$
   - Result: $0$

2. **Phase 2 (Occupied Rows):** Once all $N$ rows are occupied by one person, any additional passenger ($K - N$) must sit in a row that already has one person. 
   - When a new person sits in a row that already has one person, both the person who was already there and the new person are now "sitting next to someone."
   - Therefore, each of the $(K - N)$ new passengers creates a pair of people sitting next to each other.
   - Total people sitting next to someone = $(K - N) \times 2$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses simple arithmetic operations. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are N rows, each with 2 seats. Total seats = 2N.
 * 
 * If K <= N:
 * Each person takes one row. No one sits next to anyone. Result = 0.
 * 
 * If K > N:
 * The first N people occupy one seat in each of the N rows.
 * The remaining (K - N) people must sit in a row that already has 1 person.
 * Each of these (K - N) people creates a pair (themselves + the person already there).
 * Total = (K - N) * 2.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (k <= n) {
            cout << 0 << "\n";
        } else {
            // The number of people who end up sitting next to someone is 2 * (K - N)
            cout << (k - n) * 2 << "\n";
        }
    }

    return 0;
}
```