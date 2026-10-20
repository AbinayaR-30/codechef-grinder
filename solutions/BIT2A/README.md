# [A - Books (BIT2A)](https://www.codechef.com/problems/BIT2A)

- **Difficulty Rating**: 1175
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a sorted array $A$ of $N$ integers, for each element $A[i]$, we need to determine how many elements in the array are strictly greater than $A[i]$. The output should be a sequence of these counts corresponding to each index of the original array.

## Intuition & Mathematical Observation
The problem provides a sorted array. This is a key observation because, in a sorted array, all elements strictly greater than a value $X$ will be located to the right of the last occurrence of $X$.

1. **Naive Approach**: For every element $A[i]$, iterate through the entire array and count how many elements are greater than $A[i]$. This results in an $O(N^2)$ complexity, which is perfectly fine given $N \le 100$.
2. **Optimized Approach**: Since the array is sorted, we can use binary search. Specifically, the `std::upper_bound` function in C++ returns an iterator to the first element that is strictly greater than a given value. 
3. The number of elements strictly greater than $A[i]$ is simply the number of elements from that iterator to the end of the array. This can be calculated efficiently using `std::distance`.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \log N)$, where $T$ is the number of test cases and $N$ is the size of the array. The `upper_bound` operation takes $O(\log N)$ time, and we perform this for each of the $N$ elements.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sorted list A of size N.
 * For each A[i], we need to find the count of elements strictly greater than A[i].
 * Since the array is sorted, for any element A[i], all elements strictly greater 
 * than A[i] will appear after the last occurrence of A[i] in the array.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        // Find the first element strictly greater than A[i]
        // Since A is sorted, we can use upper_bound
        auto it = upper_bound(A.begin(), A.end(), A[i]);
        
        // The number of elements strictly greater is the distance from 
        // the iterator to the end of the vector
        long long count = distance(it, A.end());
        
        cout << count << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
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
```