#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two strings A and B of length N, consisting only of 'a' and 'b'.
 * We can shuffle A and B independently. We want to know if we can arrange them
 * such that A[i] != B[i] for all i.
 * 
 * Let countA_a, countA_b be the counts of 'a' and 'b' in A.
 * Let countB_a, countB_b be the counts of 'a' and 'b' in B.
 * 
 * To satisfy A[i] != B[i], at every index i:
 * - If A[i] = 'a', then B[i] must be 'b'.
 * - If A[i] = 'b', then B[i] must be 'a'.
 * 
 * This implies that for every 'a' in A, we must have a corresponding 'b' in B.
 * And for every 'b' in A, we must have a corresponding 'a' in B.
 * 
 * Therefore, the number of 'a's in A must equal the number of 'b's in B,
 * and the number of 'b's in A must equal the number of 'a's in B.
 * 
 * Let countA_a = x, countA_b = N - x.
 * Let countB_a = y, countB_b = N - y.
 * 
 * The condition A[i] != B[i] for all i is possible if and only if:
 * x = N - y  => x + y = N
 * (N - x) = y => N = x + y
 * 
 * Wait, is that sufficient?
 * If x + y = N, then:
 * Number of 'a's in A = x
 * Number of 'b's in B = N - y = x
 * Number of 'b's in A = N - x = y
 * Number of 'a's in B = y
 * 
 * If we have x 'a's in A and y 'a's in B, and x + y = N:
 * We can place all 'a's of A at indices where B has 'b's.
 * Since there are exactly x 'b's in B, and we have x 'a's in A, we can match them.
 * The remaining N - x positions in A are 'b's, and the remaining N - x positions in B are 'a's.
 * This perfectly satisfies the condition.
 * 
 * So the condition is simply: countA_a + countB_a == N.
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    int countA_a = 0;
    for (char c : A) if (c == 'a') countA_a++;

    int countB_a = 0;
    for (char c : B) if (c == 'a') countB_a++;

    if (countA_a + countB_a == N) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}