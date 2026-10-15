#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * John Jackson (A) wants to have strictly more votes than Jack Johnson (B).
 * We want to minimize the number of swaps.
 * To maximize John's total votes while minimizing swaps, we should always swap
 * the smallest pack from A with the largest pack from B.
 * 
 * Algorithm:
 * 1. Calculate current sums of A and B.
 * 2. If sum(A) > sum(B), return 0.
 * 3. Sort A in ascending order and B in descending order.
 * 4. Iterate through the sorted arrays, swapping the smallest A[i] with the largest B[i].
 * 5. After each swap, update sums and check if sum(A) > sum(B).
 * 6. If we exhaust all possible swaps and sum(A) is still <= sum(B), return -1.
 */

void solve() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N), B(M);
    long long sumA = 0, sumB = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sumA += A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
        sumB += B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<long long>());

    int swaps = 0;
    int limit = min(N, M);
    
    // Check if already winning
    if (sumA > sumB) {
        cout << 0 << "\n";
        return;
    }

    for (int i = 0; i < limit; ++i) {
        // Swap smallest A with largest B
        if (A[i] < B[i]) {
            sumA = sumA - A[i] + B[i];
            sumB = sumB - B[i] + A[i];
            swaps++;
            
            if (sumA > sumB) {
                cout << swaps << "\n";
                return;
            }
        } else {
            // Since A is sorted ascending and B descending, 
            // if A[i] >= B[i], no further swaps will help.
            break;
        }
    }

    cout << -1 << "\n";
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