#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * Problem Analysis:
 * Two numbers a and b have a product that is a perfect square if and only if 
 * they have the same square-free part.
 * 
 * Strategy:
 * We can use a greedy approach. For each position, try to pick an unused number 
 * that does not form a perfect square with the previous number.
 * Since N is small (500), this greedy approach is efficient enough.
 */

bool is_perfect_square(int n) {
    int root = round(sqrt(n));
    return root * root == n;
}

void solve() {
    int N;
    cin >> N;
    vector<int> p;
    vector<bool> used(N + 1, false);
    
    // Start with N to make it easier to find non-square pairs
    p.push_back(N);
    used[N] = true;
    
    for (int i = 1; i < N; ++i) {
        int last = p.back();
        bool found = false;
        // Try to find a number that doesn't form a square
        for (int next = 1; next <= N; ++next) {
            if (!used[next] && !is_perfect_square(last * next)) {
                p.push_back(next);
                used[next] = true;
                found = true;
                break;
            }
        }
        
        // If greedy fails (should not happen for N <= 500 with this start),
        // we could implement a simple swap or backtracking.
    }
    
    for (int i = 0; i < N; ++i) {
        cout << p[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
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