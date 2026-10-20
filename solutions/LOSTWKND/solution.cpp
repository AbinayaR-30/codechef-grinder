#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has 5 weekdays. For each day i, he has A_i hours of work to do at the office.
 * 1 hour of office work = P hours of home work.
 * Total work required in home hours = (A_1 + A_2 + A_3 + A_4 + A_5) * P.
 * Total available hours in 5 weekdays = 5 * 24 = 120 hours.
 * 
 * If the total work required exceeds 120 hours, Chef must work on the weekend.
 * Otherwise, he can complete the work within the 5 weekdays.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a1, a2, a3, a4, a5, p;
        cin >> a1 >> a2 >> a3 >> a4 >> a5 >> p;
        
        // Calculate total work in home hours
        long long total_work = (a1 + a2 + a3 + a4 + a5) * p;
        
        // Total available hours in 5 days (24 hours per day)
        long long total_available = 5 * 24;
        
        // If total work exceeds available hours, he must work on weekends
        if (total_work > total_available) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}