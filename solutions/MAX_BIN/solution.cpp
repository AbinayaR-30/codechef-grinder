#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Strategy:
 * 1. If S[0] == '0', we should change it to '1' using one Type 2 operation.
 *    This costs 1 operation.
 * 2. Use all remaining operations as Type 1 (appending '0's at the end).
 *    Appending '0' at the end is equivalent to multiplying by 2, which is 
 *    always better than changing internal '0's to '1's.
 */

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // Step 1: If the first bit is '0', change it to '1'
    if (s[0] == '0') {
        s[0] = '1';
        k--;
    }

    // Step 2: Append '0's at the end using remaining k
    // Each Type 1 operation adds a '0' at the end.
    // If we have more k than needed, we just keep adding '0's.
    string suffix = "";
    for (int i = 0; i < k; ++i) {
        suffix += '0';
    }

    cout << s << suffix << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}