#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N and need to find the smallest X > N such that
 * parity(digitSum(N)) != parity(digitSum(X)).
 * 
 * Since N < 10^9, the digit sum is at most 9*9 = 81.
 * The parity of the digit sum changes very frequently as we increment N.
 * In fact, for any N, checking N+1, N+2, ... will find the required X 
 * very quickly (usually within a few increments).
 * 
 * Time Complexity: O(T * K * D) where T is test cases, K is the number of 
 * increments (very small), and D is the number of digits (log10(N)).
 * This is well within the 1s time limit.
 */

int getDigitSum(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

void solve() {
    long long n;
    cin >> n;
    
    int targetParity = getDigitSum(n) % 2;
    long long x = n + 1;
    
    while (true) {
        if (getDigitSum(x) % 2 != targetParity) {
            cout << x << "\n";
            break;
        }
        x++;
    }
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