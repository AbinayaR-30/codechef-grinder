# [Maximum Ones (MXON)](https://www.codechef.com/problems/MXON)

- **Difficulty Rating**: 943
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$ and an integer $K$, we are allowed to perform at most $K$ operations. In one operation, we can choose an index $i$ ($0 \le i < N-1$) and update $S[i] = \max(S[i], S[i+1])$. The goal is to maximize the total number of '1's in the string after performing at most $K$ operations.

## Intuition & Mathematical Observation
The operation $S[i] = \max(S[i], S[i+1])$ essentially allows a '1' located at index $j$ to "propagate" to the left. Specifically, if $S[j] = '1'$, we can change $S[j-1]$ to '1' in one operation. By repeating this, a single '1' can turn all characters to its left into '1's, provided we have enough operations $K$.

Given that $N$ is very small ($N \le 10$), the total number of possible binary strings is $2^N = 1024$. This small state space allows us to use **Breadth-First Search (BFS)** to explore all reachable configurations of the string within $K$ operations. We treat each string as a node in a graph and an operation as an edge, keeping track of visited states to ensure efficiency.

## Complexity Analysis
- **Time Complexity**: $O(T \cdot 2^N \cdot N)$, where $T$ is the number of test cases. Since $N \le 10$, $2^{10} = 1024$, and for each state, we iterate through $N-1$ possible operations, the solution runs well within the time limits.
- **Space Complexity**: $O(2^N \cdot N)$ to store the `visited` set and the queue states.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation S[i] = max(S[i], S[i+1]) effectively propagates a '1' from right to left.
 * Since N is very small (N <= 10), we can use Breadth-First Search (BFS) 
 * to explore the state space (2^N = 1024).
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
        
        // If we still have operations left, try to propagate '1's to the left
        if (ops < K) {
            for (int i = 0; i < N - 1; ++i) {
                string next_s = s;
                // Only perform operation if it changes the string (S[i+1] is 1 and S[i] is 0)
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
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```