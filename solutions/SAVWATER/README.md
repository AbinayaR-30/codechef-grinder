# [A - Save Water Save Life (SAVWATER)](https://www.codechef.com/problems/SAVWATER)

- **Difficulty Rating**: 918
- **Solved in**: 2 attempt(s)

## Problem Summary
We are given $H$ households. Each household consumes $x$ liters of freshwater and $y$ liters of greywater. The greywater consumption is reduced by half (using floor division), meaning the effective greywater usage is $\lfloor y/2 \rfloor$. We need to determine if the total water consumption of all $H$ households is less than or equal to the total capacity $C$.

## Intuition & Mathematical Observation
1. **Consumption per Household**: For a single household, the total water used is the sum of the mandatory freshwater and the reduced greywater:
   $$\text{Usage}_{\text{single}} = x + \lfloor y/2 \rfloor$$
2. **Total Consumption**: Since there are $H$ households, the total water required is:
   $$\text{Usage}_{\text{total}} = H \times (x + \lfloor y/2 \rfloor)$$
3. **Condition**: We simply compare $\text{Usage}_{\text{total}}$ with $C$. If $\text{Usage}_{\text{total}} \le C$, output "YES"; otherwise, output "NO".
4. **Implementation Note**: In C++, integer division `y / 2` automatically performs the floor operation, which simplifies the calculation.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the inputs and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Each household consumes 'x' liters of mandatory freshwater.
 * Each household consumes 'y' liters of greywater, which is reduced to floor(y/2).
 * Total consumption per household = x + (y / 2).
 * Total consumption for H households = H * (x + (y / 2)).
 * We need to check if this total consumption <= C.
 * 
 * Constraints:
 * H, x, y <= 10, C <= 100.
 * The logic uses integer division (y / 2), which correctly implements floor(y/2).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int H, x, y, C;
        cin >> H >> x >> y >> C;
        
        // Calculate consumption per household
        // Integer division y/2 automatically performs floor(y/2)
        int consumption_per_household = x + (y / 2);
        
        // Calculate total consumption for all households
        int total_consumption = H * consumption_per_household;
        
        // Check if total consumption is within the available capacity C
        if (total_consumption <= C) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```