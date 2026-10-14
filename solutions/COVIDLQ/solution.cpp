#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sequence of 0s and 1s representing a queue.
 * We need to ensure that for any two people (1s), the distance between them
 * is at least 6 feet.
 * If the positions of two people are i and j (where i < j), the distance is (j - i).
 * The condition is (j - i) >= 6 for all pairs of people.
 * 
 * Algorithm:
 * 1. Iterate through the array and keep track of the index of the last person seen.
 * 2. Initialize `last_pos` to a value that won't trigger a false positive (e.g., -10).
 * 3. Whenever we encounter a 1 at index `i`:
 *    a. If `i - last_pos < 6`, then social distancing is violated. Return "NO".
 *    b. Update `last_pos = i`.
 * 4. If we finish the loop without violations, return "YES".
 * 
 * Complexity:
 * Time: O(N) per test case, where N is the number of spots.
 * Space: O(N) to store the array, or O(1) if processed on the fly.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int last_pos = -10; // Initialize to a distance > 6 from any possible index
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        if (A[i] == 1) {
            if (i - last_pos < 6) {
                possible = false;
                break;
            }
            last_pos = i;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}