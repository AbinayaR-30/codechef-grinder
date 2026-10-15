# [Chef and Interactive Contests (CHFINTRO)](https://www.codechef.com/problems/CHFINTRO)

- **Difficulty Rating**: 951
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is organizing a contest and has set a minimum rating threshold $r$. There are $N$ contestants, each with a specific rating $R$. For each contestant, we need to determine if they are eligible to participate. If a contestant's rating $R$ is greater than or equal to $r$, they are considered a "Good boi"; otherwise, they are a "Bad boi".

## Intuition & Mathematical Observation
The problem is a straightforward implementation task. For every contestant, we are given their rating $R$ and the threshold $r$. The condition for being a "Good boi" is simply $R \ge r$. 

Since we need to process $N$ contestants independently, we can read each rating one by one and perform a simple comparison. No complex data structures or algorithms are required.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of contestants. We iterate through the list of ratings exactly once, performing a constant-time comparison for each.
- **Space Complexity**: $O(1)$, as we only store a few variables ($N, r, R$) regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chef and Interactive Contests
 * Logic:
 * For each contestant with rating R:
 * If R >= r, they are a "Good boi".
 * Otherwise, they are a "Bad boi".
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long r;
    
    // Read N (number of contestants) and r (threshold rating)
    if (!(cin >> N >> r)) return 0;

    // Process each contestant
    for (int i = 0; i < N; ++i) {
        long long R;
        cin >> R;
        
        // Check eligibility condition
        if (R >= r) {
            cout << "Good boi" << "\n";
        } else {
            cout << "Bad boi" << "\n";
        }
    }

    return 0;
}
```