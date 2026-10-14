#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let A, B, C be the amounts of money the three friends have.
 * The statements are:
 * A - B = x
 * B - C = y
 * C - A = z
 * 
 * Summing these equations:
 * (A - B) + (B - C) + (C - A) = x + y + z
 * 0 = x + y + z
 * 
 * Since we are given X = |x|, Y = |y|, Z = |z|, the condition x + y + z = 0
 * can be rewritten by considering all possible signs for x, y, and z.
 * Specifically, the condition is satisfied if there exist s1, s2, s3 in {-1, 1}
 * such that s1*X + s2*Y + s3*Z = 0.
 * 
 * This is equivalent to:
 * X + Y = Z
 * X + Z = Y
 * Y + Z = X
 * Or, more generally, one of the values must be the sum of the other two, 
 * or the difference of the other two.
 * 
 * Actually, the condition s1*X + s2*Y + s3*Z = 0 can be simplified:
 * If we fix the sign of one variable (say x is positive), then:
 * X = y + z
 * X = y - z
 * X = -y + z
 * X = -y - z
 * 
 * This covers all cases where the sum of two equals the third or the sum of 
 * all three is zero with appropriate signs.
 */

void solve() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    // Possible combinations of signs for x, y, z:
    // x + y + z = 0
    // x + y - z = 0 => x + y = z
    // x - y + z = 0 => x + z = y
    // -x + y + z = 0 => y + z = x
    // x - y - z = 0 => x = y + z
    // -x + y - z = 0 => y = x + z
    // -x - y + z = 0 => z = x + y
    
    // Essentially, the condition is satisfied if:
    // X + Y == Z OR X + Z == Y OR Y + Z == X OR X == Y + Z (redundant)
    // Or if one can be formed by adding/subtracting the others.
    // The simplest check is:
    // Is there any combination of signs such that s1*X + s2*Y + s3*Z = 0?
    
    if ((X + Y == Z) || (X + Z == Y) || (Y + Z == X) || (X + Y + Z == 0)) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
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