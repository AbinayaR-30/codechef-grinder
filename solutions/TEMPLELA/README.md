# [Temple Land (TEMPLELA)](https://www.codechef.com/problems/TEMPLELA)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine if a given sequence of integers represents a valid "Temple Land" strip. A valid strip must satisfy the following conditions:
1. The length of the strip ($N$) must be odd.
2. The first and last elements must be 1.
3. The sequence must increase by exactly 1 at each step until it reaches the center element, and then decrease by exactly 1 at each step until the end.

## Intuition & Mathematical Observation
To validate the sequence, we can break down the requirements into logical checks:
* **Parity Check**: If $N$ is even, it is impossible to have a single peak element, so we immediately return "no".
* **Boundary Check**: The sequence must start and end with 1. If $H[0] \neq 1$ or $H[N-1] \neq 1$, it is invalid.
* **Pattern Check**: 
    * For the first half (indices $0$ to $N/2$), the value at index $i$ must be $i + 1$.
    * For the second half (indices $N/2 + 1$ to $N-1$), the value at index $i$ must be exactly one less than the value at $i-1$ (i.e., $H[i] = H[i-1] - 1$).

By iterating through the array once and verifying these conditions, we can determine the validity of the strip in linear time.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of elements in the strip. We perform a single pass over the array to validate the values.
- **Space Complexity**: $O(N)$ to store the input array. This can be optimized to $O(1)$ if we process the input stream directly, but $O(N)$ is well within limits for the given constraints.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. The strip must have an odd length (Ni) to have a unique center.
 * 2. The first element must be 1.
 * 3. The sequence must increase by 1 until the center, then decrease by 1.
 * 4. This implies the sequence must be: 1, 2, 3, ..., (Ni+1)/2, ..., 3, 2, 1.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    // Condition 1: Must have an odd length to have a unique center
    if (n % 2 == 0) {
        cout << "no" << "\n";
        return;
    }

    // Condition 2: Must start and end with 1
    if (h[0] != 1 || h[n - 1] != 1) {
        cout << "no" << "\n";
        return;
    }

    int center = n / 2;
    bool possible = true;

    // Check increasing part (0 to center)
    for (int i = 0; i <= center; ++i) {
        if (h[i] != i + 1) {
            possible = false;
            break;
        }
    }

    // Check decreasing part (center + 1 to end)
    if (possible) {
        for (int i = center + 1; i < n; ++i) {
            if (h[i] != h[i - 1] - 1) {
                possible = false;
                break;
            }
        }
    }

    if (possible) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s;
    cin >> s;
    while (s--) {
        solve();
    }
    return 0;
}
```