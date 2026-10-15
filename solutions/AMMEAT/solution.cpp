#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N plates with P_i meatballs. We need to select the minimum number of plates
 * such that their sum is at least M.
 * 
 * Strategy:
 * 1. To minimize the number of plates, we should always pick the plates with the 
 *    largest number of meatballs first (Greedy approach).
 * 2. Sort the array of meatballs in descending order.
 * 3. Calculate the prefix sum or keep adding elements until the sum >= M.
 * 4. If the total sum of all plates is less than M, it's impossible, return -1.
 * 
 * Constraints:
 * N <= 7 (Wait, the problem description says N <= 7, but usually competitive 
 * programming problems have N up to 10^5. The logic remains the same regardless 
 * of N as long as we sort).
 * M, P_i <= 10^18, so we must use 'long long'.
 */

void solve() {
    int n;
    long long m;
    cin >> n >> m;
    
    vector<long long> p(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        total_sum += p[i];
    }
    
    // If total meatballs available are less than M, impossible.
    if (total_sum < m) {
        cout << -1 << "\n";
        return;
    }
    
    // Sort in descending order to pick largest plates first
    sort(p.rbegin(), p.rend());
    
    long long current_sum = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        current_sum += p[i];
        count++;
        if (current_sum >= m) {
            cout << count << "\n";
            return;
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}