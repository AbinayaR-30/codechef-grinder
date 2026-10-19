#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N items with resale values A_i.
 * We have K slots that cost 5, and infinite slots that cost 10.
 * To maximize profit:
 * 1. Sort A_i in descending order.
 * 2. The best items should occupy the K slots (cost 5).
 * 3. Any remaining items that provide positive profit at cost 10 should be bought.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort descending to prioritize higher resale values
    sort(A.rbegin(), A.rend());

    long long total_profit = 0;

    for (int i = 0; i < N; ++i) {
        if (i < K) {
            // These items cost 5
            if (A[i] > 5) {
                total_profit += (A[i] - 5);
            }
        } else {
            // These items cost 10
            if (A[i] > 10) {
                total_profit += (A[i] - 10);
            }
        }
    }

    cout << total_profit << "\n";
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