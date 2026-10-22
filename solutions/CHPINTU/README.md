# [Pintu and Fruits (CHPINTU)](https://www.codechef.com/problems/CHPINTU)

- **Difficulty Rating**: 1313
- **Solved in**: 3 attempt(s)

## Problem Summary
Pintu has $N$ baskets of fruits, where each basket contains a specific type of fruit (represented by an ID from $1$ to $M$) and has a specific price. Pintu wants to remove all baskets of certain fruit types such that the total cost of the remaining baskets is minimized. However, he must remove **all** baskets of any fruit type he chooses to remove. The goal is to find the minimum total cost of the remaining baskets after choosing to remove one or more fruit types.

## Intuition & Mathematical Observation
The core of the problem is to realize that for every unique fruit type present in the input, we have two choices:
1. **Keep the fruit type**: We must keep *all* baskets of this type, adding their total cost to our final sum.
2. **Remove the fruit type**: We remove *all* baskets of this type, contributing $0$ to the final sum.

Since we want to minimize the total cost, we should calculate the total cost for each fruit type individually. If we decide to keep a set of fruit types, the total cost is simply the sum of the costs of all baskets belonging to those types. To minimize this, we should only keep the fruit type that has the **minimum total cost** among all types present in the input.

**Key steps:**
1. Use an array (or hash map) to aggregate the total price for each fruit type ID.
2. Use a boolean array to keep track of which fruit types actually appeared in the input.
3. Iterate through the aggregated costs and find the minimum value among the types that were present.

## Complexity Analysis
- **Time Complexity**: $O(N + M)$, where $N$ is the number of baskets and $M$ is the number of fruit types. We iterate through the baskets once to aggregate costs and then iterate through the fruit types once to find the minimum.
- **Space Complexity**: $O(M)$, as we use arrays of size $M+1$ to store the total costs and the existence status of each fruit type.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/**
 * Problem Analysis:
 * We need to group the costs of baskets by their fruit type.
 * We use an array `cost` of size M+1 to store the sum of prices for each fruit type.
 * We use an array `exists` to track if a fruit type was present in the input.
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    vector<int> F(N);
    for (int i = 0; i < N; ++i) {
        cin >> F[i];
    }

    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    // cost[i] stores the total price for fruit type i
    // exists[i] tracks if fruit type i is present in any basket
    vector<int> cost(M + 1, 0);
    vector<bool> exists(M + 1, false);

    for (int i = 0; i < N; ++i) {
        cost[F[i]] += P[i];
        exists[F[i]] = true;
    }

    int min_price = INT_MAX;

    // Iterate through all possible fruit types
    for (int i = 1; i <= M; ++i) {
        if (exists[i]) {
            if (cost[i] < min_price) {
                min_price = cost[i];
            }
        }
    }

    cout << min_price << "\n";
}

int main() {
    // Optimize I/O operations
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