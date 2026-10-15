# [Double Discount (DBDISC)](https://www.codechef.com/problems/DBDISC)

- **Difficulty Rating**: 994
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ items, each with a cost $A_i$ and a tastiness value $B_i$. You must select exactly two distinct items $i$ and $j$ to purchase. The pricing rule is as follows:
1. Identify the more expensive item ($M = \max(A_i, A_j)$) and the cheaper item ($m = \min(A_i, A_j)$).
2. Apply a discount to the more expensive item: the new price of the expensive item becomes $M - \min(\lfloor M/2 \rfloor, 100)$.
3. The total cost is $m + (M - \min(\lfloor M/2 \rfloor, 100))$.
4. You must find the maximum possible sum of tastiness ($B_i + B_j$) such that the total cost is less than or equal to $K$. If no such pair exists, output 0.

## Intuition & Mathematical Observation
Given the constraints $N \le 100$, an $O(N^2)$ approach is highly efficient. We can iterate through every possible pair of items $(i, j)$ where $i < j$. 

For each pair:
- Calculate the effective cost using the provided formula.
- Check if the calculated cost is $\le K$.
- If valid, update the `max_tastiness` variable with the sum $B_i + B_j$.
- Since we need to maximize the sum, we initialize `max_tastiness` to 0 and track the best result found across all valid pairs.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$ per test case, where $N$ is the number of items. With $N=100$, $N^2 = 10,000$, which easily passes within the time limit even with multiple test cases.
- **Space Complexity**: $O(N)$ to store the arrays $A$ and $B$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to select exactly two items (i, j) where i != j.
 * Let the costs be A[i] and A[j].
 * Let the more expensive item be M = max(A[i], A[j]) and the cheaper be m = min(A[i], A[j]).
 * The discount on M is min(M / 2, 100).
 * The final cost is m + (M - min(M / 2, 100)).
 * We want to maximize B[i] + B[j] subject to final cost <= K.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    int max_tastiness = 0;
    bool possible = false;

    // Iterate through all unique pairs (i, j)
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int cost1 = A[i];
            int cost2 = A[j];
            
            int M = max(cost1, cost2);
            int m = min(cost1, cost2);
            
            // Apply the discount rule
            int discount = min(M / 2, 100);
            int final_cost = m + (M - discount);
            
            // Check if the pair is affordable
            if (final_cost <= K) {
                possible = true;
                max_tastiness = max(max_tastiness, B[i] + B[j]);
            }
        }
    }

    if (!possible) {
        cout << 0 << "\n";
    } else {
        cout << max_tastiness << "\n";
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