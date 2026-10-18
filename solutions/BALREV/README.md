# [Balanced Reversals (BALREV)](https://www.codechef.com/problems/BALREV)

- **Difficulty Rating**: 1165
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $A$ of length $N$, we are allowed to perform an operation where we choose any substring that contains an equal number of '0's and '1's and reverse it. The goal is to find the lexicographically smallest string possible after performing any number of these operations.

## Intuition & Mathematical Observation
The key observation is that the allowed operation (reversing a balanced substring) is highly flexible. In a binary string, if we have at least one '0' and one '1', we can always find a way to move them relative to each other. 

Specifically, because we can reverse any substring with an equal number of 0s and 1s, we can effectively "bubble" the 0s to the front and the 1s to the back. Since the lexicographically smallest binary string is always the one where all '0's appear before all '1's (e.g., `000...111`), and the operations allow us to reach this configuration regardless of the initial order, the problem reduces to simply counting the total number of '0's and '1's in the input string and reconstructing the string in sorted order.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We iterate through the string once to count the characters and once more to construct the result.
- **Space Complexity**: $O(N)$ to store the input string and the resulting output string.

## Solution Code

```cpp
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
 * at the end.
 * 
 * The lexicographically smallest string for a binary string is simply the string 
 * with all 0s followed by all 1s.
 */

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;

    int count0 = 0;
    int count1 = 0;

    // Count occurrences of '0' and '1'
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
```