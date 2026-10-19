# [Reselling Items (RESELL)](https://www.codechef.com/problems/RESELL)

- **Difficulty Rating**: 903
- **Solved in**: 2 attempt(s)

## Problem Summary
You are given $N$ items, each with a specific resale value $A_i$. You have $K$ slots available at a cost of 5 per item, and an infinite number of slots available at a cost of 10 per item. The goal is to select items to resell such that the total profit is maximized. An item should only be resold if the resale value exceeds the cost of the slot used.

## Intuition & Mathematical Observation
To maximize profit, we must prioritize using the cheaper slots (cost 5) for the items that yield the highest potential profit.

1.  **Sorting**: By sorting the resale values $A_i$ in descending order, we ensure that the most valuable items are considered first.
2.  **Greedy Allocation**:
    *   The first $K$ items (the most valuable ones) should be assigned to the slots costing 5. If $A_i > 5$, we add $(A_i - 5)$ to our total profit.
    *   Any remaining items (from index $K$ to $N-1$) should be assigned to the slots costing 10. If $A_i > 10$, we add $(A_i - 10)$ to our total profit.
3.  **Profit Condition**: If an item's resale value is less than or equal to the cost of the slot, it is better not to resell it (profit $\le 0$), so we ignore it.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan through the array takes $O(N)$, making the overall complexity dominated by the sort.
- **Space Complexity**: $O(N)$ to store the resale values of the $N$ items.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N items with resale values A_i.
 * We have K slots that cost 5, and infinite slots that cost 10.
 * To maximize profit:
 * 1. Sort A_i in descending order.
 * 2. The best items should occupy the K slots (cost 5).
 * 3. Any remaining items that provide positive profit at cost 10 should be bought.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort descending to prioritize higher resale values
    sort(A.rbegin(), A.rend());

    long long total_profit = 0;

    for (int i = 0; i < N; ++i) {
        if (i < K) {
            // These items cost 5
            if (A[i] > 5) {
                total_profit += (A[i] - 5);
            }
        } else {
            // These items cost 10
            if (A[i] > 10) {
                total_profit += (A[i] - 10);
            }
        }
    }

    cout << total_profit << "\n";
}

int main() {
    // Fast I/O
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