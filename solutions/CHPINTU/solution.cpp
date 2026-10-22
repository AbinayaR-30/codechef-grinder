#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/**
 * Problem Analysis:
 * We need to group the costs of baskets by their fruit type.
 * We use an array `cost` of size M+1 to store the sum of prices for each fruit type.
 * We use an array `exists` to track if a fruit type was present in the input.
 * 
 * Complexity:
 * Time: O(N + M) per test case.
 * Space: O(M) to store costs and existence.
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    vector<int> F(N);
    for (int i = 0; i < N; ++i) {
        cin >> F[i];
    }

    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    // cost[i] stores the total price for fruit type i
    // exists[i] tracks if fruit type i is present in any basket
    vector<int> cost(M + 1, 0);
    vector<bool> exists(M + 1, false);

    for (int i = 0; i < N; ++i) {
        cost[F[i]] += P[i];
        exists[F[i]] = true;
    }

    int min_price = INT_MAX;
    bool found = false;

    for (int i = 1; i <= M; ++i) {
        if (exists[i]) {
            if (cost[i] < min_price) {
                min_price = cost[i];
                found = true;
            }
        }
    }

    // The problem guarantees we choose at least one basket, 
    // so 'found' will always be true given the constraints.
    cout << min_price << "\n";
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