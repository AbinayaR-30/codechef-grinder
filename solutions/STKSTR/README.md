# [Streak Star (STKSTR)](https://www.codechef.com/problems/STKSTR)

- **Difficulty Rating**: 1129
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers and a multiplier $X$, you are allowed to perform at most one operation: choose an index $i$ and replace $A[i]$ with $A[i] \times X$. The goal is to find the maximum possible length of a non-decreasing subarray after performing the operation at most once.

## Intuition & Mathematical Observation
The problem asks us to maximize the length of a non-decreasing subarray. Since the constraints on $N$ are relatively small (the sum of $N$ over test cases is $\le 1000$), we can afford an $O(N^2)$ approach.

1. **Brute Force Strategy**: We can iterate through every possible index $i$ from $0$ to $N-1$. For each index, we temporarily multiply $A[i]$ by $X$, calculate the length of the longest non-decreasing subarray, and then revert the change (backtracking).
2. **Base Case**: We must also consider the case where we perform no operations (or the operation doesn't improve the result), which is covered by calculating the streak on the original array.
3. **Streak Calculation**: A simple linear scan $O(N)$ can determine the longest non-decreasing subarray by keeping track of the current streak and updating the global maximum whenever the non-decreasing condition ($A[i] \ge A[i-1]$) is broken.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$. We iterate through $N$ possible modifications, and for each modification, we perform an $O(N)$ scan to find the longest streak. Given $\sum N \le 1000$, this is well within the time limits.
- **Space Complexity**: $O(N)$ to store the array $A$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of length N and a multiplier X.
 * We can modify at most one element A[i] to A[i] * X.
 * We want to maximize the length of the longest non-decreasing subarray.
 * 
 * Since N is small (sum of N <= 1000), we can iterate through every possible 
 * index i (0 to N-1) where we apply the operation A[i] = A[i] * X.
 * For each modification, we calculate the streak value in O(N) time.
 * Total complexity: O(N^2), which is well within the limits for N=1000.
 */

int get_streak(const vector<long long>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    int max_streak = 1;
    int current_streak = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] >= arr[i - 1]) {
            current_streak++;
        } else {
            max_streak = max(max_streak, current_streak);
            current_streak = 1;
        }
    }
    max_streak = max(max_streak, current_streak);
    return max_streak;
}

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Case 1: No operation performed
    int max_val = get_streak(A);

    // Case 2: Try modifying each index i
    for (int i = 0; i < N; ++i) {
        long long original = A[i];
        A[i] *= X;
        max_val = max(max_val, get_streak(A));
        A[i] = original; // Backtrack
    }

    cout << max_val << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```