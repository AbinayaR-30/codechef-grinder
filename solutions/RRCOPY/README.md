# [Copy-Paste (RRCOPY)](https://www.codechef.com/problems/RRCOPY)

- **Difficulty Rating**: 1280
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we want to find the minimum size of an initial array such that we can obtain $A$ by repeatedly performing the "Copy-Paste" operation. A "Copy-Paste" operation allows us to select any contiguous subsequence of the current array and insert it anywhere in the array.

## Intuition & Mathematical Observation
The core of the problem lies in understanding what the "Copy-Paste" operation allows us to do. If we have an initial array containing all the distinct elements present in $A$, we can construct $A$ by copying and pasting these elements into their required positions. 

For example, if $A = [1, 2, 3, 1, 2]$, the distinct elements are $\{1, 2, 3\}$. We can start with the array $[1, 2, 3]$ and then copy the subsequence $[1, 2]$ and paste it at the end to achieve the target array. 

Because we can copy any contiguous subsequence, we can effectively "build" the array by starting with a set of unique elements and duplicating them as needed. Therefore, the minimum size of the initial array is simply the **count of distinct elements** in the given array $A$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ on average using an `unordered_set` (or $O(N \log N)$ if using a standard `std::set`). Given the constraints, this is well within the time limits.
- **Space Complexity**: $O(N)$ to store the distinct elements in the set.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The "Copy-Paste" operation allows us to take any contiguous subsequence and 
 * insert it anywhere. This means if we have a set of unique elements present 
 * in the final array A, we can always start with an initial array containing 
 * exactly those unique elements in any order. 
 * 
 * Thus, the minimal size of the initial array is simply the number of 
 * distinct elements in the given array A.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    // Using an unordered_set to count distinct elements efficiently.
    // Time Complexity: O(N) average case.
    unordered_set<int> distinct_elements;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        distinct_elements.insert(val);
    }
    
    // The answer is the number of unique elements found.
    cout << distinct_elements.size() << "\n";
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```