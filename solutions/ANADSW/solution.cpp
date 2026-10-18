#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We can swap A[i] and A[j] if |i - j| > 1.
 * 
 * Case N=1: Always sorted. YES.
 * Case N=2: If A[1] <= A[2], YES. If A[1] > A[2], we cannot swap (distance is 1). NO.
 * Case N=3: We can swap (1,3). We can reach any permutation if we can swap 
 * (1,3), (1,2) is not allowed, (2,3) is not allowed.
 * Actually, with N >= 4, we can swap any two elements.
 * For example, to swap (i, i+1):
 * If N >= 4, pick index k such that k != i, i+1.
 * Swap (i, k) then (i+1, k) then (i, k). This effectively swaps (i, i+1).
 * 
 * For N=3:
 * We can swap (1,3). We cannot swap (1,2) or (2,3).
 * The only reachable permutations from (A1, A2, A3) are (A1, A2, A3) and (A3, A2, A1).
 * So for N=3, we check if the array is sorted or if swapping A1 and A3 makes it sorted.
 * 
 * Summary:
 * N=1: YES
 * N=2: Sorted? YES : NO
 * N=3: Sorted? YES : (Swap A1, A3 sorted? YES : NO)
 * N>=4: Always YES (because we can perform any swap).
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (N == 1) {
        cout << "YES" << "\n";
    } else if (N == 2) {
        if (A[0] <= A[1]) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else if (N == 3) {
        // Check original
        bool sorted = true;
        for (int i = 0; i < N - 1; ++i) if (A[i] > A[i+1]) sorted = false;
        if (sorted) {
            cout << "YES" << "\n";
            return;
        }
        // Check swap(0, 2)
        swap(A[0], A[2]);
        sorted = true;
        for (int i = 0; i < N - 1; ++i) if (A[i] > A[i+1]) sorted = false;
        if (sorted) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else {
        // For N >= 4, we can perform any swap, so we can always sort.
        cout << "YES" << "\n";
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