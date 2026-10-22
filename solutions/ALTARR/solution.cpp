#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An array is alternating if the parity of A[i] is different from A[i+1].
 * There are only two possible patterns for an alternating array of length N:
 * Pattern 1: Odd, Even, Odd, Even, ...
 * Pattern 2: Even, Odd, Even, Odd, ...
 * 
 * For each pattern, we count how many elements in the original array do not 
 * match the required parity. The minimum of these two counts is the answer.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // count1: cost to make it Odd, Even, Odd, Even...
    // count2: cost to make it Even, Odd, Even, Odd...
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < N; ++i) {
        int parity = A[i] % 2; // 1 for odd, 0 for even
        
        // Pattern 1: index i should have parity (i % 2 == 0 ? 1 : 0)
        int expected1 = (i % 2 == 0) ? 1 : 0;
        if (parity != expected1) {
            count1++;
        }

        // Pattern 2: index i should have parity (i % 2 == 0 ? 0 : 1)
        int expected2 = (i % 2 == 0) ? 0 : 1;
        if (parity != expected2) {
            count2++;
        }
    }

    cout << min(count1, count2) << "\n";
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