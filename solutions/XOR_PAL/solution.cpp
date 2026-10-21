#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to make the string a palindrome. A string is a palindrome if A[i] == A[N-1-i] for all i.
 * Let's look at pairs (A[i], A[N-1-i]).
 * If A[i] == A[N-1-i], these positions are already "palindromic".
 * If A[i] != A[N-1-i], these positions need to be changed.
 * 
 * Let 'diff' be the number of pairs (i, N-1-i) such that A[i] != A[N-1-i].
 * Since we are comparing indices i and N-1-i, we only need to check up to N/2.
 * 
 * If we have a pair that is different (0, 1), one operation can make them both 0 or both 1.
 * Specifically, if we pick indices i and j, we can change both to A[i] ^ A[j].
 * If we have 'diff' such pairs, we need at least 'diff' operations to fix them.
 * However, one operation can potentially fix two pairs if we choose indices carefully, 
 * but the problem allows changing any two indices. 
 * Actually, for each pair (i, N-1-i) where A[i] != A[N-1-i], we need 1 operation to make them equal.
 * Thus, we need 'diff' operations.
 * 
 * Wait, is it always 'diff'? 
 * If N is odd, the middle element doesn't have a pair.
 * If we have 'diff' pairs that are different, we need 'diff' operations.
 * Each operation can fix one mismatching pair.
 * The answer is simply ceil(diff / 2.0).
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    int diff = 0;
    for (int i = 0; i < N / 2; ++i) {
        if (A[i] != A[N - 1 - i]) {
            diff++;
        }
    }

    // Each operation can resolve two mismatches if we pick indices from two different mismatching pairs.
    // If we have 'diff' mismatches, we can resolve 2 per operation.
    // So we need ceil(diff / 2.0) operations.
    cout << (diff + 1) / 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}