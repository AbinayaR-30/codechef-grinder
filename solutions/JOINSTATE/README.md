# [Join States (JOINSTATE)](https://www.codechef.com/problems/JOINSTATE)

- **Difficulty Rating**: 1043
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an array $A$ of $N$ integers and a threshold value $M$. We need to partition the array into the maximum number of contiguous subarrays such that the sum of each subarray is at least $M$. Any elements remaining at the end that do not form a sum of at least $M$ are discarded (or effectively merged into the last valid subarray).

## Intuition & Mathematical Observation
To maximize the number of subarrays, we should use a **Greedy Approach**. 

1. We iterate through the array while maintaining a `current_sum` of the elements in the current segment.
2. As soon as `current_sum` reaches or exceeds $M$, we have successfully formed a valid state. We increment our `state_count` and reset `current_sum` to $0$ to begin forming the next state.
3. By "closing" the state as soon as the condition is met, we ensure that we leave as many elements as possible for subsequent states, thereby maximizing the total count.
4. If we reach the end of the array and the final `current_sum` is less than $M$, those elements cannot form an additional valid state and are ignored, which is consistent with the problem requirements.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We perform a single pass through the array.
- **Space Complexity**: $O(N)$ to store the input array. This can be optimized to $O(1)$ if we process the input elements one by one without storing them in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N. We want to partition the array into the 
 * maximum number of contiguous subarrays such that the sum of each subarray 
 * is at least M.
 * 
 * Greedy Strategy:
 * Iterate through the array and maintain a running sum of the current segment.
 * As soon as the running sum reaches or exceeds M, we count this as a valid 
 * state and reset the running sum to 0 to start forming the next state.
 */

void solve() {
    int N;
    long long M;
    cin >> N >> M;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int state_count = 0;
    long long current_sum = 0;
    
    for (int i = 0; i < N; ++i) {
        current_sum += A[i];
        // As soon as the condition is met, count the state and reset
        if (current_sum >= M) {
            state_count++;
            current_sum = 0;
        }
    }
    
    cout << state_count << "\n";
}

int main() {
    // Fast I/O for performance
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