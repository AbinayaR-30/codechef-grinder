#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. The strip must have an odd length (Ni) to have a unique center.
 * 2. The first element must be 1.
 * 3. The sequence must increase by 1 until the center, then decrease by 1.
 * 4. This implies the sequence must be: 1, 2, 3, ..., (Ni+1)/2, ..., 3, 2, 1.
 * 
 * Logic:
 * - If Ni is even, it's impossible to have a unique center, so "no".
 * - If H[0] != 1 or H[Ni-1] != 1, "no".
 * - Iterate through the array:
 *   - For the first half (including center), H[i] must be i + 1.
 *   - For the second half, H[i] must be H[i-1] - 1.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    // Condition 1: Must have an odd length to have a unique center
    if (n % 2 == 0) {
        cout << "no" << "\n";
        return;
    }

    // Condition 2: Must start and end with 1
    if (h[0] != 1 || h[n - 1] != 1) {
        cout << "no" << "\n";
        return;
    }

    int center = n / 2;
    bool possible = true;

    // Check increasing part
    for (int i = 0; i <= center; ++i) {
        if (h[i] != i + 1) {
            possible = false;
            break;
        }
    }

    // Check decreasing part
    if (possible) {
        for (int i = center + 1; i < n; ++i) {
            if (h[i] != h[i - 1] - 1) {
                possible = false;
                break;
            }
        }
    }

    if (possible) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s;
    cin >> s;
    while (s--) {
        solve();
    }
    return 0;
}