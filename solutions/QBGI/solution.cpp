#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to iterate through the string S and keep track of the number of boys (B) 
 * and girls (G) who have entered the bar.
 * Let 'boys' be the count of 'B' and 'girls' be the count of 'G'.
 * The condition for closing the gate is: boys > 2 * girls.
 * We stop processing as soon as this condition is met.
 * The number of people allowed to enter is the count of people processed 
 * until the condition is met.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int boys = 0;
    int girls = 0;
    int allowed = 0;

    for (int i = 0; i < N; ++i) {
        if (S[i] == 'B') {
            boys++;
        } else {
            girls++;
        }

        // Check if the condition is violated
        if (boys > 2 * girls) {
            // The current person is the one who caused the violation,
            // but the problem states "as soon as... the security closes the entrance".
            // The sample explanation for the first case:
            // "after the first six people have entered... When the next boy enters, 
            // the security guard closes the gates immediately after".
            // This implies the person who triggers the condition is included in the count.
            allowed = i + 1;
            break;
        }
        
        // If we reach the end without violating, everyone is allowed
        if (i == N - 1) {
            allowed = N;
        }
    }

    cout << allowed << "\n";
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