#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: ODDEVEN7
 * Approach:
 * Count the number of odd and even integers in the array.
 * Let O be the count of odd numbers and E be the count of even numbers.
 * We can form an alternating sequence by taking pairs of (odd, even).
 * The maximum length is 2 * min(O, E) + (1 if O != E else 0).
 * 
 * Time Complexity: O(N) per test case
 * Space Complexity: O(1) auxiliary space
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    int odd_count = 0;
    int even_count = 0;
    
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }
    
    int result;
    if (odd_count == even_count) {
        result = odd_count + even_count;
    } else {
        result = 2 * min(odd_count, even_count) + 1;
    }
    
    cout << result << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}