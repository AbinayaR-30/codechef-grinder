#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N cars with initial prices P_i.
 * Each year, the price of every unsold car decreases by 1 (minimum 0).
 * To maximize profit, we should sell the most expensive cars first.
 * If we sort the prices in descending order: P_1 >= P_2 >= ... >= P_N,
 * in year 0 (first year), we sell the car with price P_1. Profit = P_1.
 * In year 1, the remaining cars have prices max(0, P_i - 1). We sell the largest.
 * By sorting descending, in year 'i' (0-indexed), the price of the car sold
 * will be max(0, P_i - i).
 * 
 * Complexity:
 * Sorting takes O(N log N).
 * Summing takes O(N).
 * Total time complexity: O(T * N log N), which fits within the 1s limit for N=10^5.
 * Space complexity: O(N) to store the prices.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    // Sort in descending order to sell the most expensive cars first
    sort(P.begin(), P.end(), greater<long long>());

    long long total_profit = 0;
    long long MOD = 1000000007;

    for (int i = 0; i < N; ++i) {
        // Price of the car at year i is max(0, P[i] - i)
        long long current_price = P[i] - i;
        if (current_price > 0) {
            total_profit = (total_profit + current_price) % MOD;
        }
    }

    cout << total_profit << "\n";
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