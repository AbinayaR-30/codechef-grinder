#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a right-angled triangle formed by the ladder side, the base, and the height.
 * Let B be the base (separation), LS be the left side, and RS be the right side.
 * Let H be the height of the ladder.
 * 
 * Case 1: Minimum RS
 * This occurs when the height H is minimized. The smallest possible height occurs 
 * when the LS is the hypotenuse and B is one leg.
 * H^2 + B^2 = LS^2 => H = sqrt(LS^2 - B^2)
 * Then, for the RS, we have H^2 + 0^2 = RS^2 (if we consider the RS vertical)
 * Actually, the problem states: "At one extreme LS can be vertical and at other RS can be vertical."
 * 
 * If LS is vertical: H = LS. Then RS^2 = H^2 + B^2 = LS^2 + B^2. (Maximum RS)
 * If RS is vertical: H = RS. Then LS^2 = H^2 + B^2 = RS^2 + B^2.
 * So, RS^2 = LS^2 - B^2 => RS = sqrt(LS^2 - B^2). (Minimum RS)
 * 
 * Therefore:
 * Min RS = sqrt(LS^2 - B^2)
 * Max RS = sqrt(LS^2 + B^2)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        double b, ls;
        cin >> b >> ls;

        // Calculate minimum RS: sqrt(LS^2 - B^2)
        double min_rs = sqrt(ls * ls - b * b);
        
        // Calculate maximum RS: sqrt(LS^2 + B^2)
        double max_rs = sqrt(ls * ls + b * b);

        // Output with required precision
        cout << fixed << setprecision(5) << min_rs << " " << max_rs << "\n";
    }

    return 0;
}