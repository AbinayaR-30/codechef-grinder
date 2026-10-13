# [Signal (P2BAR)](https://www.codechef.com/problems/P2BAR)

- **Difficulty Rating**: 657
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string of length $N$ representing a signal, we need to count the number of '1's that appear strictly after the first occurrence of a '0'. If no '0' exists in the string, the count should be 0.

## Intuition & Mathematical Observation
The problem requires us to track the state of the signal. We are looking for a transition point:
1. **The "Silence" Phase**: Before the first '0' is encountered, any '1's we see should be ignored.
2. **The "Active" Phase**: Once the first '0' is encountered, we enter a state where every subsequent '1' contributes to our final count.

By using a boolean flag (`foundSilence`), we can effectively toggle between these two states. Once the flag is set to `true` upon hitting the first '0', we simply increment a counter whenever we encounter a '1'.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We perform a single pass through the string.
- **Space Complexity**: $O(N)$ to store the input string. This can be optimized to $O(1)$ if we process the string character by character as it is read.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to count the number of '1's that appear after the first occurrence of a '0'.
 * 
 * Algorithm:
 * 1. Iterate through the string.
 * 2. Maintain a boolean flag `foundSilence` initialized to false.
 * 3. If we encounter a '0', set `foundSilence` to true.
 * 4. If we encounter a '1' and `foundSilence` is true, increment the counter.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int pulseCount = 0;
    bool foundSilence = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            foundSilence = true;
        } else if (S[i] == '1') {
            if (foundSilence) {
                pulseCount++;
            }
        }
    }

    cout << pulseCount << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```