# [Minimum Maximum (MNMX)](https://www.codechef.com/problems/MNMX)

- **Difficulty Rating**: 1392
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, we perform an operation where we select an adjacent pair $(A[i], A[i+1])$, remove the larger element, and incur a cost equal to the smaller element. This process repeats until only one element remains. The goal is to minimize the total cost of reducing the array to a single element.

## Intuition & Mathematical Observation
To minimize the total cost, we want to ensure that the cost incurred in each of the $N-1$ operations is as small as possible. 

1. **The Strategy**: The smallest element in the array (`min_val`) is the smallest possible value we can pay for any operation. If we can ensure that `min_val` is involved in every operation, we will achieve the global minimum cost.
2. **Feasibility**: Since we can choose any adjacent pair, we can always target the neighbors of the minimum element. By repeatedly using the minimum element to "eliminate" its neighbors, we ensure that the cost of each of the $N-1$ operations is exactly `min_val`.
3. **Calculation**: Since we perform $N-1$ operations and each operation costs `min_val`, the total cost is simply:
   $$\text{Total Cost} = \text{min\_val} \times (N - 1)$$
4. **Data Types**: Given $N \le 50,000$ and $A_i \le 10^5$, the maximum possible cost is approximately $5 \times 10^9$. This exceeds the capacity of a standard 32-bit `int`, so we must use `long long` to prevent overflow.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we only need to iterate through the array once to find the minimum element.
- **Space Complexity**: $O(1)$, as we only store the minimum value and the current input, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array of N distinct integers.
 * Operation: Select adjacent pair (A[i], A[i+1]), remove the larger one, cost = smaller one.
 * We need to reduce the array to a single element.
 * 
 * Let the minimum element in the array be 'min_val'.
 * To minimize the total cost, we want to use 'min_val' as the cost for as many operations as possible.
 * Since we can pick any adjacent pair, we can always choose to keep the minimum element 
 * and use it to eliminate all other elements one by one.
 * 
 * Total cost = min_val * (N - 1).
 */

void solve() {
    int n;
    cin >> n;
    
    long long min_val = 200000; // Larger than max possible Ai (10^5)
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        if (val < min_val) {
            min_val = val;
        }
    }
    
    // The minimum element will be the cost for all N-1 operations
    // Use long long to prevent overflow (max cost ~ 5 * 10^9)
    long long total_cost = min_val * (long long)(n - 1);
    cout << total_cost << "\n";
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