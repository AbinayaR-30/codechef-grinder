#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To form the string "codechef", we need the following counts of characters:
 * c: 2
 * o: 1
 * d: 1
 * e: 2
 * h: 1
 * f: 1
 * 
 * We count the total occurrences of each character across all input strings.
 * Let the total counts be count['c'], count['o'], count['d'], count['e'], count['h'], count['f'].
 * The maximum number of "codechef" strings we can form is limited by the character
 * that runs out first, considering the required frequency per meal.
 * 
 * Specifically:
 * meals = min(
 *   count['c'] / 2,
 *   count['o'] / 1,
 *   count['d'] / 1,
 *   count['e'] / 2,
 *   count['h'] / 1,
 *   count['f'] / 1
 * )
 */

void solve() {
    int n;
    cin >> n;
    map<char, int> counts;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            counts[c]++;
        }
    }

    // Required counts for one "codechef"
    // c: 2, o: 1, d: 1, e: 2, h: 1, f: 1
    int c = counts['c'] / 2;
    int o = counts['o'];
    int d = counts['d'];
    int e = counts['e'] / 2;
    int h = counts['h'];
    int f = counts['f'];

    int ans = min({c, o, d, e, h, f});
    cout << ans << "\n";
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