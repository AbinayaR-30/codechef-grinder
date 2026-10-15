# [Reach Codetown (CODETOWN)](https://www.codechef.com/problems/CODETOWN)

- **Difficulty Rating**: 1022
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length 8, determine if it is possible to transform $S$ into the target string `"CODETOWN"`. The transformation rule allows replacing a consonant with another consonant and a vowel with another vowel at any position. Essentially, we must check if the vowel/consonant pattern of the input string $S$ matches the pattern of `"CODETOWN"` exactly.

## Intuition & Mathematical Observation
The problem states that we can only replace a character with another of the same "type" (vowel or consonant). This implies that the property of being a vowel or a consonant is **invariant** at every index $i$ (where $0 \le i < 8$).

1.  **Define Vowels**: The vowels are defined as `{A, E, I, O, U}`. All other uppercase English letters are consonants.
2.  **Analyze the Target**: The target string is `"CODETOWN"`. Let's map its indices to their types:
    *   Index 0: 'C' (Consonant)
    *   Index 1: 'O' (Vowel)
    *   Index 2: 'D' (Consonant)
    *   Index 3: 'E' (Vowel)
    *   Index 4: 'T' (Consonant)
    *   Index 5: 'O' (Vowel)
    *   Index 6: 'W' (Consonant)
    *   Index 7: 'N' (Consonant)
    *   **Pattern**: `C V C V C V C C`
3.  **Strategy**: For any input string $S$, we iterate through each index from 0 to 7. If the type (vowel/consonant) of $S[i]$ does not match the type of `target[i]`, the transformation is impossible. If all positions match, the transformation is possible.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string (which is fixed at 8). Thus, the complexity is $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space to store the target string and helper variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The rule states we can transition from T1 to T2 if:
 * 1. A consonant is replaced by a consonant.
 * 2. A vowel is replaced by a vowel.
 * 
 * This implies that the "vowel-ness" or "consonant-ness" of each position 
 * in the string must be invariant.
 */

bool isVowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void solve() {
    string s;
    cin >> s;
    string target = "CODETOWN";
    
    bool possible = true;
    for (int i = 0; i < 8; ++i) {
        // Check if the vowel/consonant type matches at every index
        if (isVowel(s[i]) != isVowel(target[i])) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```