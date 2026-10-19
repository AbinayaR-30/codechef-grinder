#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to turn all '1's into '0's.
 * 1. If the string is already all '0's, 0 operations are needed.
 * 2. If there are no two '1's that are adjacent, we can flip all '1's in a single operation.
 * 3. If there are adjacent '1's, we cannot flip them in the same operation.
 *    - Can we do it in 2 operations? Yes.
 *      We can split the '1's into two sets such that no two '1's in the same set are adjacent.
 *      For example, if we have "11", we can flip index 0 in op 1, and index 1 in op 2.
 *      Even with "111", we can pick {0, 2} for op 1 (string becomes 010) and {1} for op 2.
 *      It turns out that for any string, 2 operations are sufficient to handle adjacent '1's.
 *    - The only case where 2 operations might fail is if we can't split them, but we can always
 *      split any set of indices into two sets where no two indices are adjacent (e.g., parity-based).
 *      The only constraint is the adjacency.
 * 
 * Summary:
 * - 0 operations if no '1's exist.
 * - 1 operation if no two '1's are adjacent.
 * - 2 operations if there exists at least one pair of adjacent '1's.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    bool has_ones = false;
    bool has_adjacent_ones = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            has_ones = true;
            if (i > 0 && S[i - 1] == '1') {
                has_adjacent_ones = true;
            }
        }
    }

    if (!has_ones) {
        cout << 0 << "\n";
    } else if (has_adjacent_ones) {
        cout << 2 << "\n";
    } else {
        cout << 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}