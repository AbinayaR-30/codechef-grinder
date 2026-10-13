# [Dice Number (DICENUM)](https://www.codechef.com/problems/DICENUM)

- **Difficulty Rating**: 994
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob each roll three six-sided dice. They want to form the largest possible 3-digit number using their respective three dice values. Your task is to determine who forms the larger number, or if they form the same number (a tie).

## Intuition & Mathematical Observation
To form the largest possible number from a set of digits, the digits must be arranged in **descending order**. For example, if the dice rolls are $\{3, 2, 5\}$, the largest number is $532$.

Since both Alice and Bob have exactly three digits, we can compare the numbers they form by comparing their sorted digits:
1. Sort Alice's digits in descending order: $A_1, A_2, A_3$ (where $A_1 \ge A_2 \ge A_3$).
2. Sort Bob's digits in descending order: $B_1, B_2, B_3$ (where $B_1 \ge B_2 \ge B_3$).
3. Compare the resulting sequences lexicographically. In C++, comparing two `std::vector<int>` objects using the `>` or `<` operators performs a lexicographical comparison, which is exactly what we need to determine which 3-digit number is larger.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Sorting three elements takes constant time ($3 \log 3$), and the comparison is also constant time.
- **Space Complexity**: $O(1)$, as we only store a fixed number of integers (six dice values) regardless of the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To form the maximum number from three digits, we should sort the digits 
 * in descending order. For example, if rolls are 3, 2, 5, the maximum 
 * number is 532.
 * 
 * Algorithm:
 * 1. Read the three dice values for Alice and store them in a vector/array.
 * 2. Read the three dice values for Bob and store them in a vector/array.
 * 3. Sort both arrays in descending order.
 * 4. Construct the integer values (or compare lexicographically) to determine the winner.
 * 5. Since the numbers are always 3 digits, comparing the sorted arrays 
 *    element by element is equivalent to comparing the formed numbers.
 */

void solve() {
    vector<int> a(3), b(3);
    for (int i = 0; i < 3; ++i) cin >> a[i];
    for (int i = 0; i < 3; ++i) cin >> b[i];

    // Sort in descending order to get the largest possible number
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    // Compare the sorted arrays lexicographically
    if (a > b) {
        cout << "Alice" << "\n";
    } else if (b > a) {
        cout << "Bob" << "\n";
    } else {
        cout << "Tie" << "\n";
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