#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two companies producing vaccines starting from day D1 and D2 with rates V1 and V2.
 * We need to find the smallest day 'd' such that the total vaccines produced >= P.
 * 
 * Total vaccines produced by day 'd':
 * - Company A produces (d - D1 + 1) * V1 vaccines if d >= D1, else 0.
 * - Company B produces (d - D2 + 1) * V2 vaccines if d >= D2, else 0.
 * 
 * Since the number of vaccines produced is monotonically increasing with 'd',
 * we can either use binary search or a simple linear simulation.
 * Given the constraints (D, V <= 100, P <= 1000), a linear simulation is O(P) 
 * which is well within the time limit.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D1, V1, D2, V2, P;
    if (!(cin >> D1 >> V1 >> D2 >> V2 >> P)) return 0;

    int total_vaccines = 0;
    int day = 0;

    // Simulate day by day until total_vaccines >= P
    while (total_vaccines < P) {
        day++;
        if (day >= D1) {
            total_vaccines += V1;
        }
        if (day >= D2) {
            total_vaccines += V2;
        }
    }

    cout << day << "\n";

    return 0;
}