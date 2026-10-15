#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The rule states we can transition from T1 to T2 if:
 * 1. A consonant is replaced by a consonant.
 * 2. A vowel is replaced by a vowel.
 * 
 * This implies that the "vowel-ness" or "consonant-ness" of each position 
 * in the string must be invariant. If position 'i' in the starting string 
 * is a vowel, it must be a vowel in the target string 'CODETOWN'. 
 * If it is a consonant, it must remain a consonant.
 * 
 * Vowels: A, E, I, O, U
 * Consonants: All other letters
 * 
 * Target string: "CODETOWN"
 * Indices: 0 1 2 3 4 5 6 7
 * Chars:   C O D E T O W N
 * Types:   C V C V C V C C
 * 
 * We need to check if the input string S has the same vowel/consonant 
 * pattern as "CODETOWN".
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