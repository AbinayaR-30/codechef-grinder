# [Chef and String (RECNDSTR)](https://www.codechef.com/problems/RECNDSTR)

- **Difficulty Rating**: 1206
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$, we define two operations:
1. **Left Shift ($L$):** Move the first character of the string to the end. (e.g., `abc` becomes `bca`).
2. **Right Shift ($R$):** Move the last character of the string to the beginning. (e.g., `abc` becomes `cab`).

We need to determine if there exists a string $V$ such that shifting $V$ to the left results in $S$ AND shifting $V$ to the right results in $S$. In simpler terms, we must check if the left shift of $S$ is equal to the right shift of $S$.

## Intuition & Mathematical Observation
Let $L(V) = S$ and $R(V) = S$.
- If $L(V) = S$, then $V$ must be the right shift of $S$ (i.e., $V = R(S)$).
- If $R(V) = S$, then $V$ must be the left shift of $S$ (i.e., $V = L(S)$).

Substituting these, the condition $L(V) = R(V) = S$ implies that $L(S)$ must be equal to $R(S)$. 

**Edge Cases:**
- If the length of the string is 1 or 2, the left shift and right shift will always result in the same string (e.g., "aa" $\rightarrow$ "aa", "ab" $\rightarrow$ "ba" is not equal, but for length 2, the logic holds that $L(S) == R(S)$ is the required condition). Actually, for length 2, "ab" $\rightarrow$ $L$="ba", $R$="ba", so they are equal. For length 1, "a" $\rightarrow$ $L$="a", $R$="a", they are equal. Thus, the logic holds for all $N$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We perform string slicing and concatenation, which takes linear time relative to the string length.
- **Space Complexity**: $O(N)$ to store the shifted versions of the string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For a valid V to exist such that L(V) = S and R(V) = S,
 * it must be true that L(S) == R(S).
 * 
 * L(S) = S[1...n-1] + S[0]
 * R(S) = S[n-1] + S[0...n-2]
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    // Strings of length 1 or 2 will always satisfy the condition 
    // because L(S) and R(S) will result in the same characters.
    if (n <= 2) {
        cout << "YES" << "\n";
        return;
    }
    
    // Construct L(S)
    string left_shifted = s.substr(1) + s[0];
    
    // Construct R(S)
    string right_shifted = s[n - 1] + s.substr(0, n - 1);
    
    if (left_shifted == right_shifted) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
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