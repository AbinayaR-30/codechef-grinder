#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with N. We have two operations:
 * 1. N = N + 1
 * 2. N = next multiple of 5 strictly greater than N.
 * 
 * Since N is small (up to 100), we can use Breadth-First Search (BFS) 
 * to find the shortest path to any multiple of 3.
 * 
 * BFS state: current value of N.
 * Transitions:
 * - N -> N + 1
 * - N -> ((N / 5) + 1) * 5
 */

int solve() {
    int N;
    cin >> N;

    if (N % 3 == 0) return 0;

    // BFS to find the minimum operations
    // Since N <= 100, the reachable numbers won't explode.
    // A simple queue will suffice.
    queue<pair<int, int>> q;
    q.push({N, 0});
    
    // Visited array to prevent infinite loops
    vector<bool> visited(1000, false);
    visited[N] = true;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int val = curr.first;
        int dist = curr.second;

        // Possible next states
        int next1 = val + 1;
        int next2 = ((val / 5) + 1) * 5;

        int next_states[] = {next1, next2};

        for (int next_val : next_states) {
            if (next_val % 3 == 0) return dist + 1;
            if (next_val < 1000 && !visited[next_val]) {
                visited[next_val] = true;
                q.push({next_val, dist + 1});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}