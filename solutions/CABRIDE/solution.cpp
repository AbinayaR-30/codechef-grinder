#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Cost per cab = max(200, 100 * X) where X <= 4.
 * X=1: 200
 * X=2: 200
 * X=3: 300
 * X=4: 400
 * 
 * For N=1: 200
 * For N=2: 200
 * For N=3: 300
 * For N=4: 400
 * For N=5: 500 (3+2)
 * For N=6: 600 (3+3)
 * For N=7: 700 (4+3)
 * For N=8: 800 (4+4)
 * 
 * Pattern: For N > 1, the cost is 100 * N. For N = 1, the cost is 200.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 200 << "\n";
        } else {
            cout << 100 * n << "\n";
        }
    }
    return 0;
}