#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N days of profit/loss A_i.
 * We need to skip exactly one day to maximize the total profit.
 * Total profit = (Sum of all A_i) - A_k, where A_k is the profit of the day we skip.
 * To maximize the total profit, we need to minimize A_k.
 * Therefore, the result is (Sum of all A_i) - (Minimum value in A).
 * 
 * Constraints:
 * N <= 10^5, Sum of N <= 10^6.
 * A_i between -100 and 100.
 * The sum can be around 10^5 * 100 = 10^7, which fits in a standard 32-bit int,
 * but using long long is safer and good practice.
 */

void solve() {
    int N;
    cin >> N;
    
    vector<long long> A(N);
    long long total_sum = 0;
    long long min_val = 101; // Since max A_i is 100
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
        if (A[i] < min_val) {
            min_val = A[i];
        }
    }
    
    // The maximum profit after skipping one day is the total sum minus the minimum element.
    cout << (total_sum - min_val) << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}