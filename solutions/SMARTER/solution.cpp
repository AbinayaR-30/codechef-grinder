#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Tortoise time (T_tortoise) = ceil(L / V1)
 * Since L and V1 are integers, ceil(L / V1) can be calculated as (L + V1 - 1) / V1 using integer division.
 * 
 * Hare time (T_hare) = ceil(L / V2)
 * Let 'w' be the integer wait time.
 * Total time for hare = w + ceil(L / V2)
 * The problem states the hare's reported time is the ceiling of the actual time.
 * So, reported time = ceil(w + L / V2) = w + ceil(L / V2).
 * 
 * Condition to win:
 * w + ceil(L / V2) < ceil(L / V1)
 * w < ceil(L / V1) - ceil(L / V2)
 * 
 * Since w must be an integer >= 0, the maximum w is:
 * ceil(L / V1) - ceil(L / V2) - 1
 * 
 * If this value is < 0, the hare cannot win, output -1.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long L, V1, V2;
        cin >> L >> V1 >> V2;

        // Calculate ceil(L / V1) using integer arithmetic
        long long t_tortoise = (L + V1 - 1) / V1;
        
        // Calculate ceil(L / V2) using integer arithmetic
        long long t_hare_run = (L + V2 - 1) / V2;

        // Condition: w + t_hare_run < t_tortoise
        // w < t_tortoise - t_hare_run
        // Max integer w = t_tortoise - t_hare_run - 1
        long long max_w = t_tortoise - t_hare_run - 1;

        if (max_w < 0) {
            cout << -1 << "\n";
        } else {
            cout << max_w << "\n";
        }
    }

    return 0;
}