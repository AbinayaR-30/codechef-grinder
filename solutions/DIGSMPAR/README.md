# [Digit Sum Parities (DIGSMPAR)](https://www.codechef.com/problems/DIGSMPAR)

- **Difficulty Rating**: 1077
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to find the smallest integer $X > N$ such that the parity of the sum of digits of $X$ is different from the parity of the sum of digits of $N$.

## Intuition & Mathematical Observation
The parity of the sum of digits changes frequently as we increment a number. For example, if $N=19$, the digit sum is $1+9=10$ (even). The next number $20$ has a digit sum of $2+0=2$ (even). The next number $21$ has a digit sum of $2+1=3$ (odd). 

Since the parity of the digit sum changes at least once every few increments (and at most every 10 increments, as adding 1 to a number not ending in 9 simply increases the digit sum by 1, flipping the parity), we can simply perform a linear search starting from $N+1$. We check each subsequent integer until we find one whose digit sum parity differs from the parity of the digit sum of $N$. Given the constraints ($N \le 10^9$), this approach is extremely efficient.

## Complexity Analysis
- **Time Complexity**: $O(T \cdot K \cdot \log_{10}(N))$, where $T$ is the number of test cases, $K$ is the small constant number of increments required to find the parity change (usually $K \le 10$), and $\log_{10}(N)$ is the number of digits in $N$. This is well within the time limit.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the current number and its digit sum.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N and need to find the smallest X > N such that
 * parity(digitSum(N)) != parity(digitSum(X)).
 * 
 * Since N < 10^9, the digit sum is at most 9*9 = 81.
 * The parity of the digit sum changes very frequently as we increment N.
 * In fact, for any N, checking N+1, N+2, ... will find the required X 
 * very quickly (usually within a few increments).
 */

int getDigitSum(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

void solve() {
    long long n;
    cin >> n;
    
    int targetParity = getDigitSum(n) % 2;
    long long x = n + 1;
    
    while (true) {
        if (getDigitSum(x) % 2 != targetParity) {
            cout << x << "\n";
            break;
        }
        x++;
    }
}

int main() {
    // Optimize I/O operations
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