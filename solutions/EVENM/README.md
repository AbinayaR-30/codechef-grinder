# [Even Matrix (EVENM)](https://www.codechef.com/problems/EVENM)

- **Difficulty Rating**: 1376
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to construct an $N \times N$ matrix containing all integers from $1$ to $N^2$ exactly once. The constraint is that for any square submatrix, the sum of its four corners must be even.

## Intuition & Mathematical Observation
The condition that the sum of the four corners $(r, c), (r, c+a), (r+a, c), (r+a, c+a)$ is even implies that:
$M[r, c] + M[r+a, c+a] \equiv M[r, c+a] + M[r+a, c] \pmod 2$

This is satisfied if the parity of the numbers follows a pattern where adjacent cells have alternating parities. By filling the matrix row-by-row with numbers $1$ to $N^2$, we can maintain the parity condition by reversing the filling direction for every odd-indexed row (0-indexed).

- **Even rows (0, 2, ...):** Fill from left to right ($1, 2, \dots, N$).
- **Odd rows (1, 3, ...):** Fill from right to left ($N+1, N+2, \dots, 2N$).

This "snake-like" filling pattern ensures that the parity of the numbers shifts consistently, satisfying the corner-sum property for any square submatrix.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$, as we iterate through each cell of the $N \times N$ matrix exactly once to print the values.
- **Space Complexity**: $O(N)$ to store a single row before printing, or $O(1)$ if printing directly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct an N x N matrix with numbers 1 to N^2 such that for any square submatrix,
 * the sum of the corners is even.
 * 
 * Strategy:
 * Fill the matrix row by row with numbers 1 to N^2.
 * To ensure the parity condition, we reverse the order of numbers in every second row.
 * This ensures that the parity of elements in any column or row alternates in a way 
 * that the sum of corners of any square submatrix is always even.
 */

void solve() {
    int N;
    cin >> N;
    
    int current = 1;
    for (int i = 0; i < N; ++i) {
        vector<int> row(N);
        if (i % 2 == 0) {
            // Fill left to right
            for (int j = 0; j < N; ++j) {
                row[j] = current++;
            }
        } else {
            // Fill right to left
            for (int j = N - 1; j >= 0; --j) {
                row[j] = current++;
            }
        }
        
        // Print the row
        for (int j = 0; j < N; ++j) {
            cout << row[j] << (j == N - 1 ? "" : " ");
        }
        cout << "\n";
    }
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