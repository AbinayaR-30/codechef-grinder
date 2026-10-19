#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X strings of "01" and Y strings of "10".
 * Let's denote "01" as A and "10" as B.
 * Each A contributes 1 to f(S) internally (0->1).
 * Each B contributes 1 to f(S) internally (1->0).
 * Total internal transitions = X + Y.
 * 
 * When we concatenate two strings, we might add an extra transition:
 * - A + A: "01" + "01" -> "0101". The boundary is '1' and '0', which is a transition.
 * - B + B: "10" + "10" -> "1010". The boundary is '0' and '1', which is a transition.
 * - A + B: "01" + "10" -> "0110". The boundary is '1' and '1', no transition.
 * - B + A: "10" + "01" -> "1001". The boundary is '0' and '0', no transition.
 * 
 * To minimize f(S), we want to maximize the number of A+B or B+A adjacencies.
 * We have X strings of type A and Y strings of type B.
 * We can alternate them: A, B, A, B...
 * If |X - Y| <= 1, we can arrange them such that every pair is an A-B or B-A transition.
 * In this case, there are X+Y-1 boundaries, and all are "no transition" boundaries.
 * Total f(S) = X + Y.
 * 
 * If |X - Y| > 1, say X > Y + 1, we must place some A's next to each other.
 * Each time we place an A next to an A, we add 1 to f(S).
 * We have Y strings of B, which can act as separators for A's.
 * We can form Y+1 groups of A's using B's as separators: A...A B A...A B ... B A...A.
 * The number of extra transitions created by A-A adjacencies is (X - (Y + 1)).
 * Total f(S) = (X + Y) + (X - Y - 1) = 2X - 1.
 * Similarly, if Y > X + 1, f(S) = 2Y - 1.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    if (abs(X - Y) <= 1) {
        cout << X + Y << "\n";
    } else if (X > Y) {
        cout << 2 * X - 1 << "\n";
    } else {
        cout << 2 * Y - 1 << "\n";
    }
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