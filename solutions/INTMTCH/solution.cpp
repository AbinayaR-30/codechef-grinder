#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problem: Interesting Match
 * The problem asks to determine if the absolute difference between two integers X and Y
 * is at most 2.
 * 
 * Constraints: 0 <= X, Y <= 10.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    // Read the two integers directly as per the problem format
    if (cin >> x >> y) {
        // Calculate absolute difference
        int diff = abs(x - y);

        // Check if the difference is at most 2
        if (diff <= 2) {
            cout << "Interesting" << endl;
        } else {
            cout << "Boring" << endl;
        }
    }

    return 0;
}