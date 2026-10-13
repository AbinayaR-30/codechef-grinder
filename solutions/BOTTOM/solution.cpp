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