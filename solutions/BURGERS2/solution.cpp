#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let n_normal be the number of normal burgers and n_premium be the number of premium burgers.
 * We have two equations:
 * 1) n_normal + n_premium = N
 * 2) X * n_normal + Y * n_premium <= R
 * 
 * Substituting n_normal = N - n_premium into (2):
 * X * (N - n_premium) + Y * n_premium <= R
 * X * N - X * n_premium + Y * n_premium <= R
 * n_premium * (Y - X) <= R - X * N
 * 
 * Since Y > X, (Y - X) is positive.
 * n_premium <= (R - X * N) / (Y - X)
 * 
 * Also, we have constraints:
 * 0 <= n_premium <= N
 * 
 * If R < X * N, it is impossible to buy N burgers even if all are normal. Output -1.
 * Otherwise, the maximum n_premium is min(N, (R - X * N) / (Y - X)).
 * If this value is < 0, it's impossible (though R < X * N covers this).
 */

void solve() {
    long long X, Y, N, R;
    cin >> X >> Y >> N >> R;

    // If even buying N normal burgers costs more than R, it's impossible.
    if (R < X * N) {
        cout << -1 << "\n";
        return;
    }

    // Calculate max possible premium burgers
    // n_premium * (Y - X) <= R - X * N
    long long max_premium = (R - X * N) / (Y - X);

    // We must have at most N burgers total
    if (max_premium > N) {
        max_premium = N;
    }

    long long n_premium = max_premium;
    long long n_normal = N - n_premium;

    cout << n_normal << " " << n_premium << "\n";
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