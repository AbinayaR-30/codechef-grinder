#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A sequence is "good" if the parity of adjacent elements is different.
 * This means the sequence must alternate between odd and even numbers.
 * To find the longest good subsequence, we simply need to pick an element,
 * then pick the next element that has a different parity, and so on.
 * 
 * Greedy Strategy:
 * Iterate through the array and keep track of the parity of the last element 
 * added to our subsequence. If the current element has a different parity 
 * than the last added element, we include it.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(1) auxiliary space.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (N == 0) {
        cout << 0 << "\n";
        return;
    }

    int count = 0;
    int last_parity = -1; // -1 indicates no element picked yet

    for (int i = 0; i < N; ++i) {
        int current_parity = A[i] % 2;
        if (last_parity == -1 || current_parity != last_parity) {
            count++;
            last_parity = current_parity;
        }
    }

    cout << count << "\n";
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