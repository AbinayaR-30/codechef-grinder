#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has score A, Bob has score B. Both are 2-digit numbers without '0'.
 * Alice can reverse her score (A_rev) and/or Bob's score (B_rev).
 * There are 4 possible scenarios for the final scores (A', B'):
 * 1. (A, B)
 * 2. (A, B_rev)
 * 3. (A_rev, B)
 * 4. (A_rev, B_rev)
 * 
 * If in any of these scenarios A' > B', the answer is "Yes".
 * Otherwise, the answer is "No".
 */

int reverse_num(int n) {
    int tens = n / 10;
    int units = n % 10;
    return units * 10 + tens;
}

void solve() {
    int A, B;
    cin >> A >> B;
    
    int A_rev = reverse_num(A);
    int B_rev = reverse_num(B);
    
    // Check all 4 combinations
    if (A > B || A > B_rev || A_rev > B || A_rev > B_rev) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
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