#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chef and Interactive Contests
 * Logic:
 * For each contestant with rating R:
 * If R >= r, they are a "Good boi".
 * Otherwise, they are a "Bad boi".
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long r;
    
    // Read N and r
    if (!(cin >> N >> r)) return 0;

    // Process each contestant
    for (int i = 0; i < N; ++i) {
        long long R;
        cin >> R;
        
        if (R >= r) {
            cout << "Good boi" << "\n";
        } else {
            cout << "Bad boi" << "\n";
        }
    }

    return 0;
}