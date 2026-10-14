# [Count Odd Even Divisors (CNTODDEVEN)](https://www.codechef.com/problems/CNTODDEVEN)

- **Difficulty Rating**: 538
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, the task is to find the total count of its divisors that are odd and the total count of its divisors that are even. We need to output these two counts for each test case.

## Intuition & Mathematical Observation
A divisor $d$ of $N$ is any integer such that $N \pmod d = 0$. 
- An **odd divisor** satisfies $d \pmod 2 \neq 0$.
- An **even divisor** satisfies $d \pmod 2 = 0$.

Given the constraints ($N \le 100$), a brute-force approach is highly efficient. We can iterate through every integer $i$ from $1$ to $N$. For each $i$, we check if it divides $N$ perfectly. If it does, we then check its parity (odd or even) and increment the respective counter.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the input integer. Given $N \le 100$, this performs well within the time limits.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the counts and the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given an integer N, we need to count its odd divisors and even divisors.
 * A divisor d of N is odd if d % 2 != 0.
 * A divisor d of N is even if d % 2 == 0.
 * 
 * Since the constraints are small (N <= 100), we can iterate from 1 to N
 * and check if each number is a divisor of N, then categorize it.
 * 
 * Time Complexity: O(T * N)
 * Space Complexity: O(1)
 */

void solve() {
    int N;
    cin >> N;
    
    int odd_count = 0;
    int even_count = 0;
    
    // Iterate through all numbers from 1 to N to find divisors
    for (int i = 1; i <= N; ++i) {
        if (N % i == 0) {
            // Check if the divisor is odd or even
            if (i % 2 != 0) {
                odd_count++;
            } else {
                even_count++;
            }
        }
    }
    
    cout << odd_count << " " << even_count << "\n";
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}
```