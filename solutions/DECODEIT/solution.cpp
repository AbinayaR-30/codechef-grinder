#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem describes a binary encoding scheme for the first 16 lowercase English letters (a-p).
 * Each character is represented by 4 bits.
 * The encoding process is essentially a binary search over the range [0, 15].
 * 
 * For a 4-bit sequence b1 b2 b3 b4:
 * The value can be calculated as: b1*8 + b2*4 + b3*2 + b4*1.
 * This value corresponds directly to the index of the letter in the alphabet (0 for 'a', 1 for 'b', ..., 15 for 'p').
 * 
 * Complexity:
 * Time: O(N) where N is the length of the string, as we process each 4-bit block once.
 * Space: O(N) to store the input string, or O(1) if processed character by character.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string result = "";
    // Process the string in chunks of 4 bits
    for (int i = 0; i < n; i += 4) {
        int val = 0;
        // Convert 4-bit binary string to integer
        // bit 0: 2^3 = 8, bit 1: 2^2 = 4, bit 2: 2^1 = 2, bit 3: 2^0 = 1
        if (s[i] == '1') val += 8;
        if (s[i + 1] == '1') val += 4;
        if (s[i + 2] == '1') val += 2;
        if (s[i + 3] == '1') val += 1;
        
        // Map the integer value (0-15) to the corresponding character ('a'-'p')
        result += (char)('a' + val);
    }
    cout << result << "\n";
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