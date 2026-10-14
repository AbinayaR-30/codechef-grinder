#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S of length N.
 * We need to construct a string T such that T[i] != S[i] for all i.
 * Since the string is binary, the only possible characters are '0' and '1'.
 * If S[i] == '0', then T[i] must be '1'.
 * If S[i] == '1', then T[i] must be '0'.
 * This is equivalent to flipping each bit of the string S.
 * 
 * Time Complexity: O(N) per test case, where N is the length of the string.
 * Total time complexity: O(sum of N), which is O(2 * 10^5).
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    string T = "";
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            T += '1';
        } else {
            T += '0';
        }
    }
    cout << T << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}