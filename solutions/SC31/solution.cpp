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