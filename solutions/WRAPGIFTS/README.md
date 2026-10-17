# [Christmas Gifts (WRAPGIFTS)](https://www.codechef.com/problems/WRAPGIFTS)

- **Difficulty Rating**: 574
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has 1000 square centimeters of wrapping paper. Given the dimensions (Height $H$, Length $L$, and Width $W$) of a rectangular gift box, calculate the maximum number of such gifts that can be fully wrapped using the available paper.

## Intuition & Mathematical Observation
The surface area of a rectangular prism (box) is calculated using the formula:
$$\text{Surface Area} = 2 \times (H \times L + L \times W + W \times H)$$

Since Chef has a fixed amount of wrapping paper (1000 cm²), the number of gifts that can be wrapped is determined by dividing the total paper by the surface area of a single gift. Because we cannot wrap a partial gift, we use integer division (the floor function):
$$\text{Max Gifts} = \lfloor \frac{1000}{\text{Surface Area}} \rfloor$$

Given the constraints ($1 \le H, L, W \le 10$), the surface area will range from 6 to 600, ensuring the result is always a non-negative integer.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the dimensions and the calculated area.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The surface area of a rectangular box with dimensions H, L, and W is given by:
 * Surface Area = 2 * (H*L + L*W + W*H)
 * 
 * Chef has a total of 1000 square centimeters of wrapping paper.
 * The number of gifts that can be wrapped is the floor of (Total Area / Surface Area of one gift).
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long h, l, w;
        cin >> h >> l >> w;
        
        // Calculate surface area of one gift
        long long surface_area = 2 * (h * l + l * w + w * h);
        
        // Total available paper
        long long total_paper = 1000;
        
        // Calculate maximum number of gifts using integer division
        long long max_gifts = total_paper / surface_area;
        
        cout << max_gifts << "\n";
    }
    
    return 0;
}
```