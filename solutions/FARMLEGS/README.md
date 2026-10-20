# [Legs on a Farm (FARMLEGS)](https://www.codechef.com/problems/FARMLEGS)

- **Difficulty Rating**: 709
- **Solved in**: 3 attempt(s)

## Problem Summary
Given a total number of legs $N$ on a farm, where cows have 4 legs and chickens have 2 legs, find the **minimum** number of animals required to account for exactly $N$ legs.

## Intuition & Mathematical Observation
To minimize the total number of animals ($A = C + H$), we want to prioritize the animal that contributes the most legs per individual. Since a cow has 4 legs and a chicken has 2, replacing two chickens (4 legs total) with one cow (4 legs total) reduces the total animal count by one. 

Therefore, to minimize the total count, we should maximize the number of cows:
1. **Maximize Cows**: Calculate the maximum number of cows possible by dividing $N$ by 4 ($C = N / 4$).
2. **Handle Remainder**: If there are remaining legs ($N \% 4$), they must be covered by chickens. Since the remainder can only be 0 or 2, we divide the remainder by 2 to get the number of chickens ($H = (N \% 4) / 2$).
3. **Result**: The minimum number of animals is simply $C + H$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and results.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We want to minimize A = C + H subject to 4C + 2H = N.
 * Since each cow (4 legs) contributes more to the leg count than a chicken (2 legs),
 * we maximize the number of cows to minimize the total number of animals.
 * 
 * C_max = N / 4
 * Remaining legs = N % 4
 * H = (N % 4) / 2
 * Total = C_max + H
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        // Maximize cows to minimize total animals
        int cows = n / 4;
        
        // Remaining legs must be covered by chickens
        int remaining_legs = n % 4;
        int chickens = remaining_legs / 2;
        
        // Output the minimum number of animals
        cout << (cows + chickens) << "\n";
    }
    
    return 0;
}
```