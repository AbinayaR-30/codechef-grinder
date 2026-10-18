#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Stairs:
 *    Distance = N * sqrt(2)
 *    Velocity = V1
 *    Time_stairs = (N * sqrt(2)) / V1
 * 
 * 2. Elevator:
 *    The elevator starts at ground, goes to N (distance N), then back to ground (distance N).
 *    Total distance = 2 * N
 *    Velocity = V2
 *    Time_elevator = (2 * N) / V2
 * 
 * To compare (N * sqrt(2)) / V1 and (2 * N) / V2, we can compare their squares 
 * to avoid floating point precision issues, or simply use double.
 * Since N, V1, V2 are small (up to 100), double precision is sufficient.
 * 
 * Time_stairs^2 = (N^2 * 2) / V1^2
 * Time_elevator^2 = (4 * N^2) / V2^2
 * 
 * We compare (2 / V1^2) with (4 / V2^2).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        double n, v1, v2;
        cin >> n >> v1 >> v2;

        double time_stairs = (n * sqrt(2.0)) / v1;
        double time_elevator = (2.0 * n) / v2;

        if (time_elevator < time_stairs) {
            cout << "Elevator" << "\n";
        } else {
            cout << "Stairs" << "\n";
        }
    }

    return 0;
}