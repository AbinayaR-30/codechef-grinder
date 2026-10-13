#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Operation 1 allows us to convert any uppercase letter to its lowercase equivalent.
 *    This means we can effectively treat every uppercase letter as its lowercase counterpart.
 *    For example, 'A' can become 'a', 'B' can become 'b', etc.
 * 2. After applying Operation 1 as much as we want, the string consists only of lowercase letters.
 *    Specifically, for any character S[i], we can choose to keep it as its lowercase form.
 * 3. Operation 2 allows us to pick one lowercase letter and change all its occurrences to another.
 *    This means we can merge the counts of two different lowercase letters into one.
 * 4. To maximize the score, we should:
 *    a. Count the frequency of each lowercase letter after converting all uppercase letters to lowercase.
 *    b. We want to pick two letters (or one, if we don't merge) and sum their frequencies to get the maximum.
 *    c. If we have counts of letters, say count[0] for 'a', count[1] for 'b', etc.,
 *       the maximum score will be the maximum of (count[i] + count[j]) for any i, j.
 *       Since we can only perform Operation 2 once, we can merge any two distinct letters,
 *       or simply pick the letter that already has the highest frequency.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> counts(26, 0);
    for (char c : S) {
        if (c >= 'A' && c <= 'Z') {
            counts[c - 'A']++;
        } else {
            counts[c - 'a']++;
        }
    }

    // We can pick any two letters i and j and merge them.
    // The new count for the target letter will be counts[i] + counts[j].
    // We want to maximize this.
    int max_score = 0;
    
    // Case 1: Merge two different letters
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (i == j) {
                max_score = max(max_score, counts[i]);
            } else {
                max_score = max(max_score, counts[i] + counts[j]);
            }
        }
    }

    cout << max_score << "\n";
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