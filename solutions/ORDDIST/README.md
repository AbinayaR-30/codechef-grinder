# [Ordered Distances (ORDDIST)](https://www.codechef.com/problems/ORDDIST)

- **Difficulty Rating**: 1112
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an initial sequence $X$ of length $N$ and a target sequence $Y$, we need to determine if there exists a "pivot" element $P$ chosen from the elements of $X$ such that $Y$ is the result of sorting the elements of $X$ based on their distance from $P$. Specifically, for each element $X_j$, we consider the pair $(|X_j - P|, X_j)$. The sequence $Y$ must match the sequence of $X_j$ values when these pairs are sorted primarily by distance ($|X_j - P|$) in ascending order, and secondarily by the value of $X_j$ itself in ascending order. If such a pivot exists, output its 1-based index in the original array $X$; otherwise, output -1.

## Intuition & Mathematical Observation
The constraints are small ($N \le 100$), which suggests that a brute-force approach is feasible. Since there are only $N$ possible candidates for the pivot $P$ (each element $X_i$ in the array), we can simulate the sorting process for every possible pivot.

1. **Simulation**: For each index $i \in [0, N-1]$, we set $P = X[i]$.
2. **Transformation**: We create a list of pairs where each element $X_j$ is transformed into $(|X_j - P|, X_j)$.
3. **Sorting**: We sort this list using the custom criteria:
   - Primary key: Distance $|X_j - P|$ (ascending).
   - Secondary key: The value $X_j$ (ascending).
4. **Verification**: After sorting, we extract the second element of each pair to form a candidate sequence $Y_{calc}$. If $Y_{calc}$ is identical to the input sequence $Y$, then $i+1$ is our answer.

If we iterate through all $N$ possibilities and find no match, we conclude that no such pivot exists and return -1.

## Complexity Analysis
- **Time Complexity**: $O(T \times N^2 \log N)$. For each of the $T$ test cases, we iterate $N$ times. Inside the loop, we perform a sort operation which takes $O(N \log N)$. Given $N=100$, $N^2 \log N \approx 10^4 \times 6.6 \approx 6.6 \times 10^4$ operations per test case, which easily fits within the time limit.
- **Space Complexity**: $O(N)$ to store the sequences $X$, $Y$, and the temporary list of pairs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an initial sequence X and a transformed sequence Y.
 * We need to find a pivot index i (1 <= i <= N) such that if we set P = X[i],
 * the sequence Y is exactly the sequence obtained by sorting the pairs 
 * (|X[j] - P|, X[j]) based on the specified criteria.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; ++i) cin >> X[i];
    for (int i = 0; i < N; ++i) cin >> Y[i];

    // Try each element of X as the pivot P
    for (int i = 0; i < N; ++i) {
        int P = X[i];
        vector<pair<int, int>> L(N);
        for (int j = 0; j < N; ++j) {
            L[j] = {abs(X[j] - P), X[j]};
        }

        // Sort based on the problem definition:
        // Primary: Distance |X[j] - P|
        // Secondary: Value X[j]
        sort(L.begin(), L.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });

        // Check if the generated sequence matches Y
        bool match = true;
        for (int k = 0; k < N; ++k) {
            if (L[k].second != Y[k]) {
                match = false;
                break;
            }
        }

        if (match) {
            cout << i + 1 << "\n";
            return;
        }
    }

    // No valid pivot found
    cout << -1 << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```