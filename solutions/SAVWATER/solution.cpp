#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Each household consumes 'x' liters of mandatory freshwater.
 * Each household consumes 'y' liters of greywater, which is reduced to floor(y/2).
 * Total consumption per household = x + (y / 2).
 * Total consumption for H households = H * (x + (y / 2)).
 * We need to check if this total consumption <= C.
 * 
 * Constraints:
 * H, x, y <= 10, C <= 100.
 * The logic uses integer division (y / 2), which correctly implements floor(y/2).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int H, x, y, C;
        cin >> H >> x >> y >> C;
        
        // Calculate consumption per household
        // Integer division y/2 automatically performs floor(y/2)
        int consumption_per_household = x + (y / 2);
        
        // Calculate total consumption for all households
        int total_consumption = H * consumption_per_household;
        
        // Check if total consumption is within the available capacity C
        if (total_consumption <= C) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}