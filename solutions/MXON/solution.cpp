#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation S[i] = max(S[i], S[i+1]) effectively propagates a '1' from right to left.
 * If we have a '1' at index j, we can move this '1' to any index i < j using (j - i) operations.
 * Specifically, if we have a '1' at index j, we can make all indices from i to j equal to '1'
 * using (j - i) operations.
 * 
 * Since N is very small (N <= 10), we can use Breadth-First Search (BFS) or simply 
 * observe that the state space is small (2^N = 1024).
 * 
 * For each test case:
 * 1. Start with the initial string S.
 * 2. Use a queue to perform BFS where each state is the string S and the number of operations used.
 * 3. Keep track of visited states to avoid redundant work.
 * 4. For each state, try all possible operations (i from 0 to N-2).
 * 5. Track the maximum number of '1's encountered.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // BFS to find the maximum number of 1s
    queue<pair<string, int>> q;
    q.push({S, 0});
    
    set<string> visited;
    visited.insert(S);
    
    int max_ones = 0;
    for (char c : S) if (c == '1') max_ones++;
    
    while (!q.empty()) {
        pair<string, int> curr = q.front();
        q.pop();
        
        string s = curr.first;
        int ops = curr.second;
        
        int current_ones = 0;
        for (char c : s) if (c == '1') current_ones++;
        max_ones = max(max_ones, current_ones);
        
        if (ops < K) {
            for (int i = 0; i < N - 1; ++i) {
                string next_s = s;
                if (next_s[i+1] == '1' && next_s[i] == '0') {
                    next_s[i] = '1';
                    if (visited.find(next_s) == visited.end()) {
                        visited.insert(next_s);
                        q.push({next_s, ops + 1});
                    }
                }
            }
        }
    }
    
    cout << max_ones << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}