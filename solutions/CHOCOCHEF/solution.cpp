#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We need to distribute N chocolates into three jars (a, b, c) such that:
 * 1. a + b + c = N
 * 2. At least one jar has an odd number of chocolates.
 * 3. Exactly two jars have the same number of chocolates.
 * 4. a, b, c >= 1.
 * 
 * Construction:
 * Let the jars be (1, 1, N-2).
 * - Sum: 1 + 1 + (N-2) = N.
 * - Equality: Two jars have 1, so exactly two are equal (unless N-2 = 1, i.e., N=3, but N >= 4).
 * - Odd: 1 is odd, so at least one jar is odd.
 * - Positivity: Since N >= 4, N-2 >= 2, so all jars >= 1.
 */

void solve() {
    long long N;
    if (!(cin >> N)) return;
    cout << "1 1 " << N - 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}