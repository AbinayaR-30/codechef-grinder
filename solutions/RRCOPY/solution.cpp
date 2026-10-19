#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The "Copy-Paste" operation allows us to take any contiguous subsequence and 
 * insert it anywhere. This means if we have a set of unique elements present 
 * in the final array A, we can always start with an initial array containing 
 * exactly those unique elements in any order. 
 * 
 * For example, if A = [1, 2, 3, 1, 2], the unique elements are {1, 2, 3}.
 * We can start with [1, 2, 3] and copy [1, 2] to the end to get [1, 2, 3, 1, 2].
 * 
 * Thus, the minimal size of the initial array is simply the number of 
 * distinct elements in the given array A.
 * 
 * Time Complexity: O(N log N) or O(N) depending on the set implementation.
 * Space Complexity: O(N) to store the unique elements.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    // Using a set to count distinct elements
    // Since Ai <= 10^5, we can also use a boolean array or a frequency array
    // for O(N) time complexity.
    unordered_set<int> distinct_elements;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        distinct_elements.insert(val);
    }
    
    cout << distinct_elements.size() << "\n";
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