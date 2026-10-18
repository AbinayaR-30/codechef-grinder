#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The score increases by 1 only when we remove a pair (0, 1) or (1, 0).
 * Each such operation consumes one 0 and one 1.
 * Since we can always bring a 0 and a 1 together as long as both exist 
 * (by removing other pairs or simply finding an adjacent pair), 
 * the maximum number of such operations is min(count of 0s, count of 1s).
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val == 0) {
            c0++;
        } else {
            c1++;
        }
    }
    // The maximum score is the number of pairs of (0, 1) we can form.
    cout << min(c0, c1) << "\n";
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}