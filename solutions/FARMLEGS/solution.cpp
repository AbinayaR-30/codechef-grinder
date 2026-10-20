#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We want to minimize A = C + H subject to 4C + 2H = N.
 * Since each cow (4 legs) contributes more to the leg count than a chicken (2 legs),
 * we maximize the number of cows to minimize the total number of animals.
 * 
 * C_max = N / 4
 * Remaining legs = N % 4
 * H = (N % 4) / 2
 * Total = C_max + H
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        // Maximize cows to minimize total animals
        int cows = n / 4;
        
        // Remaining legs must be covered by chickens
        int remaining_legs = n % 4;
        int chickens = remaining_legs / 2;
        
        // Output the minimum number of animals
        cout << (cows + chickens) << "\n";
    }
    
    return 0;
}