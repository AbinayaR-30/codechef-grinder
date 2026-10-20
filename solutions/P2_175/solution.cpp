#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let's trace the positions:
 * Initial: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10...
 * 
 * Second 1:
 * Positions 1 and 3 leave.
 * Remaining: 2, 4, 5, 6, 7, 8, 9, 10...
 * New indices: 1(2), 2(4), 3(5), 4(6), 5(7), 6(8), 7(9), 8(10)...
 * 
 * Second 2:
 * Positions 1 and 3 leave (which were original 2 and 5).
 * Remaining: 4, 6, 7, 8, 9, 10...
 * New indices: 1(4), 2(6), 3(7), 4(8), 5(9), 6(10)...
 * 
 * Second 3:
 * Positions 1 and 3 leave (which were original 4 and 7).
 * Remaining: 6, 8, 9, 10...
 * 
 * Pattern observation:
 * N=1: 1st sec
 * N=2: 2nd sec
 * N=3: 1st sec
 * N=4: 3rd sec
 * N=5: 2nd sec
 * N=6: 4th sec
 * N=7: 3rd sec
 * 
 * Let f(N) be the time taken for position N.
 * If N % 2 != 0:
 *   N=1 -> 1
 *   N=3 -> 1
 *   N=5 -> 2
 *   N=7 -> 3
 *   N=9 -> 4
 *   For odd N > 1, f(N) = (N-1)/2
 * If N % 2 == 0:
 *   N=2 -> 2
 *   N=4 -> 3
 *   N=6 -> 4
 *   N=8 -> 5
 *   For even N, f(N) = N/2 + 1
 */

void solve() {
    long long N;
    cin >> N;
    if (N == 1 || N == 3) {
        cout << 1 << "\n";
    } else if (N % 2 != 0) {
        cout << (N - 1) / 2 << "\n";
    } else {
        cout << (N / 2) + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}