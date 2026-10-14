# [Three Boxes (THREEBOX)](https://www.codechef.com/problems/THREEBOX)

- **Difficulty Rating**: 1183
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given three items with sizes $A$, $B$, and $C$, and an unlimited supply of bags, each with a capacity $D$. We need to find the minimum number of bags required to store all three items such that the sum of the sizes of items in any single bag does not exceed $D$.

## Intuition & Mathematical Observation
Since we only have three items, the number of bags required will be either 1, 2, or 3. We can determine the minimum number of bags using a greedy approach based on the constraints:

1.  **1 Bag**: If the sum of all three items ($A + B + C$) is less than or equal to $D$, we can fit all items into a single bag.
2.  **2 Bags**: If we cannot fit all items in one bag, we check if we can fit them into two. Given the sorted order $A \le B \le C$, we can fit the items into two bags if any pair of items fits into one bag (leaving the third item for the second bag). Specifically, if $(A + B) \le D$ or $(A + C) \le D$, we can group them efficiently. Note that if $(A + B + C) > D$, we know we need at least 2 bags.
3.  **3 Bags**: If neither of the above conditions is met, it is impossible to group any two items together in a single bag. Therefore, each item must be placed in its own bag, requiring 3 bags.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of arithmetic operations and comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and perform calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three boxes with sizes A, B, and C, and bags of size D.
 * Constraints: 1 <= A <= B <= C <= D <= 100.
 * 
 * Strategy:
 * 1. If A + B + C <= D, we only need 1 bag.
 * 2. If A + B + C > D, we check if we can fit two boxes in one bag.
 *    Since A <= B <= C, the largest possible pairs are (A+B), (A+C), or (B+C).
 *    If (A + B) <= D or (A + C) <= D, we can put two items in one bag and the third in another (2 bags).
 * 3. If neither of the above, we need 3 bags.
 */

void solve() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    if (A + B + C <= D) {
        cout << 1 << "\n";
    } else if (A + B <= D || A + C <= D) {
        // We can fit two boxes in one bag, leaving the third in another.
        cout << 2 << "\n";
    } else {
        // Cannot fit any pair in one bag.
        cout << 3 << "\n";
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