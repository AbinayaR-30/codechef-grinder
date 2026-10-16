#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Arya can reach cell (r, c) if and only if:
 * r = X0 + k1 * L  (where 1 <= r <= N)
 * c = Y0 + k2 * L  (where 1 <= c <= M)
 * 
 * This means r % L == X0 % L and c % L == Y0 % L.
 * We need to count how many integers r in [1, N] satisfy r % L == X0 % L
 * and how many integers c in [1, M] satisfy c % L == Y0 % L.
 * 
 * Number of such r:
 * Smallest r >= 1: X0 - ((X0 - 1) / L) * L
 * Largest r <= N: X0 + ((N - X0) / L) * L
 * Count = (Largest - Smallest) / L + 1
 */

void solve() {
    long long N, M, X0, Y0, L;
    if (!(cin >> N >> M >> X0 >> Y0 >> L)) return;

    long long r_min = X0 - ((X0 - 1) / L) * L;
    long long r_max = X0 + ((N - X0) / L) * L;
    long long count_r = (r_max - r_min) / L + 1;

    long long c_min = Y0 - ((Y0 - 1) / L) * L;
    long long c_max = Y0 + ((M - Y0) / L) * L;
    long long count_c = (c_max - c_min) / L + 1;

    cout << count_r * count_c << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}