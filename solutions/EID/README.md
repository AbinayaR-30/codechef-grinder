# [Chef and Eid (EID)](https://www.codechef.com/problems/EID)

- **Difficulty Rating**: 1135
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ coins with various values, the goal is to select two distinct coins such that the absolute difference between their values is minimized. We need to output this minimum difference.

## Intuition & Mathematical Observation
To minimize the difference $|v_i - v_j|$ between any two elements in an array, the most efficient approach is to sort the array first. 

**Why sorting works:**
1. Once the array is sorted in non-decreasing order ($a_1 \le a_2 \le \dots \le a_N$), the smallest difference between any two elements must exist between two **adjacent** elements.
2. If we consider any two non-adjacent elements $a_i$ and $a_j$ (where $j > i+1$), the difference $a_j - a_i$ can be expressed as the sum of differences of adjacent elements: $(a_j - a_{j-1}) + (a_{j-1} - a_{j-2}) + \dots + (a_{i+1} - a_i)$.
3. Since all coin values are non-negative, each individual term $(a_{k+1} - a_k)$ is $\ge 0$. Therefore, the sum of these differences will always be greater than or equal to any single adjacent difference.
4. Thus, we only need to calculate $a_{i+1} - a_i$ for all $i$ from $0$ to $N-2$ and track the minimum value found.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case, dominated by the sorting step. The subsequent linear scan takes $O(N)$. Given the constraint $\sum N \le 5 \times 10^5$, this approach is well within the time limits.
- **Space Complexity**: $O(N)$ to store the coin values in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N coins with values v_1, v_2, ..., v_N.
 * We need to choose two distinct coins such that the absolute difference 
 * between their values is minimized.
 * 
 * Strategy:
 * 1. If we sort the array of coin values in non-decreasing order, the minimum 
 *    difference between any two elements must occur between two adjacent 
 *    elements in the sorted array.
 * 2. Proof: Suppose we have sorted values a_1 <= a_2 <= ... <= a_N.
 *    For any i < j, the difference a_j - a_i = (a_j - a_{j-1}) + (a_{j-1} - a_{j-2}) + ... + (a_{i+1} - a_i).
 *    Since all terms are non-negative, a_j - a_i >= a_{k+1} - a_k for any k in [i, j-1].
 *    Thus, the minimum difference must be found among adjacent pairs.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    
    // Sort the coins to bring values with minimal differences next to each other
    sort(v.begin(), v.end());
    
    long long min_diff = -1;
    
    // Iterate through adjacent elements to find the minimum difference
    for (int i = 0; i < N - 1; ++i) {
        long long current_diff = v[i + 1] - v[i];
        if (min_diff == -1 || current_diff < min_diff) {
            min_diff = current_diff;
        }
    }
    
    cout << min_diff << "\n";
}

int main() {
    // Fast I/O setup
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