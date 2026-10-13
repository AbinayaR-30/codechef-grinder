#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three regions A, B, and C with populations P_A, P_B, and P_C.
 * Conflict rules:
 * - Region B cannot be with A.
 * - Region B cannot be with C.
 * 
 * Possible valid combinations:
 * 1. Invite people from A and C (since A and C have no conflict with each other).
 *    Total = P_A + P_C
 * 2. Invite people from B only.
 *    Total = P_B
 * 
 * We want to maximize the number of people, so we take max(P_A + P_C, P_B).
 * Constraints: P_A, P_B, P_C <= 1000. The sum will not exceed 2000, 
 * so standard 'int' is sufficient, but 'long long' is used for safety.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long pa, pb, pc;
        cin >> pa >> pb >> pc;
        
        // Option 1: Invite A and C
        long long option1 = pa + pc;
        
        // Option 2: Invite B
        long long option2 = pb;
        
        // Output the maximum of the two valid scenarios
        cout << max(option1, option2) << "\n";
    }
    
    return 0;
}