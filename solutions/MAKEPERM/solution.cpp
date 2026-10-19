#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N. We need to find if there exists an array B 
 * of non-negative integers such that C_i = A_i + B_i forms a permutation of 1 to N.
 * 
 * Since B_i >= 0, we must have C_i >= A_i.
 * This means for every element in the target permutation {1, 2, ..., N}, 
 * we must be able to map it to an element A_i such that A_i <= C_i.
 * 
 * If we sort array A in non-decreasing order, and we sort the target permutation 
 * (which is simply 1, 2, ..., N) in non-decreasing order, the condition 
 * "there exists a permutation" is satisfied if and only if for all i from 0 to N-1:
 * sorted_A[i] <= (i + 1)
 * 
 * Proof sketch:
 * If sorted_A[i] <= i + 1 for all i, we can assign the value (i + 1) to A[i] 
 * by setting B[i] = (i + 1) - A[i]. Since A[i] <= i + 1, B[i] will be >= 0.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort A to compare with the sorted permutation 1, 2, ..., N
    sort(A.begin(), A.end());
    
    bool possible = true;
    for (int i = 0; i < N; ++i) {
        // The i-th smallest element in the permutation is (i + 1)
        // We need A[i] <= (i + 1) to ensure B[i] >= 0
        if (A[i] > (i + 1)) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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