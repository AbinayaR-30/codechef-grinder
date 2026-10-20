# [Expensive Buying (BUYING7)](https://www.codechef.com/problems/BUYING7)

- **Difficulty Rating**: 635
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a list of $N$ item prices, we need to calculate the total cost of the $K$ most expensive items. We are provided with $T$ test cases, where for each case, we receive $N$ (the total number of items) and $K$ (the number of items to select), followed by the list of prices.

## Intuition & Mathematical Observation
To find the sum of the $K$ most expensive items, we need to identify the largest values in the given array. 
1. **Sorting**: By sorting the array of prices in ascending order, the largest values will naturally be positioned at the end of the array (from index $N-K$ to $N-1$).
2. **Summation**: Once sorted, we simply iterate through the last $K$ elements of the array and accumulate their sum.
3. **Data Types**: Since the sum of prices might exceed the capacity of a 32-bit integer, we use `long long` to store the `total_cost` to prevent overflow.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \log N)$, where $N \log N$ is the cost of sorting the array for each of the $T$ test cases. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(N)$, as we store the $N$ prices in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Expensive Buying
 * Approach:
 * To find the sum of the K most expensive items, we can sort the array of prices
 * in ascending order and sum the last K elements.
 * 
 * Time Complexity: O(T * N log N)
 * Space Complexity: O(N)
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    
    vector<long long> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }
    
    // Sort the prices in ascending order
    sort(C.begin(), C.end());
    
    // Sum the last K elements (the K most expensive)
    long long total_cost = 0;
    for (int i = N - 1; i >= N - K; --i) {
        total_cost += C[i];
    }
    
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```