#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial price of petrol: X
 * Initial price of diesel: Y
 * Monthly increase for petrol: A
 * Monthly increase for diesel: B
 * Number of months: K
 * 
 * Price of petrol after K months: X + (A * K)
 * Price of diesel after K months: Y + (B * K)
 * 
 * We need to compare these two values.
 * Constraints are small (up to 1000), so standard integer types are sufficient,
 * but using long long is good practice to prevent any potential overflow.
 */

void solve() {
    long long X, Y, A, B, K;
    if (!(cin >> X >> Y >> A >> B >> K)) return;

    long long final_petrol = X + (A * K);
    long long final_diesel = Y + (B * K);

    if (final_petrol < final_diesel) {
        cout << "PETROL" << "\n";
    } else if (final_diesel < final_petrol) {
        cout << "DIESEL" << "\n";
    } else {
        cout << "SAME PRICE" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}