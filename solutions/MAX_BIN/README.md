# [Max Binary (MAX_BIN)](https://www.codechef.com/problems/MAX_BIN)

- **Difficulty Rating**: 1143
- **Solved in**: 3 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$ and an integer $K$, you are allowed to perform two types of operations at most $K$ times in total:
1. **Type 1**: Append a '0' to the end of the string.
2. **Type 2**: Change any '0' in the string to a '1'.

The goal is to maximize the value of the binary string after performing at most $K$ operations.

## Intuition & Mathematical Observation
To maximize the value of a binary string, we prioritize the most significant bits (the leftmost positions).

1. **Prioritizing the Most Significant Bit**: If the first bit $S[0]$ is '0', changing it to '1' significantly increases the value of the number (effectively adding $2^{N-1}$ to the value). This is always more beneficial than appending '0's or changing '0's at less significant positions. Therefore, if $S[0] == '0'$ and $K > 0$, we perform a Type 2 operation to flip it to '1'.
2. **Appending vs. Flipping**: After ensuring the first bit is '1', we have remaining operations. Appending a '0' to the end of a binary string is equivalent to multiplying the number by 2. Since we want to maximize the integer value, appending '0's is highly efficient as it shifts all existing bits to the left, increasing their place value. 
3. **Strategy**:
   - If $S[0] == '0'$, use one operation to flip it to '1'.
   - Use all remaining operations to append '0's to the end of the string.

## Complexity Analysis
- **Time Complexity**: $O(N + K)$, where $N$ is the length of the string and $K$ is the number of operations. We iterate through the string once and perform $K$ append operations.
- **Space Complexity**: $O(N + K)$ to store the resulting string.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Strategy:
 * 1. If S[0] == '0', we should change it to '1' using one Type 2 operation.
 *    This costs 1 operation and maximizes the most significant bit.
 * 2. Use all remaining operations as Type 1 (appending '0's at the end).
 *    Appending '0' at the end is equivalent to multiplying by 2, which 
 *    increases the magnitude of the number significantly.
 */

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // Step 1: If the first bit is '0', change it to '1'
    if (s[0] == '0') {
        s[0] = '1';
        k--;
    }

    // Step 2: Append '0's at the end using remaining k
    // Each Type 1 operation adds a '0' at the end.
    string suffix = "";
    for (int i = 0; i < k; ++i) {
        suffix += '0';
    }

    cout << s << suffix << "\n";
}

int main() {
    // Optimize I/O operations
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