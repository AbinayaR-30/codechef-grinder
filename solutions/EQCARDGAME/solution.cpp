#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has 52 cards. There are K people in total.
 * She needs to distribute the cards equally among K people.
 * Let N be the number of cards remaining after discarding some.
 * N must be a multiple of K, and N <= 52.
 * To minimize the number of discarded cards (52 - N), 
 * we need to maximize N such that N <= 52 and N % K == 0.
 * 
 * The largest multiple of K less than or equal to 52 is:
 * N = (52 / K) * K
 * The number of discarded cards is 52 - N.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int k;
        cin >> k;
        
        // Calculate the largest multiple of k less than or equal to 52
        int remaining_cards = (52 / k) * k;
        
        // The number of cards to discard
        int discarded = 52 - remaining_cards;
        
        cout << discarded << "\n";
    }
    
    return 0;
}