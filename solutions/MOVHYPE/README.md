# [Movie Hype (MOVHYPE)](https://www.codechef.com/problems/MOVHYPE)

- **Difficulty Rating**: 921
- **Solved in**: 2 attempt(s)

## Problem Summary
In a theater with $2N+1$ seats, the odd-numbered seats ($1, 3, 5, \dots, 2N+1$) are occupied by people with specific "hype" levels $A_1, A_2, \dots, A_{N+1}$. The even-numbered seats ($2, 4, \dots, 2N$) are empty. The "loudness" of an empty seat is defined as the maximum hype level of the two people sitting immediately adjacent to it. We need to find the minimum possible loudness among all empty seats.

## Intuition & Mathematical Observation
- The problem states that there are $N+1$ people at positions $1, 3, \dots, 2N+1$.
- An empty seat at position $2k$ (where $1 \le k \le N$) is located between the person at position $2k-1$ (hype $A_k$) and the person at position $2k+1$ (hype $A_{k+1}$).
- Therefore, the loudness of the $k$-th empty seat is $\max(A_k, A_{k+1})$.
- To find the minimum loudness, we simply need to iterate through all adjacent pairs in the given array $A$ of size $N+1$, calculate the maximum of each pair, and track the minimum value found across all pairs.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of empty seats. We perform a single pass through the array of $N+1$ hype levels to compare adjacent elements.
- **Space Complexity**: $O(N)$ to store the hype levels in a vector. This could be optimized to $O(1)$ by storing only the previous element while reading the input, but $O(N)$ is well within limits for the given constraints.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * The theater has 2N+1 seats.
 * Occupied seats are 1, 3, 5, ..., 2N+1.
 * Empty seats are 2, 4, 6, ..., 2N.
 * 
 * The hype levels are given as A_1, A_2, ..., A_{N+1}.
 * Seat 2 is between A_1 and A_2. Loudness = max(A_1, A_2).
 * Seat 2k is between A_k and A_{k+1}. Loudness = max(A_k, A_{k+1}).
 * 
 * We need to find min(max(A_k, A_{k+1})) for k = 1 to N.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<int> A(N + 1);
    for (int i = 0; i <= N; ++i) {
        cin >> A[i];
    }
    
    // Initialize min_loudness with a value larger than any possible A_i
    int min_loudness = 1000000; 
    
    // There are N empty seats. 
    // The i-th empty seat (0-indexed loop) is between A[i] and A[i+1]
    for (int i = 0; i < N; ++i) {
        int current_loudness = max(A[i], A[i + 1]);
        if (current_loudness < min_loudness) {
            min_loudness = current_loudness;
        }
    }
    
    cout << min_loudness << "\n";
}

int main() {
    // Optimize I/O operations
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