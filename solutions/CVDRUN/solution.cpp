#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The virus starts at city X and jumps by K each day in a circular arrangement of N cities.
 * This is equivalent to visiting cities (X + i * K) % N for i = 0, 1, 2, ...
 * We need to determine if Y is in this sequence.
 * 
 * Since N is small (up to 1000), we can simulate the process.
 * The sequence will eventually repeat because there are only N possible cities.
 * If we visit a city that has already been visited, we stop.
 * 
 * Complexity:
 * Time: O(N) per test case, as there are at most N distinct cities to visit.
 * Space: O(N) to keep track of visited cities.
 */

void solve() {
    int N, K, X, Y;
    if (!(cin >> N >> K >> X >> Y)) return;

    // visited array to keep track of infected cities
    vector<bool> visited(N, false);
    
    int current = X;
    bool reached = false;
    
    // Simulate the jumps
    while (!visited[current]) {
        visited[current] = true;
        
        if (current == Y) {
            reached = true;
            break;
        }
        
        // Next city calculation
        current = (current + K) % N;
    }
    
    if (reached) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}