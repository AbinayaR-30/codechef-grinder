#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let x = min(A, B), y = min(B, C), z = min(C, A).
 * Without loss of generality, assume A <= B <= C.
 * Then:
 * min(A, B) = A = x
 * min(B, C) = B = y
 * min(C, A) = A = z
 * This implies x = z.
 * 
 * If we sort the three given values as s1 <= s2 <= s3:
 * 1. If all three are equal (s1 = s2 = s3), then A=B=C=s1 works. (YES)
 * 2. If two are equal and the third is larger (s1 = s2 < s3), 
 *    let A = s3, B = s1, C = s1.
 *    min(A, B) = min(s3, s1) = s1
 *    min(B, C) = min(s1, s1) = s1
 *    min(C, A) = min(s1, s3) = s1
 *    This results in (s1, s1, s1), which doesn't match (s1, s1, s3).
 *    Wait, let's re-evaluate:
 *    If we have values x, y, z.
 *    If two are equal and the third is larger, say x = y < z:
 *    We need min(A, B) = x, min(B, C) = x, min(C, A) = z.
 *    This is impossible because min(C, A) = z implies A >= z and C >= z.
 *    If A >= z and C >= z, then min(A, B) = x implies B = x (since x < z).
 *    Then min(B, C) = min(x, C) = x. This works!
 *    Example: x=2, y=2, z=4. A=4, B=2, C=4.
 *    min(4, 2) = 2, min(2, 4) = 2, min(4, 4) = 4. Matches!
 * 3. If all three are distinct, it is impossible because the two smallest values 
 *    must be equal to the smallest element of the set {A, B, C}.
 * 
 * Conclusion:
 * A valid tuple exists if and only if the two smallest values are equal.
 * Or simply: sort the three values, check if s1 == s2.
 */

void solve() {
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    
    // After sorting, v[0] <= v[1] <= v[2].
    // A valid tuple exists if and only if v[0] == v[1].
    if (v[0] == v[1]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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