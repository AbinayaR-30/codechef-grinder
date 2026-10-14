#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has A cookies, Bob has B cookies. A > B.
 * Let x be the number of cookies Alice gives to Bob.
 * After the transfer:
 * Alice has A - x cookies.
 * Bob has B + x cookies.
 * For them to be equal: A - x = B + x
 * A - B = 2x
 * x = (A - B) / 2
 * 
 * For x to be a valid number of cookies (an integer), (A - B) must be even.
 * Also, since Alice gives x cookies, x must be positive (x > 0).
 * Since A > B, A - B is always positive, so x will be positive if (A - B) is even.
 * 
 * Constraints: 1 <= B < A <= 10.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // The problem description implies a single line of input, 
    // but standard competitive programming practice handles test cases if provided.
    // Given the constraints and format, we read A and B.
    long long A, B;
    if (!(cin >> A >> B)) return 0;

    long long diff = A - B;

    // Check if the difference is even
    if (diff % 2 == 0) {
        cout << (diff / 2) << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}