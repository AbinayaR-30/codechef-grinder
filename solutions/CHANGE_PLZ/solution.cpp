#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * You owe X dollars. You give 100 dollars.
 * The change due is (100 - X).
 * The driver only has 10 dollar bills.
 * The driver can pay back the largest multiple of 10 that is less than or equal to (100 - X).
 * 
 * Let R = 100 - X.
 * We need to find the largest multiple of 10 <= R.
 * This is equivalent to (R / 10) * 10 using integer division.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x;
        cin >> x;
        
        // Calculate the amount the driver owes back
        int change_due = 100 - x;
        
        // The driver can only return multiples of 10.
        // Integer division by 10 truncates the remainder, 
        // effectively finding the floor of the number of 10-dollar bills.
        int result = (change_due / 10) * 10;
        
        cout << result << "\n";
    }
    
    return 0;
}