# [Maximise Adjacent Sum (MAXADJSUM)](https://www.codechef.com/problems/MAXADJSUM)

- **Difficulty Rating**: 1118
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we want to rearrange the elements to maximize the sum of adjacent elements:
$$f(A) = \sum_{i=1}^{N-1} (A_i + A_{i+1})$$
We need to find the maximum possible value of this sum after an optimal permutation of the array.

## Intuition & Mathematical Observation
Let's expand the summation formula:
$$f(A) = (A_1 + A_2) + (A_2 + A_3) + (A_3 + A_4) + \dots + (A_{N-1} + A_N)$$
Grouping the terms by their indices:
$$f(A) = A_1 + 2A_2 + 2A_3 + \dots + 2A_{N-1} + A_N$$

From this expansion, we observe that:
1. The elements at the two ends of the array ($A_1$ and $A_N$) are added exactly **once**.
2. All other $N-2$ elements are added **twice**.

To maximize the total sum, we want the largest elements to have a coefficient of 2. Conversely, we should assign the two smallest elements of the array to the positions $A_1$ and $A_N$ so that they are only counted once.

Let $S$ be the sum of all elements in the array, and let $min_1$ and $min_2$ be the two smallest elements in the array. The maximum sum is given by:
$$\text{Result} = 2 \times (\text{Sum of all elements}) - (min_1 + min_2)$$

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step required to identify the two smallest elements. The summation takes $O(N)$.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * f(A) = A_1 + 2*A_2 + 2*A_3 + ... + 2*A_{N-1} + A_N
 * 
 * To maximize this sum, we place the two smallest elements at the ends 
 * (A_1 and A_N) so they are counted only once. All other N-2 elements 
 * are counted twice.
 * 
 * Formula: 2 * (Sum of all elements) - (smallest + second_smallest)
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }
    
    // Sort to easily identify the two smallest elements
    sort(A.begin(), A.end());
    
    // Calculate result using the derived formula
    long long result = 2 * total_sum - (A[0] + A[1]);
    cout << result << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```