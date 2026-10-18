#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an initial sequence X and a transformed sequence Y.
 * We need to find a pivot index i (1 <= i <= N) such that if we set P = X[i],
 * the sequence Y is exactly the sequence obtained by sorting the pairs 
 * (|X[j] - P|, X[j]) based on the specified criteria.
 * 
 * Constraints: N <= 100, T <= 100.
 * An O(N^2 log N) approach per test case is perfectly acceptable.
 * 
 * Algorithm:
 * 1. Iterate through each possible pivot index i from 0 to N-1.
 * 2. For each i, calculate P = X[i].
 * 3. Construct the list L of pairs (|X[j] - P|, X[j]) for all j.
 * 4. Sort the list L using the custom comparator:
 *    (A, B) < (C, D) if A < C or (A == C and B < D).
 * 5. Extract the second elements from the sorted list L into a new sequence Y_calc.
 * 6. Compare Y_calc with the given sequence Y.
 * 7. If they match, return i + 1 (1-based index).
 * 8. If no index matches after checking all, return -1.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; ++i) cin >> X[i];
    for (int i = 0; i < N; ++i) cin >> Y[i];

    for (int i = 0; i < N; ++i) {
        int P = X[i];
        vector<pair<int, int>> L(N);
        for (int j = 0; j < N; ++j) {
            L[j] = {abs(X[j] - P), X[j]};
        }

        // Sort based on the problem definition
        sort(L.begin(), L.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });

        // Check if the generated sequence matches Y
        bool match = true;
        for (int k = 0; k < N; ++k) {
            if (L[k].second != Y[k]) {
                match = false;
                break;
            }
        }

        if (match) {
            cout << i + 1 << "\n";
            return;
        }
    }

    cout << -1 << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}