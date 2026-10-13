#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To form the maximum number from three digits, we should sort the digits 
 * in descending order. For example, if rolls are 3, 2, 5, the maximum 
 * number is 532.
 * 
 * Algorithm:
 * 1. Read the three dice values for Alice and store them in a vector/array.
 * 2. Read the three dice values for Bob and store them in a vector/array.
 * 3. Sort both arrays in descending order.
 * 4. Construct the integer values (or compare lexicographically) to determine the winner.
 * 5. Since the numbers are always 3 digits, comparing the sorted arrays 
 *    element by element is equivalent to comparing the formed numbers.
 */

void solve() {
    vector<int> a(3), b(3);
    for (int i = 0; i < 3; ++i) cin >> a[i];
    for (int i = 0; i < 3; ++i) cin >> b[i];

    // Sort in descending order to get the largest possible number
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    // Compare the sorted arrays
    if (a > b) {
        cout << "Alice" << "\n";
    } else if (b > a) {
        cout << "Bob" << "\n";
    } else {
        cout << "Tie" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}