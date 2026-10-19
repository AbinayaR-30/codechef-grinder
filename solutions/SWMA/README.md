# [Swapping Marks Digits (SWMA)](https://www.codechef.com/problems/SWMA)

- **Difficulty Rating**: 964
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob each have a 2-digit score (guaranteed not to contain the digit '0'). Alice can choose to reverse the digits of her score, Bob can choose to reverse the digits of his score, or both can choose to reverse their scores, or neither can. We need to determine if there exists any combination of these choices such that Alice's final score is strictly greater than Bob's final score.

## Intuition & Mathematical Observation
Since the scores are always 2-digit numbers, there are only two possible states for each person: their original score and their reversed score. 

Let $A$ be Alice's score and $B$ be Bob's score. Let $A_{rev}$ and $B_{rev}$ be their respective reversed values. The possible pairs of final scores $(A', B')$ are:
1. $(A, B)$
2. $(A, B_{rev})$
3. $(A_{rev}, B)$
4. $(A_{rev}, B_{rev})$

The problem asks if $A' > B'$ is possible in **any** of these four scenarios. We can simply calculate the reversed values using basic arithmetic (`(n % 10) * 10 + (n / 10)`) and check the condition for all four cases using a logical OR operator.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we are performing a constant number of arithmetic operations and comparisons regardless of the input values, the time complexity is constant.
- **Space Complexity**: $O(1)$. We only use a few integer variables to store the scores and their reversed versions, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has score A, Bob has score B. Both are 2-digit numbers without '0'.
 * Alice can reverse her score (A_rev) and/or Bob's score (B_rev).
 * There are 4 possible scenarios for the final scores (A', B'):
 * 1. (A, B)
 * 2. (A, B_rev)
 * 3. (A_rev, B)
 * 4. (A_rev, B_rev)
 * 
 * If in any of these scenarios A' > B', the answer is "Yes".
 * Otherwise, the answer is "No".
 */

int reverse_num(int n) {
    int tens = n / 10;
    int units = n % 10;
    return units * 10 + tens;
}

void solve() {
    int A, B;
    cin >> A >> B;
    
    int A_rev = reverse_num(A);
    int B_rev = reverse_num(B);
    
    // Check all 4 combinations
    if (A > B || A > B_rev || A_rev > B || A_rev > B_rev) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
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