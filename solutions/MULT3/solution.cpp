#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an integer N and need to find the nearest multiple of 3.
 * The distance between N and a multiple of 3 is |N - X|.
 * 
 * For any integer N:
 * 1. If N % 3 == 0, the nearest multiple is N itself.
 * 2. If N % 3 == 1, the multiples are (N-1) and (N+2).
 *    Distance to (N-1) is 1. Distance to (N+2) is 2.
 *    So, N-1 is the nearest.
 * 3. If N % 3 == 2, the multiples are (N-2) and (N+1).
 *    Distance to (N-2) is 2. Distance to (N+1) is 1.
 *    So, N+1 is the nearest.
 * 
 * Note: The problem states N is a positive integer (1 <= N <= 10).
 * The logic above holds for all integers.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    long long remainder = n % 3;

    if (remainder == 0) {
        cout << n << "\n";
    } else if (remainder == 1) {
        cout << (n - 1) << "\n";
    } else {
        // remainder == 2
        cout << (n + 1) << "\n";
    }

    return 0;
}