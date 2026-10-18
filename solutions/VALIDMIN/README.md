# [Valid Minimum (VALIDMIN)](https://www.codechef.com/problems/VALIDMIN)

- **Difficulty Rating**: 1132
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three integers $x, y,$ and $z$, determine if there exist three integers $A, B,$ and $C$ such that:
- $\min(A, B) = x$
- $\min(B, C) = y$
- $\min(C, A) = z$

If such a triplet $(A, B, C)$ exists, output `YES`, otherwise output `NO`.

## Intuition & Mathematical Observation
Let the three given values be $x, y, z$. Without loss of generality, assume we sort these values such that $s_1 \le s_2 \le s_3$.

Consider the properties of the minimum function:
1. If we have three numbers $A, B, C$, let the smallest value among them be $m$. At least two of the pairs $(A, B), (B, C), (C, A)$ must result in the minimum value $m$.
2. For example, if $A$ is the smallest, then $\min(A, B) = A$ and $\min(C, A) = A$. Thus, the two smallest values in the set $\{x, y, z\}$ must be equal.

**Case Analysis:**
- **If $s_1 = s_2 = s_3$**: We can set $A=B=C=s_1$. Then $\min(A, B) = s_1, \min(B, C) = s_1, \min(C, A) = s_1$. This works.
- **If $s_1 = s_2 < s_3$**: We can set $A=s_3, B=s_1, C=s_3$.
    - $\min(A, B) = \min(s_3, s_1) = s_1$
    - $\min(B, C) = \min(s_1, s_3) = s_1$
    - $\min(C, A) = \min(s_3, s_3) = s_3$
    - This matches the set $\{s_1, s_1, s_3\}$. This works.
- **If $s_1 < s_2 \le s_3$**: The two smallest values are distinct. As shown in the logic above, the two smallest values of the set $\{x, y, z\}$ must be equal to the smallest element of $\{A, B, C\}$. If they are not equal, no such $A, B, C$ can satisfy the conditions.

**Conclusion**: A valid triplet exists if and only if the two smallest values among the input are equal ($s_1 = s_2$).

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as sorting three elements takes constant time.
- **Space Complexity**: $O(1)$, as we only store three integers.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * After sorting the three inputs as s1 <= s2 <= s3,
 * a valid triplet (A, B, C) exists if and only if s1 == s2.
 */

void solve() {
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    
    // After sorting, v[0] <= v[1] <= v[2].
    // A valid tuple exists if and only if the two smallest values are equal.
    if (v[0] == v[1]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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