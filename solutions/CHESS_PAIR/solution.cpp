#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have 2N total players, X of whom are rated.
 * We want to minimize the number of rated players paired with other rated players.
 * 
 * Let R = X (number of rated players)
 * Let U = 2N - X (number of unrated players)
 * 
 * Each pair consists of 2 players.
 * To minimize rated-rated pairs, we should prioritize pairing rated players with unrated players.
 * Each rated-unrated pair uses 1 rated player and 1 unrated player.
 * We can form at most U such pairs (since we only have U unrated players).
 * 
 * After forming as many rated-unrated pairs as possible:
 * 1. If X <= N, we can pair all X rated players with unrated players.
 *    The number of rated players with rated opponents is 0.
 * 2. If X > N, we have more rated players than unrated players.
 *    We use all U unrated players to pair with U rated players.
 *    Remaining rated players = X - U = X - (2N - X) = 2X - 2N.
 *    These remaining rated players must be paired with each other.
 *    Since each such pair consists of 2 rated players, the number of rated players 
 *    with rated opponents is simply the number of remaining rated players, which is 2X - 2N.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        // Total players = 2 * n
        // Rated players = x
        // Unrated players = 2 * n - x
        
        // If x <= n, we can pair every rated player with an unrated player.
        // If x > n, we have x - (2n - x) = 2x - 2n rated players left over
        // who must be paired with each other.
        
        if (x <= n) {
            cout << 0 << "\n";
        } else {
            cout << (2 * x - 2 * n) << "\n";
        }
    }

    return 0;
}