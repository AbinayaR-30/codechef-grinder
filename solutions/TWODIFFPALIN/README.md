# [Two Different Palindromes (TWODIFFPALIN)](https://www.codechef.com/problems/TWODIFFPALIN)

- **Difficulty Rating**: 1216
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, determine if it is possible to construct two **different** binary strings that are both palindromes and contain exactly $A$ zeros and $B$ ones.

## Intuition & Mathematical Observation
To form a palindrome, the counts of characters must satisfy specific parity conditions:
1. **Parity Constraint**: 
   - If the total length ($A+B$) is even, both $A$ and $B$ must be even. If both are odd, it is impossible to form even a single palindrome.
   - If the total length ($A+B$) is odd, exactly one of $A$ or $B$ must be odd (the one that will occupy the middle position).

2. **Uniqueness Constraint**:
   - If $A=1$ or $B=1$, we are severely restricted. For example, if $A=1$ and $B=2$, the only possible palindrome is `101`. If $A=1$ and $B=4$, the only possible palindrome is `11011`. In these cases, we cannot form *two* different palindromes.
   - If $A$ and $B$ are both even and greater than 0, we can always construct at least two distinct palindromes by varying the arrangement of the characters (e.g., placing the 0s at the ends vs. placing the 1s at the ends).
   - If one is even and the other is odd (and both are $> 1$), we can also construct at least two distinct palindromes.

**Conclusion**:
We can construct two different palindromes if and only if:
- Neither $A$ nor $B$ is 1.
- It is not the case that both $A$ and $B$ are odd.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic checks.
- **Space Complexity**: $O(1)$, as no extra data structures are used.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct two different binary strings that are both palindromes
 * and contain exactly A zeros and B ones.
 * 
 * Condition for existence of at least one palindrome:
 * - If A+B is even, both A and B must be even.
 * - If A+B is odd, exactly one of A or B must be odd.
 * 
 * Condition for existence of two different palindromes:
 * - If A=1 or B=1, we can only form one unique palindrome.
 * - If both A and B are odd, we cannot form any palindrome.
 */

void solve() {
    long long A, B;
    cin >> A >> B;

    // If both are odd, total length is even, but counts are odd -> Impossible
    // If either A or B is 1, we can only form one unique palindrome structure
    if ((A % 2 != 0 && B % 2 != 0) || (A == 1 || B == 1)) {
        cout << "No" << "\n";
    } else {
        cout << "Yes" << "\n";
    }
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