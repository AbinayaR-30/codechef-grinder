# [Encoded String (DECODEIT)](https://www.codechef.com/problems/DECODEIT)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to decode a string of length $N$ (where $N$ is a multiple of 4) consisting of '0's and '1's. The string is composed of 4-bit segments, where each segment represents one of the first 16 lowercase English letters ('a' through 'p'). We need to map each 4-bit binary sequence to its corresponding character based on a binary search logic.

## Intuition & Mathematical Observation
The encoding scheme follows a binary search pattern over the range $[0, 15]$:
1. The first bit determines if the character is in the first half (0-7) or the second half (8-15).
2. The second bit narrows it down to a quarter, the third to an eighth, and the fourth to a specific index.

Mathematically, a 4-bit binary string $b_1b_2b_3b_4$ represents the integer value:
$$\text{Value} = b_1 \cdot 2^3 + b_2 \cdot 2^2 + b_3 \cdot 2^1 + b_4 \cdot 2^0$$
Since the alphabet starts at 'a' (index 0), the character can be retrieved simply by calculating this integer value and adding it to the ASCII value of 'a'.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the input string. We iterate through the string once, processing each 4-bit block in constant time.
- **Space Complexity**: $O(N)$ to store the input string and the resulting decoded string. If processed as a stream, this could be reduced to $O(1)$ auxiliary space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem describes a binary encoding scheme for the first 16 lowercase English letters (a-p).
 * Each character is represented by 4 bits.
 * The encoding process is essentially a binary search over the range [0, 15].
 * 
 * For a 4-bit sequence b1 b2 b3 b4:
 * The value can be calculated as: b1*8 + b2*4 + b3*2 + b4*1.
 * This value corresponds directly to the index of the letter in the alphabet (0 for 'a', 1 for 'b', ..., 15 for 'p').
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string result = "";
    // Process the string in chunks of 4 bits
    for (int i = 0; i < n; i += 4) {
        int val = 0;
        // Convert 4-bit binary string to integer
        // bit 0: 2^3 = 8, bit 1: 2^2 = 4, bit 2: 2^1 = 2, bit 3: 2^0 = 1
        if (s[i] == '1') val += 8;
        if (s[i + 1] == '1') val += 4;
        if (s[i + 2] == '1') val += 2;
        if (s[i + 3] == '1') val += 1;
        
        // Map the integer value (0-15) to the corresponding character ('a'-'p')
        result += (char)('a' + val);
    }
    cout << result << "\n";
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