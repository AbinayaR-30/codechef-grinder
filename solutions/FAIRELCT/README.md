# [Fair Elections (FAIRELCT)](https://www.codechef.com/problems/FAIRELCT)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
John Jackson and Jack Johnson are competing in an election. John has $N$ packs of votes, and Jack has $M$ packs of votes. John wants to win the election, meaning he needs the sum of his votes to be strictly greater than the sum of Jack's votes. We are allowed to swap any pack of votes from John with any pack of votes from Jack. The goal is to find the minimum number of swaps required to make John win, or determine if it is impossible.

## Intuition & Mathematical Observation
To make John win with the minimum number of swaps, we need to increase John's total sum as efficiently as possible. 
1. **Greedy Strategy**: At each step, we should swap the smallest pack of votes from John with the largest pack of votes from Jack. This provides the maximum possible increase to John's total sum for a single swap.
2. **Sorting**: By sorting John's votes in ascending order and Jack's votes in descending order, we can easily access the "smallest" and "largest" elements using a single index pointer.
3. **Termination**: 
   - If John's sum is already greater than Jack's, the answer is 0.
   - If at any point the smallest available pack from John is greater than or equal to the largest available pack from Jack, no further swaps will increase John's total sum, so we stop.
   - If we exhaust all possible swaps (up to the minimum of $N$ and $M$) and John still does not have a majority, it is impossible to win.

## Complexity Analysis
- **Time Complexity**: $O(T \cdot (N \log N + M \log M))$, where $T$ is the number of test cases. The sorting step dominates the complexity, while the iteration takes $O(\min(N, M))$.
- **Space Complexity**: $O(N + M)$ to store the vote packs for both candidates.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * John Jackson (A) wants to have strictly more votes than Jack Johnson (B).
 * We want to minimize the number of swaps.
 * To maximize John's total votes while minimizing swaps, we should always swap
 * the smallest pack from A with the largest pack from B.
 */

void solve() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N), B(M);
    long long sumA = 0, sumB = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sumA += A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
        sumB += B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<long long>());

    int swaps = 0;
    int limit = min(N, M);
    
    // Check if already winning
    if (sumA > sumB) {
        cout << 0 << "\n";
        return;
    }

    for (int i = 0; i < limit; ++i) {
        // Swap smallest A with largest B
        if (A[i] < B[i]) {
            sumA = sumA - A[i] + B[i];
            sumB = sumB - B[i] + A[i];
            swaps++;
            
            if (sumA > sumB) {
                cout << swaps << "\n";
                return;
            }
        } else {
            // Since A is sorted ascending and B descending, 
            // if A[i] >= B[i], no further swaps will help.
            break;
        }
    }

    cout << -1 << "\n";
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