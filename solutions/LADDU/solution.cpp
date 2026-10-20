#include <iostream>
#include <string>

using namespace std;

/**
 * Problem Analysis:
 * 1. CONTEST_WON: 300 + (20 - rank) if rank < 20, else 300.
 * 2. TOP_CONTRIBUTOR: 300.
 * 3. BUG_FOUND: severity.
 * 4. CONTEST_HOSTED: 50.
 * 5. Redemption threshold: 200 for INDIAN, 400 for NON_INDIAN.
 * 6. Max months = total_laddus / threshold.
 */

void solve() {
    int activities;
    string origin;
    if (!(cin >> activities >> origin)) return;

    long long total_laddus = 0;

    for (int i = 0; i < activities; ++i) {
        string type;
        cin >> type;
        if (type == "CONTEST_WON") {
            int rank;
            cin >> rank;
            total_laddus += 300;
            if (rank < 20) {
                total_laddus += (20 - rank);
            }
        } else if (type == "TOP_CONTRIBUTOR") {
            total_laddus += 300;
        } else if (type == "BUG_FOUND") {
            int severity;
            cin >> severity;
            total_laddus += severity;
        } else if (type == "CONTEST_HOSTED") {
            total_laddus += 50;
        }
    }

    int threshold = (origin == "INDIAN") ? 200 : 400;
    
    // The user can redeem as long as they have at least the threshold amount
    // per month. Integer division naturally handles the "maximum number of months".
    cout << (total_laddus / threshold) << "\n";
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