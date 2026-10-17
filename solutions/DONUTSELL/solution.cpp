#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Selling Donuts
 * Approach:
 * We are given N types of donuts with initial counts A_i.
 * M customers arrive sequentially, each wanting one donut of type B_i.
 * If A[B_i] > 0, we decrement A[B_i] and the customer is satisfied.
 * If A[B_i] == 0, the customer is sad.
 * We need to count the total number of sad customers.
 * 
 * Complexity:
 * Time: O(T * (N + M)) where T is test cases, N is donut types, M is customers.
 * Given constraints N, M <= 100, this is well within the 1s time limit.
 * Space: O(N) to store the donut counts.
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    // Use 1-based indexing for convenience since B_i is 1 to N
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    int sad_customers = 0;
    for (int i = 0; i < M; ++i) {
        int type;
        cin >> type;
        
        // Check if the requested donut type is available
        if (A[type] > 0) {
            A[type]--;
        } else {
            // No donuts of this type left, customer is sad
            sad_customers++;
        }
    }

    cout << sad_customers << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}