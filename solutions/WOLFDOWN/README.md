# [Wolf Down (WOLFDOWN)](https://www.codechef.com/problems/WOLFDOWN)

- **Difficulty Rating**: 1022
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a string of length $N$ representing a line of animals, where `'1'` represents a wolf and `'0'` represents a bird. A wolf at position $x$ can eat a bird at position $x+1$ and move to that position. This process continues, meaning any bird located to the right of a wolf will eventually be eaten. We need to determine how many birds are "safe," meaning they are not eaten by any wolf.

## Intuition & Mathematical Observation
The movement rule implies that a wolf effectively "sweeps" everything to its right. If a wolf exists at any index $j$, it will consume all birds at indices $i > j$. 

Therefore, a bird at index $i$ is safe if and only if there are **no wolves** at any index $j < i$. 
- If we encounter a bird ('0') before seeing any wolf ('1'), that bird is safe.
- Once the first wolf ('1') appears in the string, every bird encountered thereafter will be eaten by that wolf (or a subsequent one).
- Consequently, the problem reduces to counting the number of consecutive '0's appearing at the beginning of the string before the first '1' appears.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We perform a single pass through the string to count the safe birds.
- **Space Complexity**: $O(N)$ to store the input string (or $O(1)$ if processed character by character).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A bird at position 'i' is safe if and only if there are no wolves 
 * at any index j < i. Once a wolf appears, all subsequent birds 
 * are consumed.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int safe_birds = 0;
    bool wolf_seen = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            // Once a wolf is seen, no further birds can be safe
            wolf_seen = true;
        } else {
            // It's a bird
            if (!wolf_seen) {
                safe_birds++;
            }
        }
    }

    cout << safe_birds << "\n";
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