#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows us to reverse any substring that has an equal number of 0s and 1s.
 * This operation is powerful enough to allow us to rearrange the 0s and 1s in the string
 * such that all 0s come before all 1s.
 * 
 * Specifically, if we have a string with 'c0' zeros and 'c1' ones, we can always 
 * reach the state where all 'c0' zeros are at the beginning and all 'c1' ones are 
 * at the end. This is because any substring with equal 0s and 1s can be reversed, 
 * and by repeatedly applying this, we can effectively sort the string.
 * 
 * The lexicographically smallest string for a binary string is simply the string 
 * with all 0s followed by all 1s.
 * 
 * Time Complexity: O(N) per test case to count 0s and 1s and print them.
 * Space Complexity: O(N) to store the input string.
 */

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;

    int count0 = 0;
    int count1 = 0;

    for (char c : a) {
        if (c == '0') {
            count0++;
        } else {
            count1++;
        }
    }

    // The lexicographically smallest string is all 0s followed by all 1s.
    string result = "";
    for (int i = 0; i < count0; ++i) {
        result += '0';
    }
    for (int i = 0; i < count1; ++i) {
        result += '1';
    }

    cout << result << "\n";
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