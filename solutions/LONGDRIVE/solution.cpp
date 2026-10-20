#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial distance covered in 10 hours = 10 * X.
 * Let 'n' be the number of additional hours.
 * Let 'v' be the speed in each of those 'n' hours (max 100 km/h).
 * Total distance = 10 * X + n * v
 * Total time = 10 + n
 * Average speed = (10 * X + n * v) / (10 + n)
 * We want Average speed >= Y.
 * (10 * X + n * v) / (10 + n) >= Y
 * 10 * X + n * v >= Y * (10 + n)
 * 10 * X + n * v >= 10 * Y + n * Y
 * n * (v - Y) >= 10 * (Y - X)
 * 
 * To minimize 'n', we should maximize 'v'. The maximum speed is 100 km/h.
 * n * (100 - Y) >= 10 * (Y - X)
 * n >= (10 * (Y - X)) / (100 - Y)
 * 
 * Since 'n' must be an integer, n = ceil( (10 * (Y - X)) / (100 - Y) ).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long X, Y;
        cin >> X >> Y;

        // We need to find the smallest integer n such that:
        // n * (100 - Y) >= 10 * (Y - X)
        // Let numerator = 10 * (Y - X)
        // Let denominator = 100 - Y
        // n = ceil(numerator / denominator)
        // Using integer arithmetic, ceil(a / b) = (a + b - 1) / b
        
        long long numerator = 10 * (Y - X);
        long long denominator = 100 - Y;
        
        long long n = (numerator + denominator - 1) / denominator;
        
        cout << n << "\n";
    }

    return 0;
}