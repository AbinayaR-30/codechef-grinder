#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice and Bob play a game where they pick numbers a and b (1 to 5).
 * Sum = a + b.
 * If Sum is odd, Alice wins.
 * If Sum is even, Bob wins.
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= a, b <= 5
 * 
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        // Calculate the sum
        int sum = a + b;
        
        // Check parity
        if (sum % 2 != 0) {
            // Sum is odd, Alice wins
            cout << "Alice" << "\n";
        } else {
            // Sum is even, Bob wins
            cout << "Bob" << "\n";
        }
    }
    
    return 0;
}