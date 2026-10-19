#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A subsequence is "cool" if the averages of all its non-empty subsequences are present 
 * in the complement subsequence.
 * 
 * Consider a subsequence of length 1, say {x}. The only non-empty subsequence is {x},
 * with average x. If x is present in the complement, then {x} is a cool subsequence.
 * 
 * If an array has any duplicate elements, say 'x' appears at least twice, we can pick
 * one 'x' as our subsequence. The complement will contain at least one other 'x'.
 * Since the average of {x} is x, and x is in the complement, {x} is a cool subsequence.
 * 
 * If all elements in the array are distinct, we need to check if any element x exists 
 * such that x is in the complement. But if all elements are distinct, the complement 
 * of {x} is the set of all other elements. So x cannot be in the complement.
 * 
 * Thus, a cool subsequence exists if and only if there is at least one duplicate 
 * element in the array. If there are duplicates, any duplicate element 'x' forms 
 * a cool subsequence of length 1.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> counts;
    int duplicate_val = -1;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        counts[A[i]]++;
        if (counts[A[i]] > 1) {
            duplicate_val = A[i];
        }
    }

    if (duplicate_val != -1) {
        // We found a duplicate. A subsequence of length 1 containing this value
        // is cool because the complement will contain at least one more instance
        // of this value.
        cout << 1 << "\n";
        cout << duplicate_val << "\n";
    } else {
        // If all elements are distinct, no cool subsequence exists.
        cout << -1 << "\n";
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