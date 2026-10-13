# [Bar Queue (QBGI)](https://www.codechef.com/problems/QBGI)

- **Difficulty Rating**: 821
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine how many people can enter a bar before the security guard closes the entrance. The entrance is closed as soon as the number of boys ($B$) currently in the queue exceeds twice the number of girls ($G$) currently in the queue (i.e., $B > 2 \times G$). We are given a string representing the sequence of people arriving at the bar and must output the total number of people who successfully entered before or at the moment the condition was met.

## Intuition & Mathematical Observation
The problem can be solved by simulating the arrival process step-by-step:
1. Maintain two counters: `boys` and `girls`.
2. Iterate through the input string character by character.
3. For each character, update the respective counter.
4. Immediately after updating, check the condition `boys > 2 * girls`.
5. If the condition is true, the current person is the last one allowed to enter. We record the current position (index + 1) and terminate the loop.
6. If the loop finishes without the condition ever being met, it means everyone in the queue was allowed to enter.

**Key Insight:** The condition is checked *after* each person enters. Since the problem asks for the count of people who entered *until* the gate closes, the person who triggers the violation is included in the count.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We iterate through the string exactly once.
- **Space Complexity**: $O(N)$ to store the input string, or $O(1)$ if we process the input character by character (though storing the string is standard and efficient for these constraints).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We iterate through the string S and keep track of the number of boys (B) 
 * and girls (G). The condition for closing the gate is: boys > 2 * girls.
 * We stop processing as soon as this condition is met.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int boys = 0;
    int girls = 0;
    int allowed = N; // Default to N if condition is never met

    for (int i = 0; i < N; ++i) {
        if (S[i] == 'B') {
            boys++;
        } else {
            girls++;
        }

        // Check if the condition is violated
        if (boys > 2 * girls) {
            // The current person is the one who caused the violation,
            // and the gate closes immediately after them.
            allowed = i + 1;
            break;
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
```