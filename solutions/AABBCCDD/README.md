# [AabBcCDd (AABBCCDD)](https://www.codechef.com/problems/AABBCCDD)
- **Difficulty Rating**: 972
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a string $S$ containing both uppercase and lowercase English letters. You are allowed two operations:
1. Convert any uppercase letter to its lowercase equivalent (e.g., 'A' to 'a').
2. Choose any two lowercase letters and merge all occurrences of one into the other.

The goal is to maximize the frequency of a single character in the string after performing these operations.

## Intuition & Mathematical Observation
1. **Normalization**: Since Operation 1 allows us to convert any uppercase letter to lowercase, we can treat 'A' and 'a' as the same character. We start by calculating the frequency of each letter 'a' through 'z' by treating all uppercase letters as their lowercase counterparts.
2. **Merging**: Operation 2 allows us to combine the counts of two different letters. To maximize the score, we want to find the two letters that, when combined, yield the highest total frequency.
3. **Strategy**: 
   - Let `counts[i]` be the frequency of the $i$-th letter of the alphabet.
   - We want to find $\max(counts[i] + counts[j])$ for any $i, j \in \{0, \dots, 25\}$.
   - If $i = j$, the result is simply the frequency of that letter (which is covered by the case where we don't merge or merge a letter with itself).
   - If $i \neq j$, we are effectively summing the frequencies of two distinct characters.

## Complexity Analysis
- **Time Complexity**: $O(N + 26^2)$, where $N$ is the length of the string. We iterate through the string once to count frequencies ($O(N)$) and then use a nested loop to check all pairs of the 26 alphabet characters ($O(26^2)$). Since $26^2$ is a constant, this is effectively $O(N)$.
- **Space Complexity**: $O(1)$, as we only use a fixed-size array of size 26 to store the character frequencies.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Operation 1 allows us to convert any uppercase letter to its lowercase equivalent.
 *    This means we can effectively treat every uppercase letter as its lowercase counterpart.
 * 2. Operation 2 allows us to pick one lowercase letter and change all its occurrences to another.
 *    This means we can merge the counts of two different lowercase letters into one.
 * 3. To maximize the score, we count the frequency of each letter and find the maximum 
 *    sum of any two (possibly identical) letter frequencies.
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

    int max_score = 0;
    
    // Check all pairs (i, j) to find the maximum possible frequency after one merge
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
```