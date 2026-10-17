# [Weapon Value (SC31)](https://www.codechef.com/problems/SC31)

- **Difficulty Rating**: 1204
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ contestants, each possessing a set of 10 different types of weapons, represented as a binary string of length 10. When two contestants battle, for each weapon type, if both possess it, the weapon is destroyed (both lose it). If only one possesses it, the winner keeps it. We need to find the total number of weapons the final winner has after all contestants have battled.

## Intuition & Mathematical Observation
The core of the problem lies in the rules of the "battle":
- If both have the weapon (1 and 1), it is destroyed (becomes 0).
- If one has it and the other doesn't (1 and 0, or 0 and 1), the weapon remains (becomes 1).
- If neither has it (0 and 0), it remains absent (becomes 0).

This logic is exactly equivalent to the **XOR (exclusive OR) operation**. Since the XOR operation is both associative and commutative, the order in which the battles occur does not matter. The final state of the weapons is simply the XOR sum of all the binary strings provided. 

To solve this:
1. Convert each 10-character binary string into an integer (bitmask).
2. XOR all these integers together.
3. Count the number of set bits (1s) in the resulting integer.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \times L)$, where $T$ is the number of test cases, $N$ is the number of contestants, and $L$ is the length of the string (fixed at 10). Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(1)$, as we only store a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem states that when two contestants battle, for each weapon type j,
 * if both have it, it is destroyed. If only one has it, the winner keeps it.
 * This is equivalent to the XOR operation on the bit representation of the weapons.
 * 
 * Let S_i be the bitmask of weapons for contestant i.
 * When two contestants with masks A and B battle, the resulting mask is A ^ B.
 * Since the XOR operation is associative and commutative (A ^ B) ^ C = A ^ (B ^ C),
 * the final state of the winner will always be the XOR sum of all initial weapon masks,
 * regardless of the order of battles or who wins.
 * 
 * The number of weapons the winner has is simply the number of set bits (popcount)
 * in the XOR sum of all input strings.
 */

void solve() {
    int N;
    cin >> N;
    
    // Since each string has length 10, we can represent it as an integer.
    // We initialize the result with 0.
    int final_mask = 0;
    
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        
        // Convert binary string to integer
        int current_mask = 0;
        for (int j = 0; j < 10; ++j) {
            if (s[j] == '1') {
                current_mask |= (1 << (9 - j));
            }
        }
        
        // XOR the current mask into the final result
        final_mask ^= current_mask;
    }
    
    // Count the number of set bits in the final mask
    int weapon_count = 0;
    for (int i = 0; i < 10; ++i) {
        if ((final_mask >> i) & 1) {
            weapon_count++;
        }
    }
    
    cout << weapon_count << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```