#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three points (Chef, Head Server, Sous-chef). Let them be P1, P2, P3.
 * Two points can communicate if the Euclidean distance between them is <= R.
 * This is equivalent to distance squared <= R^2.
 * We need to check if the graph formed by these 3 nodes is connected.
 * Since there are only 3 nodes, the graph is connected if:
 * 1. (P1-P2 connected AND P2-P3 connected) OR
 * 2. (P1-P2 connected AND P1-P3 connected) OR
 * 3. (P2-P3 connected AND P1-P3 connected)
 * Essentially, we need at least two pairs to be within range R.
 */

typedef long long ll;

ll distSq(ll x1, ll y1, ll x2, ll y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void solve() {
    ll R;
    cin >> R;
    ll R2 = R * R;
    
    ll x[3], y[3];
    for (int i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i];
    }
    
    // Calculate squared distances between all pairs
    ll d12 = distSq(x[0], y[0], x[1], y[1]);
    ll d23 = distSq(x[1], y[1], x[2], y[2]);
    ll d13 = distSq(x[0], y[0], x[2], y[2]);
    
    // Check connectivity
    bool c12 = (d12 <= R2);
    bool c23 = (d23 <= R2);
    bool c13 = (d13 <= R2);
    
    // For 3 nodes to be connected, we need at least 2 edges
    int connections = 0;
    if (c12) connections++;
    if (c23) connections++;
    if (c13) connections++;
    
    if (connections >= 2) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
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