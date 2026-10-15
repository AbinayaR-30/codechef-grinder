# [Andrew and the Meatballs (AMMEAT)](https://www.codechef.com/problems/AMMEAT)

- **Difficulty Rating**: 1275
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ plates, each containing a specific number of meatballs. We need to select the minimum number of plates such that the total number of meatballs collected is at least $M$. If it is impossible to reach the target $M$ even by selecting all available plates, we should output -1.

## Intuition & Mathematical Observation
To minimize the number of plates used, we must prioritize plates that contain the highest number of meatballs. This is a classic **Greedy** approach:

1. **Total Capacity Check**: First, calculate the sum of all meatballs across all plates. If this sum is less than $M$, it is physically impossible to satisfy the requirement, so we output -1.
2. **Greedy Selection**: Sort the plates in descending order based on the number of meatballs they contain.
3. **Iterative Accumulation**: Start picking plates from the sorted list one by one. Keep a running total of the meatballs collected. As soon as the running total reaches or exceeds $M$, the number of plates picked is our answer.

Since we are dealing with values up to $10^{18}$, it is crucial to use the `long long` data type in C++ to prevent integer overflow.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case, where $N$ is the number of plates. This is dominated by the sorting step. The subsequent linear scan takes $O(N)$.
- **Space Complexity**: $O(N)$ to store the number of meatballs on each plate.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N plates with P_i meatballs. We need to select the minimum number of plates
 * such that their sum is at least M.
 * 
 * Strategy:
 * 1. To minimize the number of plates, we should always pick the plates with the 
 *    largest number of meatballs first (Greedy approach).
 * 2. Sort the array of meatballs in descending order.
 * 3. Calculate the prefix sum or keep adding elements until the sum >= M.
 * 4. If the total sum of all plates is less than M, it's impossible, return -1.
 */

void solve() {
    int n;
    long long m;
    cin >> n >> m;
    
    vector<long long> p(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        total_sum += p[i];
    }
    
    // If total meatballs available are less than M, impossible.
    if (total_sum < m) {
        cout << -1 << "\n";
        return;
    }
    
    // Sort in descending order to pick largest plates first
    sort(p.rbegin(), p.rend());
    
    long long current_sum = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        current_sum += p[i];
        count++;
        if (current_sum >= m) {
            cout << count << "\n";
            return;
        }
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