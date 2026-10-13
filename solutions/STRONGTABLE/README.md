# [Table Strength (STRONGTABLE)](https://www.codechef.com/problems/STRONGTABLE)

- **Difficulty Rating**: 1211
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ table legs, each with a specific strength $W_i$. If you choose a subset of $k$ legs to support a table, the weight $X$ that the table can support is limited by the weakest leg in that subset. Specifically, if the minimum strength among the chosen $k$ legs is $W_{min}$, each leg can support at most $W_{min}$ weight. Therefore, the total weight the table can support is $X = k \times W_{min}$. The goal is to choose a subset of legs that maximizes this total weight $X$.

## Intuition & Mathematical Observation
To maximize the product $k \times W_{min}$, we need to be strategic about which legs to include:

1. **Sorting**: If we sort the leg strengths in non-decreasing order ($W_0 \le W_1 \le \dots \le W_{N-1}$), it becomes easier to evaluate subsets.
2. **Subset Selection**: If we decide that a specific leg $W_i$ will be the "weakest" leg in our subset, then to maximize the total weight, we should include all legs that are at least as strong as $W_i$. In our sorted array, these are all legs from index $i$ to $N-1$.
3. **Calculation**: 
   - The number of legs in this subset is $k = (N - i)$.
   - The minimum strength in this subset is $W_i$.
   - The total weight supported is $(N - i) \times W_i$.
4. **Optimization**: By iterating through every possible index $i$ from $0$ to $N-1$ and calculating $(N - i) \times W_i$, we can track the maximum value found. This covers all optimal subset configurations because any subset's potential is defined by its minimum element.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case, dominated by the sorting step. The subsequent linear scan takes $O(N)$.
- **Space Complexity**: $O(N)$ to store the input array of leg strengths.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Suppose we choose a subset of k legs with strengths W_{i_1}, W_{i_2}, ..., W_{i_k}.
 * Let the minimum strength in this subset be W_min.
 * If we place a weight X on this table, each leg bears X/k.
 * To prevent any leg from breaking, we must have X/k <= W_min, which means X <= k * W_min.
 * To maximize X for a fixed subset, we should choose the subset such that k * W_min is maximized.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    
    // Sort the weights in non-decreasing order
    sort(w.begin(), w.end());
    
    long long max_weight = 0;
    
    // For each leg i, consider it as the minimum strength leg in a subset
    // containing all legs from i to n-1.
    for (int i = 0; i < n; ++i) {
        long long count = (long long)(n - i);
        long long current_weight = count * w[i];
        if (current_weight > max_weight) {
            max_weight = current_weight;
        }
    }
    
    cout << max_weight << "\n";
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