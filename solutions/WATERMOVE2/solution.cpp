#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N cups with amounts A_i.
 * In one operation, we move all water from cup i to cup j.
 * We must perform exactly K operations.
 * To maximize the water in a single cup, we want to aggregate as much water
 * as possible into one cup.
 * 
 * Each operation reduces the number of non-empty cups by 1.
 * We can perform at most N-1 operations to merge all water into one cup.
 * If K <= N-1, we can pick the largest cup and merge K other cups into it.
 * If K > N-1, we merge all cups into one (taking N-1 operations).
 * The remaining K - (N-1) operations must be performed. 
 * Since we can only move water from a cup to another, and we can choose 
 * to move 0 amount of water (if we move from an empty cup to the cup 
 * containing all the water), we can effectively "waste" the extra operations 
 * without changing the total amount in the target cup.
 * 
 * Thus, the strategy is:
 * 1. Sort the array A in descending order.
 * 2. The maximum amount will be the sum of the largest cup and the next K cups.
 * 3. If K >= N, the maximum amount is the sum of all cups.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }

    if (K >= N) {
        cout << total_sum << "\n";
    } else {
        // Sort descending to pick the largest elements
        sort(A.rbegin(), A.rend());
        long long max_val = A[0];
        for (int i = 1; i <= K; ++i) {
            max_val += A[i];
        }
        cout << max_val << "\n";
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