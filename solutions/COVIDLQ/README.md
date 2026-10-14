# [COVID Pandemic and Long Queue (COVIDLQ)](https://www.codechef.com/problems/COVIDLQ)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a queue represented by an array of size $N$ containing only $0$s and $1$s, where $1$ represents a person and $0$ represents an empty spot. The rule for social distancing states that any two people must be at least 6 feet apart. In the context of the array, this means if two people are at indices $i$ and $j$ (where $i < j$), the condition $j - i \ge 6$ must hold for all consecutive pairs of people. We need to determine if the given queue configuration satisfies this condition.

## Intuition & Mathematical Observation
The problem requires us to ensure that no two people are placed too close to each other. Instead of checking every possible pair, we only need to track the position of the **last person encountered**. 

1. We iterate through the array and maintain a variable `last_pos` to store the index of the most recent person (`1`) found.
2. We initialize `last_pos` to a value sufficiently small (e.g., $-10$) so that the first person encountered does not trigger a false violation.
3. Whenever we encounter a `1` at the current index `i`, we check the distance from the previous person: `i - last_pos`.
4. If `i - last_pos < 6`, the social distancing rule is violated, and we can immediately conclude the answer is "NO".
5. If we traverse the entire array without violating this condition, the answer is "YES".

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of spots in the queue. We perform a single pass through the array.
- **Space Complexity**: $O(N)$ to store the input array. Note that this can be optimized to $O(1)$ by processing the input values one by one without storing them in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sequence of 0s and 1s representing a queue.
 * We need to ensure that for any two people (1s), the distance between them
 * is at least 6 feet.
 * If the positions of two people are i and j (where i < j), the distance is (j - i).
 * The condition is (j - i) >= 6 for all pairs of people.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Initialize to a value that ensures the first person found 
    // doesn't trigger a violation (distance > 6).
    int last_pos = -10; 
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        if (A[i] == 1) {
            if (i - last_pos < 6) {
                possible = false;
                break;
            }
            last_pos = i;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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