#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct a permutation A of {1, 2, ..., N} such that 
 * LCM(1+A_1, 2+A_2, ..., N+A_N) is minimized.
 * 
 * Let B_i = i + A_i. We want to minimize LCM(B_1, B_2, ..., B_N).
 * Since A is a permutation of {1, ..., N}, the sum of B_i is:
 * sum(B_i) = sum(i) + sum(A_i) = 2 * sum(1 to N) = N * (N + 1).
 * 
 * To minimize the LCM, we want the values B_i to be as small as possible 
 * and ideally equal to each other or sharing many factors.
 * If we set A_i = N - i + 1, then B_i = i + (N - i + 1) = N + 1 for all i.
 * In this case, LCM(N+1, N+1, ..., N+1) = N + 1.
 * 
 * Since each B_i = i + A_i >= 1 + 1 = 2, the LCM must be at least the 
 * maximum of the set {B_i}. Since the average value of B_i is N+1, 
 * the LCM cannot be smaller than N+1.
 * Thus, the permutation A_i = N - i + 1 is optimal.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        // Output the permutation N, N-1, ..., 1
        // This results in B_i = i + (N - i + 1) = N + 1 for all i.
        for (int i = 0; i < n; ++i) {
            cout << (n - i) << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}