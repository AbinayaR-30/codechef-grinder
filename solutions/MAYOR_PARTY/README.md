# [Peaceful Party (MAYOR_PARTY)](https://www.codechef.com/problems/MAYOR_PARTY)

- **Difficulty Rating**: 898
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the populations of three regions: $P_A$, $P_B$, and $P_C$. We need to select a subset of these regions to invite to a party such that no two adjacent regions are invited simultaneously. Specifically, region $B$ is adjacent to both $A$ and $C$, while $A$ and $C$ are not adjacent to each other. We want to maximize the total number of people invited.

## Intuition & Mathematical Observation
The constraints state that $B$ cannot be invited if $A$ is invited, and $B$ cannot be invited if $C$ is invited. This leaves us with two mutually exclusive valid strategies:

1. **Invite regions $A$ and $C$**: Since $A$ and $C$ are not adjacent, they can both be invited together. The total population is $P_A + P_C$.
2. **Invite region $B$**: Since $B$ is adjacent to both $A$ and $C$, if we invite $B$, we cannot invite $A$ or $C$. The total population is $P_B$.

To maximize the total number of people, we simply compare these two options and choose the larger one:
$$\text{Result} = \max(P_A + P_C, P_B)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations and a comparison. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three regions A, B, and C with populations P_A, P_B, and P_C.
 * Conflict rules:
 * - Region B cannot be with A.
 * - Region B cannot be with C.
 * 
 * Possible valid combinations:
 * 1. Invite people from A and C (since A and C have no conflict with each other).
 *    Total = P_A + P_C
 * 2. Invite people from B only.
 *    Total = P_B
 * 
 * We want to maximize the number of people, so we take max(P_A + P_C, P_B).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long pa, pb, pc;
        cin >> pa >> pb >> pc;
        
        // Option 1: Invite A and C
        long long option1 = pa + pc;
        
        // Option 2: Invite B
        long long option2 = pb;
        
        // Output the maximum of the two valid scenarios
        cout << max(option1, option2) << "\n";
    }
    
    return 0;
}
```