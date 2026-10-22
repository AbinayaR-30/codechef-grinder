#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * To make all elements equal to some value X, X must be a common divisor of all A[i].
 * The largest such X is G = GCD(A[0], ..., A[N-1]).
 * Any other common divisor X' is a divisor of G.
 * If we choose X = G:
 * - If A[i] == G, 0 moves.
 * - If A[i] > G, 1 move (since G | A[i]).
 * Total moves = count of A[i] where A[i] != G.
 */

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    long long common_gcd = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (i == 0) common_gcd = A[i];
        else common_gcd = gcd(common_gcd, A[i]);
    }

    int moves = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] != common_gcd) {
            moves++;
        }
    }

    cout << moves << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}