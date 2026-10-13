# [Guess the bottom face (BOTTOM)](https://www.codechef.com/problems/BOTTOM)

- **Difficulty Rating**: 815
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the value on the bottom face of a standard six-sided die, given the value shown on the top face. In a standard die, the sum of the numbers on any two opposite faces is always 7.

## Intuition & Mathematical Observation
A standard die has faces numbered 1 through 6. The key property provided is that opposite faces sum to 7. 
- If the top face is $X$, and the bottom face is $Y$, then the relationship is defined by the equation:
  $$X + Y = 7$$
- To find the bottom face ($Y$), we simply rearrange the equation:
  $$Y = 7 - X$$

Since the input $X$ is guaranteed to be between 1 and 6, this simple subtraction will always yield the correct opposite face value.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time arithmetic operation.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input and result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem states that for a regular dice, the sum of opposite faces is 7.
 * Given the top face value X, the bottom face value Y must satisfy X + Y = 7.
 * Therefore, Y = 7 - X.
 * 
 * Constraints:
 * 1 <= T <= 6
 * 1 <= X <= 6
 * 
 * Time Complexity: O(T), where T is the number of test cases.
 * Space Complexity: O(1), as we only use a few variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // Calculate the bottom face value
        int bottom = 7 - x;
        
        // Output the result
        cout << bottom << "\n";
    }

    return 0;
}
```