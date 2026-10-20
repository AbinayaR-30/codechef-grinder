#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * The theater has 2N+1 seats.
 * Occupied seats are 1, 3, 5, ..., 2N+1.
 * Empty seats are 2, 4, 6, ..., 2N.
 * 
 * The hype levels are given as A_1, A_2, ..., A_{N+1}.
 * Seat 2 is between A_1 and A_2. Loudness = max(A_1, A_2).
 * Seat 4 is between A_2 and A_3. Loudness = max(A_2, A_3).
 * Seat 2k is between A_k and A_{k+1}. Loudness = max(A_k, A_{k+1}).
 * 
 * We need to find min(max(A_k, A_{k+1})) for k = 1 to N.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<int> A(N + 1);
    for (int i = 0; i <= N; ++i) {
        cin >> A[i];
    }
    
    // Initialize min_loudness with a value larger than any possible A_i (max 100)
    int min_loudness = 1000;
    
    // There are N empty seats. 
    // The i-th empty seat (0-indexed loop) is between A[i] and A[i+1]
    for (int i = 0; i < N; ++i) {
        int current_loudness = max(A[i], A[i + 1]);
        if (current_loudness < min_loudness) {
            min_loudness = current_loudness;
        }
    }
    
    cout << min_loudness << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}