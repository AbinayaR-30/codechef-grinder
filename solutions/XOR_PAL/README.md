# [Xor Palindrome (XOR_PAL)](https://www.codechef.com/problems/XOR_PAL)

- **Difficulty Rating**: 1129
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $A$ of length $N$, we want to make it a palindrome. In one operation, we can choose any two indices $i$ and $j$ ($1 \le i, j \le N$) and flip the bits at these positions (i.e., $A[i] = A[i] \oplus 1$ and $A[j] = A[j] \oplus 1$). We need to find the minimum number of operations required to make the string a palindrome.

## Intuition & Mathematical Observation
1. **Identify Mismatches**: A string is a palindrome if $A[i] == A[N-1-i]$ for all $0 \le i < N/2$. We iterate through the first half of the string and count the number of pairs $(i, N-1-i)$ where $A[i] \neq A[N-1-i]$. Let this count be `diff`.
2. **Operation Mechanics**: 
   - Each operation allows us to flip two bits. 
   - If we have a mismatching pair $(A[i], A[N-1-i])$, we can fix it by flipping one of the bits. However, flipping one bit affects the palindrome property.
   - By choosing two indices from two different mismatching pairs, we can fix both pairs in a single operation. 
   - If `diff` is even, we can pair up all mismatches and fix them in `diff / 2` operations.
   - If `diff` is odd, we fix `diff - 1` mismatches in `(diff - 1) / 2` operations, and the final remaining mismatch requires one additional operation.
3. **Conclusion**: The total number of operations required is $\lceil \text{diff} / 2 \rceil$, which can be calculated using integer arithmetic as `(diff + 1) / 2`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the string once to count the mismatches.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We count the number of pairs (i, N-1-i) that are not equal.
 * Let this count be 'diff'.
 * Each operation can resolve two such mismatching pairs simultaneously.
 * Therefore, the minimum operations required is ceil(diff / 2).
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    int diff = 0;
    // Count pairs that violate the palindrome property
    for (int i = 0; i < N / 2; ++i) {
        if (A[i] != A[N - 1 - i]) {
            diff++;
        }
    }

    // Each operation can resolve two mismatches.
    // Using integer division to perform ceil(diff / 2.0)
    cout << (diff + 1) / 2 << "\n";
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