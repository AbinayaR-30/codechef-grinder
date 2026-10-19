#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct an N x N matrix with numbers 1 to N^2 such that for any square submatrix,
 * the sum of the corners is even.
 * 
 * The condition M[r,c] + M[r+a,c+a] is even implies M[r,c] and M[r+a,c+a] have the same parity.
 * Similarly, M[r,c+a] and M[r+a,c] must have the same parity.
 * 
 * A simple way to satisfy this is to fill the matrix such that the parity of the cells
 * follows a checkerboard pattern or a specific row-based pattern.
 * 
 * Strategy:
 * Fill the matrix row by row with numbers 1 to N^2.
 * If we fill row 1: 1, 2, ..., N
 * Row 2: N+1, N+2, ..., 2N
 * ...
 * To ensure the parity condition, we can reverse the order of numbers in every second row.
 * This ensures that the parity of elements in any column or row alternates or stays consistent
 * in a way that the sum of corners of any square submatrix is always even.
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