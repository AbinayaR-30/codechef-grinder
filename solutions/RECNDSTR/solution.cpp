#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be a string of length n.
 * L(V) = S means V[1...n-1] + V[0] = S[0...n-1].
 * This implies V[i] = S[(i+1)%n].
 * R(V) = S means V[n-1] + V[0...n-2] = S[0...n-1].
 * This implies V[i] = S[(i-1+n)%n].
 * 
 * For a valid V to exist, the left shift of S and the right shift of S must be equal.
 * Let's verify:
 * If L(V) = S, then V = R(S).
 * If R(V) = S, then V = L(S).
 * Therefore, we must have R(S) = L(S).
 * 
 * Let's check the condition R(S) == L(S):
 * L(S) = S[1...n-1] + S[0]
 * R(S) = S[n-1] + S[0...n-2]
 * 
 * If |S| <= 2, the condition is always satisfied.
 * For |S| > 2, we simply construct L(S) and R(S) and compare them.
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    if (n <= 2) {
        cout << "YES" << "\n";
        return;
    }
    
    // Construct L(S)
    string left_shifted = s.substr(1) + s[0];
    
    // Construct R(S)
    string right_shifted = s[n - 1] + s.substr(0, n - 1);
    
    if (left_shifted == right_shifted) {
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