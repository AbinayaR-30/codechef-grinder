#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an N x M grid of students. Each student must move to an adjacent cell.
 * This is equivalent to finding a perfect matching in the grid graph where each 
 * node (i, j) is matched with an adjacent node (i', j').
 * 
 * A grid graph is a bipartite graph. A perfect matching exists if and only if 
 * the total number of vertices (N * M) is even and the graph satisfies Hall's 
 * Marriage Theorem.
 * 
 * Specifically for a grid graph:
 * 1. If N * M is odd, it is impossible to have a perfect matching because 
 *    the number of black and white cells in a checkerboard coloring will differ by 1.
 * 2. If N * M is even, at least one of N or M must be even.
 *    - If N is even, we can pair students in each column (e.g., (1,1) with (2,1), 
 *      (3,1) with (4,1), etc.).
 *    - If M is even, we can pair students in each row (e.g., (1,1) with (1,2), 
 *      (1,3) with (1,4), etc.).
 * 
 * Therefore, the condition for a perfect matching is simply that N * M is even, 
 * which is equivalent to saying at least one of N or M is even.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, m;
        cin >> n >> m;

        // If the total number of cells is even, a perfect matching exists.
        // This happens if at least one dimension is even.
        if ((n * m) % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}