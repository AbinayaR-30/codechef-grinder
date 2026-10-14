#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let TS = 2^k * m, where m is odd.
 * The game proceeds by dividing both TS and JS by 2 as long as both are even.
 * This is equivalent to removing all factors of 2 from both numbers.
 * Let TS' = TS / 2^k = m (which is odd).
 * Let JS = 2^p * n, where n is odd.
 * 
 * The game ends when:
 * 1. Both are odd: TS_reduced = m, JS_reduced = n. If m == n, it's a tie.
 * 2. TS is even, JS is odd: Tom wins.
 * 3. TS is odd, JS is even: Jerry wins.
 * 
 * After dividing both by 2^min(k, p):
 * - If k < p: TS becomes odd, JS becomes even. Jerry wins.
 * - If k > p: TS becomes even, JS becomes odd. Tom wins.
 * - If k == p: Both become odd. If m == n, it's a tie.
 * 
 * We need Jerry to win, which happens if k < p.
 * JS = 2^p * n, where 1 <= JS <= TS.
 * Since k < p, JS must be a multiple of 2^(k+1).
 * Let JS = 2^(k+1) * x.
 * Then 2^(k+1) * x <= TS
 * x <= TS / 2^(k+1)
 * The number of such values is floor(TS / 2^(k+1)).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long ts;
        cin >> ts;

        // Find the power of 2 that divides ts
        long long temp_ts = ts;
        long long power_of_2 = 1;
        while (temp_ts % 2 == 0) {
            temp_ts /= 2;
            power_of_2 *= 2;
        }

        // Jerry wins if JS has more factors of 2 than TS.
        // JS must be a multiple of (power_of_2 * 2).
        // The number of multiples of (power_of_2 * 2) up to TS is TS / (power_of_2 * 2).
        long long ans = ts / (power_of_2 * 2);
        
        cout << ans << "\n";
    }

    return 0;
}