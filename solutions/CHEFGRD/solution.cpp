#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The grid size N is odd, and the center is at (C, C) where C = (N + 1) / 2.
 * Diagonal moves are free (cost 0).
 * Horizontal/Vertical moves cost 1.
 * 
 * A move (dx, dy) is diagonal if |dx| == |dy|.
 * A move (dx, dy) is horizontal/vertical if (|dx| == 1 and dy == 0) or (dx == 0 and |dy| == 1).
 * 
 * Let the center be (C, C). We are at (x, y).
 * The parity of the sum of coordinates (x + y) changes with every horizontal/vertical move.
 * Specifically, if we move (x, y) -> (x+1, y), the sum changes from (x+y) to (x+y+1).
 * Diagonal moves (x, y) -> (x+1, y+1) keep the parity of (x+y) constant (sum changes by 2).
 * 
 * The center (C, C) has a coordinate sum of 2C = N + 1, which is always even.
 * If (x + y) is even, the parity matches the center, meaning we can reach the center 
 * using only diagonal moves (cost 0).
 * If (x + y) is odd, the parity does not match the center, meaning we must make 
 * at least one horizontal/vertical move (cost 1).
 */

void solve() {
    long long N, xs, ys;
    cin >> N >> xs >> ys;
    
    long long center = (N + 1) / 2;
    
    // Calculate the parity of the distance from the center.
    // If (xs + ys) and (center + center) have the same parity, 
    // the cost is 0. Otherwise, the cost is 1.
    // (xs + ys) % 2 == (2 * center) % 2
    // Since 2 * center is always even, we check if (xs + ys) is even.
    
    if ((xs + ys) % 2 == 0) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
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